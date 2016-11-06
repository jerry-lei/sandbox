import serial
import sys

s = serial.Serial(baudrate=115200,port='COM4')

while True:
    character = s.read()
    if character == '~':
        break
    sys.stdout.write(character)
