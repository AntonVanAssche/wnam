#!/usr/bin/env python3

# Import the necessary packages
# See requirements.txt for more information
# pip3 install -r requirements.txt
import serial
import pyautogui as pg

pg.FAILSAFE=False

# Open serial port to the Arduino UNO.
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser.flush()

# Continuously read from the serial port.
# To stop the program, press Ctrl+C.
while True:
    if ser.in_waiting > 0:
        # Read the line from the serial port and decode to ASCII characters.
        input = ser.readline().decode('ascii').rstrip()

        # split the input into an array.
        array = input.split(',')

        # get the x, y and button state from the array.
        if len(array) == 3:
            button = int(array[0])
            x = int(array[1])
            y = int(array[2])

            # Print out the values.
            print(button, x, y)

            # If the joystick is pressed, click the mouse.
            if button == 1:
                pg.click(button='left')

            # Move the mouse relative to its current position.
            pg.moveRel(x, y)

