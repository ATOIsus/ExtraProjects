import numpy as np
import cv2
import tensorflow as tf
import math

import os

FRAME_WIDTH = 640
FRAME_HEIGHT = 480

print("[INFO] Starting streaming...")
# pipeline.start(config)
print("[INFO] Camera ready.")

# download model from: https://github.com/opencv/opencv/wiki/TensorFlow-Object-Detection-API#run-network-in-opencv
print("[INFO] Loading model...")
PATH_TO_CKPT = "./frozen_inference_graph.pb"

# Load the Tensorflow model into memory.
detection_graph = tf.Graph()
with detection_graph.as_default():
    od_graph_def = tf.compat.v1.GraphDef()
    with tf.compat.v1.gfile.GFile(PATH_TO_CKPT, 'rb') as fid:
        serialized_graph = fid.read()
        od_graph_def.ParseFromString(serialized_graph)
        tf.compat.v1.import_graph_def(od_graph_def, name='')
    sess = tf.compat.v1.Session(graph=detection_graph)


# coordinate distance
def distance(x1, x2, y1, y2):
    # width =math.sqrt( ((xmin-ymin)**2)+((xmax-ymin)**2) )
    # height = math.sqrt( ((xmax-ymin)**2)+((xmax-ymax)**2) )
    # area = int((width * height)/100)
    return math.sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2))


# Input tensor is the image
image_tensor = detection_graph.get_tensor_by_name('image_tensor:0')
# Output tensors are the detection boxes, scores, and classes
# Each box represents a part of the image where a particular object was detected
detection_boxes = detection_graph.get_tensor_by_name('detection_boxes:0')
# Each score represents level of confidence for each of the objects.
# The score is shown on the result image, together with the class label.
detection_scores = detection_graph.get_tensor_by_name('detection_scores:0')
detection_classes = detection_graph.get_tensor_by_name('detection_classes:0')
# Number of objects detected
num_detections = detection_graph.get_tensor_by_name('num_detections:0')
# code source of tensorflow model loading: https://www.geeksforgeeks.org/ml-training-image-classifier-using-tensorflow-object-detection-api/
print("[INFO] Model loaded.")
colors_hash = {}
classes_90 = ["background", "person", "bicycle", "car", "motorcycle",
              "airplane", "bus", "train", "truck", "boat", "traffic light", "fire hydrant",
              "unknown", "stop sign", "parking meter", "bench", "bird", "cat", "dog", "horse",
              "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "unknown", "backpack",
              "umbrella", "unknown", "unknown", "handbag", "tie", "suitcase", "frisbee", "skis",
              "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard",
              "surfboard", "tennis racket", "bottle", "unknown", "wine glass", "cup", "fork", "knife",
              "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot", "hot dog",
              "pizza", "donut", "cake", "chair", "couch", "potted plant", "bed", "unknown", "dining table",
              "unknown", "unknown", "toilet", "unknown", "tv", "laptop", "mouse", "remote", "keyboard",
              "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "unknown",
              "book", "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush", "cone"]

#  camera

# cap = cv2.imread(r'parking.png')
cap = cv2.VideoCapture("vid1.mp4")
# cap = cv2.VideoCapture(0)

cap.set(cv2.CAP_PROP_FRAME_WIDTH, FRAME_WIDTH)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT)

with tf.compat.v1.Session(graph=detection_graph) as sess:
    while True:
        ret, img = cap.read()

        im_height, im_width, _ = img.shape
        print(im_height, im_width)
        t = cv2.waitKey(2)

        image_expanded = np.expand_dims(img, axis=0)
        # Perform the actual detection by running the model with the image as input
        (boxes, scores, classes, num) = sess.run([detection_boxes, detection_scores, detection_classes, num_detections],
                                                 feed_dict={image_tensor: image_expanded})
        boxes = np.squeeze(boxes)
        classes = np.squeeze(classes).astype(np.int32)
        scores = np.squeeze(scores)
        for idx in range(int(num)):
            class_ = classes[idx]
            score = scores[idx]
            box = boxes[idx]
            print(box)
            print(score)

            if score > 0.5:
                ymin = int(box[0] * im_height)
                xmin = int(box[1] * im_width)
                ymax = int(box[2] * im_height)
                xmax = int(box[3] * im_width)

                p1 = (xmin, ymin)
                p2 = (xmax, ymax)

                # cv2.rectangle(img,(70,160),(330,700),(0,0,255),3)

                cv2.rectangle(img, p1, p2, (0, 0, 255), 2, 1)
                cv2.putText(img, classes_90[class_], p1, cv2.FONT_HERSHEY_SIMPLEX,
                            1, (255, 0, 0), 2, cv2.LINE_AA)
                print(classes_90[class_])

        if t == ord('q'):
            break

        cv2.imshow('output', img)
