"""  To get the sensor values from Arduino's Serial Port and Send it to MongoDB. """

# Note:
#      1) The Arduino must be connected to the laptop/computer.
#      2) The port chosen for Arduino e.g. COM3 needs to be for ardSerial(line 45)
#      3) You cannot use the serial monitor i.e. COM for both Arduino and Python at the same time.
#              An error shows up in either one.
#      4) Some error regarding decode may occur in line 49. Use appropriate decoder.
#           Use:
#              chardet.detect(ardData))     # To identify the encoding type. (one line after ardData is assigned)
#                                           (chardet needs to be installed)
#      5) Remember that the data flow from Arduino should not be very fast or error occurs. minimum: delay(100);


import time  # To pause the program.
import serial  # To take data from the Serial Port.
from pymongo import MongoClient  # To write and fetch data from MongoDB.


# region MongoDB

try:
    # To connect to the MongoDB.
    clientObject = MongoClient("mongodb+srv://test:test@cluster0.9ulav.mongodb.net/test?retryWrites=true&w=majority")
    dataBase = clientObject.hydroponics  # Select a database.
    documentCollection = dataBase.hydro  # Select a collection.

except BaseException as er1:
    print("Error while connecting to the MongoDB")
    quit()


def insertData(val1, val2, val3, val4, val5):
    """To insert data."""

    try:
        # To insert data.
        # dictionaryData = {"Name" : "Data", "Turbity Value": val1, "DHT Value": val2, "PO Value": val3, "T1 Value": val4, "T2 Value": val5}
        # documentCollection.insert_one(dictionaryData)
        # quit()
            

        #To update data.
        identifyDocument = {"Name": "Data"}
        updateData = {"$set": {"Turbity Value": val1, "DHT Value": val2, "PO Value": val3, "T1 Value": val4, "T2 Value": val5}}
        documentCollection.update_one(identifyDocument, updateData)

    except BaseException as er2:
        messagebox.showerror("Error in insertData Function!")
        quit()


# endregion


# region Arduino


def readData():
    """ To connect to the Serial Port to get data from Arduino."""

    try:
        # Connecting to the Serial Port("portNumber",baudRate) ("com" may vary)

        ardSerial = serial.Serial("com31", 9600)

        while True:  # Infinite Loop.
            ardData = ardSerial.readline()  # To read data from the port.
            decodedValues = str(ardData[0:len(ardData)].decode('windows-1252'))


            arrValues = decodedValues.split("$")
            # To decode the data. The value will be in string.

            val  = arrValues[1]
            val2 = arrValues[2]
            val3 = arrValues[3]
            val4 = arrValues[4]
            val5 = arrValues[5]
            

            print("Value1", val, ", Value2", val2, ", Value3", val3, ", Value4", val4,  " ,Value5", val5)

            insertData(val, val2, val3, val4, val5)  # Pass data(in Integer form) to the MongoDB.

            time.sleep(1)  # To pause the program for 1 second.

    except BaseException as er:
        print("Error while connecting to the Serial Monitor!")
        quit()


readData()  # To call the function once.

# endregion