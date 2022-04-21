import serial
import time
from croppredict import predictcrop

ser = serial.Serial('/dev/cu.usbmodem14201', 9600, timeout=1)
time.sleep(2)

sensor_data = []

def x():
    while len(sensor_data)<6:
        line = ser.readline()   
        if line:
            string = line.decode().strip('\r\n') 
            sensor_data.append(string)

    print(sensor_data)

    if ('Bad Intensity' in sensor_data):
        msg = "Not an ideal condition"
        return msg
    elif ('Good Intensity' in sensor_data):
        if int(sensor_data[2]) > 0:
            in_arg = [78, 42, 42, sensor_data[-1], 81.604873, sensor_data[-2], 262.717340]
            crop = predictcrop(in_arg)
            return crop
        else:
            msg = "Not an ideal condition"
            return msg

    ser.close()