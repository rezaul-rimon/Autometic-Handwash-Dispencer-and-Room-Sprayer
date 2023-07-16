# Automatic Handwash and Room Spray System

## Description
This project implements an automatic handwash and room spray system using Arduino. The system dispenses handwash automatically when a person puts their hand under the handwash pot. A 20x4 LCD display shows the remaining handwash level in the pot, as well as the current room temperature and humidity. The system also includes an automatic sprayer that periodically sprays room spray after a time delay. The duration of the spray can be set using two push-button switches. The project utilizes Arduino Uno, MG996R servo motor, 18650 Li-ion battery, 3S BMS (Battery Management System), LM2596 voltage regulator, 12V power adapter, handwash pot, room spray, 2004 LCD display, IR proximity sensor, and other components.

## Features
- Automatic Handwash Dispensing: The system dispenses handwash automatically when a person's hand is detected under the handwash pot.
- Handwash Level Display: A 20x4 LCD display shows the remaining handwash level in the pot.
- Room Temperature and Humidity Monitoring: The LCD display also shows the current room temperature and humidity.
- Automatic Room Spray: The system includes an automatic sprayer that sprays room spray periodically after a time delay.
- Adjustable Spray Duration: The duration of the spray can be set using two push-button switches.

## Hardware Requirements
- Arduino Uno or compatible board
- MG996R servo motor for handwash dispensing
- 18650 Li-ion battery for power supply
- 3S BMS (Battery Management System) for battery protection and charging
- LM2596 voltage regulator for voltage regulation
- 12V power adapter for external power supply
- Handwash pot with dispensing mechanism
- Room spray for automatic sprayer
- 2004 LCD display for visual feedback
- IR proximity sensor for hand detection
- Push-button switches for spray duration adjustment
- Connecting wires
- Other mechanical components as needed for your specific setup

## Software Requirements
- Arduino IDE (Integrated Development Environment)
- Libraries for LCD display, servo motor control, and any other specific sensors or components used in the project

## Installation and Setup
1. Clone the repository to your local machine using the following command: git clone https://github.com/rezaul-rimon/Autometic-Handwash-Dispencer-and-Room-Sprayer.git

2. Connect the required components, including the MG996R servo motor, 18650 Li-ion battery with BMS, LM2596 voltage regulator, 12V power adapter, handwash pot with dispensing mechanism, room spray, 2004 LCD display, IR proximity sensor, push-button switches, and other components, based on the provided schematic or pin connections in the code.

3. Open the Arduino IDE.

4. Open the Arduino sketch (.ino file) for the automatic handwash and room spray system.

5. Install any required libraries for controlling the LCD display, servo motor, IR proximity sensor, etc.

6. Upload the sketch to the Arduino board.

7. Power on the system and ensure all connections are properly made.

8. Calibrate and adjust the system parameters as necessary, such as the handwash dispensing mechanism, spray duration, etc., based on your specific setup.

## Usage
1. Power on the system and ensure that the handwash pot is filled with handwash liquid.

2. When a person puts their hand under the handwash pot, the system will automatically dispense handwash.

3. The 20x4 LCD display will show the remaining handwash level in the pot, as well as the current room temperature and humidity.

4. The automatic sprayer will periodically spray room spray after a time delay, creating a refreshing environment.

5. Use the two push-button switches to adjust the duration of the room spray as desired.

6. Monitor the LCD display for handwash level, room temperature, and humidity readings.

7. Refill the handwash pot as needed.

8. Adjust the spray duration using the push-button switches to achieve the desired room fragrance.

## Contributing
Contributions to this project are welcome! If you have any suggestions, improvements, or encounter any issues, feel free to open an issue or submit a pull request.

## License
[MIT License](LICENSE)
