#include "main.h"
#include "robot.h"

using namespace std;
using namespace pros;

bool tongue_activated = true;

void driveVolts(int lspeed, int rspeed, int wt)
{
	// convert percent to mV (approx)
	int l_mV = int(lspeed / 127.0);
	int r_mV = int(rspeed / 127.0);

	left_motor_front.move_voltage(l_mV);
	left_motor_middle.move_voltage(l_mV);
	left_motor_back.move_voltage(l_mV);
	right_motor_front.move_voltage(r_mV);
	right_motor_middle.move_voltage(r_mV);
	right_motor_back.move_voltage(r_mV);

	delay(wt);
}

void driveBrake()
{
	left_motor_front.brake();
	left_motor_middle.brake();
	left_motor_back.brake();
	right_motor_front.brake();
	right_motor_middle.brake();
	right_motor_back.brake();
}

void intakeInit(int vel)
{
	intake1.move(vel);
	intake2.move(vel);
	tongue_activated = false;
}

void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		lcd::set_text(2, "I was pressed!");
	}
	else
	{
		lcd::clear_line(2);
	}
}

void screenTask(void *)
{
	while (true)
	{
		// keep screens running in their own task so competition_initialize can return

		delay(50);
	}
}

void initialize()
{
	lcd::initialize();
	lcd::set_text(1, "There once was a knee. It grew every day.");

	lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize()
{
	// spawn the screen updater but don't block returning from competition_initialize
	Task screenUpdater(screenTask, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "screenUpdater");
	// give the task a moment
	delay(50);
}

void autonomous()
{
}

void opcontrol()
{
	while (true)
	{
		// if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT))
		// {
		// 	step_1_complete = true;
		// }
		// if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN) && step_1_complete)
		// {
		// 	activated = true;
		// }
		// if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT))
		// {
		// 	activated =
		// 	// step_1_complete = false;
		// }
		//!!
		// Motor Controls
		if (tongue_activated)
		{
			if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN))
			{
				tankToggle = !tankToggle;
			}

			if (tankToggle)
			{
				// read axes as doubles in range [-127,127]
				double dLeftRaw = controller.get_analog(ANALOG_LEFT_Y);
				double dRightRaw = controller.get_analog(ANALOG_RIGHT_Y);

				// cubic-ish deadband shaping but preserve sign: ((|x|*x)/127)
				double leftScaled = (fabs(dLeftRaw) * dLeftRaw) / 127.0;
				double rightScaled = (fabs(dRightRaw) * dRightRaw) / 127.0;

				// convert to integer percent in [-127..127]
				int leftPercent = int(round(leftScaled * 127.0));
				int rightPercent = int(round(rightScaled * 127.0));

				driveVolts(leftPercent, rightPercent, 0); // driveVolts now expects percent
			}
			else
			{

				int power = controller.get_analog(ANALOG_LEFT_Y); // [-127..127]
				int RX = controller.get_analog(ANALOG_RIGHT_X);	  // [-127..127]

				// cubic turn shaping (faster than pow)
				// int turn = (RX * RX * RX) / (127 * 127);
				int turn = (RX * RX * RX * abs(RX)) / (127 * 127 * 127);
				int forward = (power * power * power) / (127 * 127);

				int left = forward + turn;
				int right = forward - turn;

				// clamp to [-127..127]
				if (left > 127)
					left = 127;
				if (left < -127)
					left = -127;
				if (right > 127)
					right = 127;
				if (right < -127)
					right = -127;

				driveVolts(left, right, 0);
			}
			//!

			if (controller.get_digital(E_CONTROLLER_DIGITAL_R1))
			{
				intakeInit(127);
			}

			else if (controller.get_digital(E_CONTROLLER_DIGITAL_R2))
			{
				intakeInit(-127);
			}
			else
			{
				intakeInit(0);
			}

			if (controller.get_digital(E_CONTROLLER_DIGITAL_L1))
			{
				intake2.move(127);
			}

			else if (controller.get_digital(E_CONTROLLER_DIGITAL_L2))
			{
				intake2.move(-127);
			}
			else
			{
				intake2.move(0);
			}

			// Pneumatics
			if (controller.get_digital_new_press(E_CONTROLLER_DIGITAL_B))
			{
				lickerMechToggle = !lickerMechToggle;
				lickerMech.set_value(lickerMechToggle);
			}

			// Important: yield CPU
			delay(10);
			//!
		}
		else
		{
		}
	}
}
