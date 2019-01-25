import serial
from PIL import Image, ImageDraw
import time
img = Image.new('RGBA', (100, 100), 'white')  # create blank image 4X6
pixels = img.load()  # load pixel map
time.sleep(5)
arduinoData = serial.Serial('COM7', 9600, timeout=0)  # connection to arduino set up
time.sleep(1)
print(arduinoData.in_waiting)
while arduinoData.in_waiting == 0:  # while there is data from ardunino do the following
    time.sleep(1)
    pass
for i in range(img.size[1]):   # for every row:
    if i%5 == 0:
        img.show()
    for j in range(img.size[0]):   # For every col
        arduinoString = arduinoData.readline()   # read in data from arduino in string form
        arduinoString = arduinoString.decode("utf-8")
        print(arduinoString)
        print(type(arduinoString))
        try:

                R, G, B = arduinoString.split(",")  # split the string to get each value
                R = int(R)
                G = int(G)
                B = int(B)
                pixels[j, i] = (R, G, B)  # set the colour accordingl
        except ValueError:
            print("error in split\n")
        time.sleep(.01)  # delay iteration by .25 seconds

img.show()


