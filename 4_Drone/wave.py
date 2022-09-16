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

    if current_time == "14:13:33":
        for i in range(0,4):
            sleep(1.5)
            me.takeoff()
            me.land()