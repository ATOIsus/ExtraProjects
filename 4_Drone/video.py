from djitellopy import Tello
import cv2
import time

######################################################################
width = 700  # WIDTH OF THE IMAGE
height = 700  # HEIGHT OF THE IMAGE
startCounter = 1  # 0 FOR FIGHT 1 FOR TESTING
######################################################################

# CONNECT TO TELLO
me = Tello()
me.connect()
me.for_back_velocity = 0
me.left_right_velocity = 0
me.up_down_velocity = 0
me.yaw_velocity = 0
me.speed = 0

print(me.get_battery())


me.streamoff()
me.streamon()
time.sleep(10)


while True:

    # GET THE IMGAE FROM TELLO
    frame_read = me.get_frame_read()
    myFrame = frame_read.frame
    img = cv2.resize(myFrame, (width, height))


    # DISPLAY IMAGE
    cv2.imshow("MyResult", img)

    if startCounter == 7:
        me.takeoff()

        me.send_rc_control(0, 0, 0, 0)
        time.sleep(1)

        me.send_rc_control(0, 15, 0, 0)
        time.sleep(2)

        startCounter = 2

    # WAIT FOR THE 'Q' BUTTON TO STOP
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
