# Smart Home System using AVR Microcontrollers

## Project Overview
This project is a **Smart Home System** developed as our final project at the Information Technology Institute (ITI). The system leverages AVR microcontrollers to provide secure and efficient control over home appliances, including lights and fans. The system features both manual and automatic control options for enhanced user flexibility.Here is the project demo: <a href="https://drive.google.com/file/d/1EXYR_9_Q-QP6n7vKbQQkLmP2drwTZSpk/view?usp=drive_link">video link</a>

![Screenshot 2024-09-21 153709](https://github.com/user-attachments/assets/df46738f-d4a5-4850-b5e1-83ccfd88286a)

## Features

1. **Secure Access**:
   - Upon startup, the system prompts the user to enter a password.
   - If the correct password is entered, the door opens.
   - If the password is incorrect, "Wrong Password" is displayed on the LCD.

2. **User Control**:
   - Once inside, the user is prompted to choose between controlling the **Light** or the **Fan**.
   - The user can then select either **Manual** or **Automatic** control.

3. **Manual Control**:
   - **Fan**: The speed of the fan can be adjusted manually using a potentiometer.
   - **Light**: Lights can be toggled on and off using a switch.

4. **Automatic Control**:
   - **Fan**: In automatic mode, the system uses room temperature data to adjust the fan speed automatically.

5. **Microcontroller Communication**:
   - Two AVR microcontrollers are used:
     - **Microcontroller 1**: Handles user input (Light/Fan, Auto/Manual selection).
     - **Microcontroller 2**: Receives the user's choices from Microcontroller 1 via **UART** communication and executes the commands.

## Components Used
- **AVR Microcontrollers** (2)
- **LCD Display** for feedback and status messages
- **Potentiometer** for manual fan speed control
- **Switch** for manual light control
- **Temperature Sensor** for automatic fan control
- **UART Communication** for microcontroller interaction

## Team
- **Teammates**: [Eman Abdelazeem](https://github.com/Emaaanabdelazeemm), [Shiamaa Kamel](https://github.com/Shaimaakamel474)
- **Instructors**: Eng. Youssef Gohar, Eng. Dina

