from djitellopy import tello
from time import sleep
from datetime import datetime


me = tello.Tello()
me.connect()

print(me.get_battery())


while True:

    now = datetime.now()

    current_time = now.strftime("%H:%M:%S")
    print("Current Time =", current_time)

    if current_time == "12:27:09":
        for i in range(0,2):
            me.takeoff()
            me.land()