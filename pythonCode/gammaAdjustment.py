import cv2
import numpy as np

#read image
image = cv2.imread("../assets/putin.jpg")

#define gamma
gamma = 1.5

#create lookup table
values = np.arange(0, 256)
lut = np.uint8(255 * np.power((values/255.0), gamma))
print(lut)

#gamma adjustment. convert image using LUT table. It maps the pixel intensities in the input to the output using values from lut
result = cv2.LUT(image, lut)

#create windows to display image
cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result", cv2.WINDOW_NORMAL)

#display images
cv2.imshow("image", image)
cv2.imshow("result", result)

#press Esc to exit the program
cv2.waitKey(0)

#close all the opended windows
cv2.destroyAllWindows()