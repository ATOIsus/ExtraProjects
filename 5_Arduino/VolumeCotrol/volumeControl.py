from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
 
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
   IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))
 
# Control volume
#volume.SetMasterVolumeLevel(-0.0, None) #max
#volume.SetMasterVolumeLevel(-5.0, None) #72%
#volume.SetMasterVolumeLevel(-10.0, None) #51%
#volume.SetMasterVolumeLevel(-20.0, None)  # 26%
#volume.SetMasterVolumeLevel(-30.0, None) #13%
#volume.SetMasterVolumeLevel(-50.0, None) # 2%



import time  # To pause the program.
import serial  # To take data from the Serial Port.




def readData():
    """ To connect to the Serial Port to get data from Arduino."""


    ardSerial = serial.Serial("com32", 9600)

    while True:  # Infinite Loop.
            ardData = ardSerial.readline()  # To read data from the port.
            decodedValue = str(ardData[0:len(ardData)].decode('windows-1252'))


            arrValues = decodedValue.split("$")
            # To decode the data. The value will be in string.

            val  = arrValues[1]

            mapVal = int(val) // 16

            print(mapVal)


            #control Volume
            volume.SetMasterVolumeLevel(-mapVal, None) 

readData() 

