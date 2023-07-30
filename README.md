# ArduinoProjects - distance_door_locker
# Description
This project is an automated door lock system implemented using an Arduino board, an HC-SR04 ultrasonic distance sensor, a 2x16 LCD screen, and a servo motor.
The system can detect the presence of an object near the door using the ultrasonic sensor and accordingly control the servo motor to lock or unlock the door.
Additionally, it provides real-time information about the door's current state and distance from the object through the LCD screen.

# Hardware Components
Arduino board
HC-SR04 Ultrasonic Distance Sensor
2x16 LCD Screen with I2C Module
Servo Motor

# Libraries Used
<Servo.h> - Library for controlling servo motors.
<LiquidCrystal_I2C.h> - Library for interfacing with I2C-enabled LCD screens.

# Connections
HC-SR04:
Trig Pin: Connected to Digital Pin 4 of Arduino.
Echo Pin: Connected to Digital Pin 3 of Arduino.

LCD Screen with I2C Module:
I2C Data (SDA): Connected to Arduino's SDA (A4) pin.
I2C Clock (SCL): Connected to Arduino's SCL (A5) pin.

Servo Motor Control Pin: 
Connected to Digital Pin 7 of Arduino.

# Global Functions
sensor_Distance()
Description: Reads the sensor value from the HC-SR04 ultrasonic distance sensor and calculates the distance from the object to the sensor.
Returns: The distance (float).

LCD_print()
Description: Sets the LCD cursor to the appropriate position and displays the current state of the door (open or closed) along with the distance from the object.
Returns: Nothing.

servo_State()
Description: Sets the servo motor position based on the state received from the previous function. If the door is open, the servo is set to 180 degrees (unlocked); otherwise, it is set to 0 degrees (locked).
Parameters: State - The state of the door (open or closed).

# Usage
Connect the hardware components as per the provided connections.
Include the required libraries (<Servo.h> and <LiquidCrystal_I2C.h>).
Create instances for the ultrasonic sensor, LCD screen, and servo motor control.
Call the sensor_Distance() function to read the distance from the ultrasonic sensor and store it in a variable.
Determine the current state of the door based on the distance obtained in the previous step.
Call the LCD_print() function to display the door's state and distance on the LCD screen.
Call the servo_State() function with the determined state to control the servo motor accordingly.

# Note
Make sure to adjust any threshold values or distance calculations in the sensor_Distance() function to suit your specific setup.
Ensure that the servo motor's mechanical configuration aligns with the angles used in the servo_State() function (0 degrees for locked and 180 degrees for unlocked).
If your servo motor operates differently, adjust the angles accordingly.
