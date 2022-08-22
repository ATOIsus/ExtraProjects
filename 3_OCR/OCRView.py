

import cv2
from PIL import Image
from pytesseract import pytesseract

camera = cv2.VideoCapture(0, cv2.CAP_DSHOW)

while True:
    _, image = camera.read()

    cv2.imshow('Text detection', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.imwrite('testText1.jpg', image)
        break


camera.release()
cv2.destroyAllWindows()


def tesseract():
    path_to_tesseracts = r"C:\Program Files\Tesseract-OCR\tesseract.exe"

    Imagepath = 'testText1.jpg'
    pytesseract.tesseract_cmd = path_to_tesseracts
    text = pytesseract.image_to_string(Image.open(Imagepath))
    print(text[:-1])


tesseract()