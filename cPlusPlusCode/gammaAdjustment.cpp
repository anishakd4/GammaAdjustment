#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){

    //Read image
    Mat image = imread("../assets/putin.jpg");

    //define gamma
    float gamma = 1.5;

    Mat lookupTable(1, 256, CV_8U);
    uchar* lut = lookupTable.ptr();
    for(int i=0; i<256; i++){
        lut[i] = int(255*(pow((float)i/255.0, gamma)));
    }
    cout<<lookupTable<<endl;

    //gamma adjustment. convert image using LUT table. It maps the pixel intensities in the input to the output using values from lut
    Mat result;
    LUT(image, lookupTable, result);

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    //display images
    imshow("image", image);
    imshow("result", result);

    //press esc to exit the prgoram
    waitKey(0);

    //close all the opened windows
    destroyAllWindows();

    return 0;
}