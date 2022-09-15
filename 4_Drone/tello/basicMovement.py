from djitellopy import tello
from time import sleep


me = tello.Tello()
me.connect()

print(me.get_battery())

me.takeoff()

#Don't move for 1 second.
me.send_rc_control(0, 0, 0, 0)
sleep(1)


#Move forward for 2 seconds with speed 10
me.send_rc_control(0, 10, 0, 0)
sleep(2)



me.land()