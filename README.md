# Image Registration
Program used to combine two images by comparing if one of the images have same picture with the other. If the location is found, it will combine two images and start from it's corresponding point. Program written in C++ and using OpenCV

- <b>Image A</b> </br>
![alt text][imageA]
- <b>Image B</b> </br>
![alt text][imageB]
- <b>Output</b> </br>
![alt text][output]

## Algorithm
1. Image A will be divided into different regions (ex. 6 regions, 8 regions)
2. Compare one of the region on image A to image B using match template 
3. Using minMaxLoc to get the prediction value and coordinates on where the region matches to image B
4. Add rest of the image A's regions to image B
5. Output is combination of image A and image B

[imageA]:https://github.com/adif-git/Image-Registration/blob/master/A1.jpg "Image A"
[imageB]:https://github.com/adif-git/Image-Registration/blob/master/B1.jpg "Image B"
[output]:https://github.com/adif-git/Image-Registration/blob/master/Hasil.jpg "Output"
