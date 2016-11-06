import serial
import sys

for x in xrange(15):
    try:
        s = serial.Serial(baudrate=115200,port='COM'+str(x))
        print "===== USING COM" + str(x) + " ====="
        while True:
            character = s.read()
            if character == '~':
                break
            sys.stdout.write(character)
        break
    except:
        pass


print "===================="
