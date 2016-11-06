import serial
import time

def reading_fxn(array):
    s = ''
    for c1 in xrange(len(array)):
        s += array[c1]
    print s

s = serial.Serial(baudrate=115200,port='COM4')

while True:
    array = []
    c1 = 0
    while(True):
        character = s.read()
        if character == '\n':
            break;
        else:
            array.append(character)
    reading_fxn(array)
    time.sleep(2)
