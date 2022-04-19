import cv2
import random

# Enable camera
cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 420)

# import cascade file for facial recognition
faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

# circle game
touched = True
xrand = 0
yrand = 0

def distanceFromPoint(xpos, ypos, xgoal, ygoal):
    print("Distance from", xgoal, ygoal, ": ", xgoal - xpos, ygoal - ypos)
    if(abs(xgoal - xpos) < 10 and abs(ygoal - ypos) < 10):
        return True
    else:
        return False

while True:
    success, img = cap.read()
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Draw a new circle in random place when touched
    if(touched):
        xrand = random.randrange(100, 400, 1)
        yrand = random.randrange(50, 300, 1)
        touched = False
    img = cv2.circle(img, (xrand, yrand), 10, (0, 0, 255), -1)

    # Getting corners around the face
    faces = faceCascade.detectMultiScale(imgGray, 1.3, 5)  # 1.3 = scale factor, 5 = minimum neighbor
    # drawing bounding box around face
    for (x, y, w, h) in faces:
        img = cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 3)
        touched = distanceFromPoint(x, y, xrand, yrand)

    cv2.imshow('face_detect', img)
    if cv2.waitKey(10) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyWindow('face_detect')