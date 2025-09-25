# 🤖 PROS Project Overview

This project is organized so that different robot functions are split into clear files.  
It keeps the code modular, easy to debug, and easy to expand.

---

# 📂 File Overview

| File              | Purpose                                                                 |
|-------------------|-------------------------------------------------------------------------|
| main.cpp      | 🚗 Drive code (driver control loop) and 🤖 autonomous routines.         |
| robot.cpp     | ⚙️ Robot initialization (motors, sensors, subsystems).                  |
| vex.h         | 📦 Default VEX header file (includes API).                              |
| robot.h       | 🛠️ Declarations for robot-wide objects (motors, sensors, subsystems).   |

---

# 🔄 Code Flow

1. Initialization → `robot.cpp` sets up all devices.  
2. Competition start → `main.cpp` chooses mode:  
   - Autonomous → runs the selected routine.  
   - Driver Control → runs drive code and listens to controller input.  
3. Helper files → support subsystems and features like odometry and displays.  

---

# 🎯 Why This Structure?

- Keeps drive logic, robot setup, and subsystems separated.  
- Makes the project easier to maintain and team-friendly.  
- Lets you quickly add new features without breaking old ones.  
