#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//#include<opencv2/saliencyBaseClasses.hpp>
//#include<opencv2/saliencySpecializedClasses.hpp>
#include<opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;

////saliency map
//      void GetSaliencyMap(
//      const vector<vector<uint> >&inputimg,
//      const int&                      width,
//      const int&                      height,
//      vector<double>&                 salmap,
//      const bool&                     normflag){

////      vector<double> salmap; bool normflag=true;
//     Mat im = imread("C:/Users/AKROBOT/Desktop/No_qml/trees1.png",IMREAD_COLOR);
//      GetSaliencyMap(im, im.size().width, im.size().height,  salmap,
//      normflag);

//      Mat output;
//      output = Mat( im.rows, im.cols,CV_8UC1);
//      int k=0;

//      for(int y=0;y<im.rows;y++){
//        for(int x=0;x<im.cols;x++){
//          output.at<uchar>(Point(x,y)) = int(salmap[k]);
//          k++;
//        }
//      }

//      imwrite("test_saliency_blackAndWhite.jpg", output );
//}

//void drawLine(Mat im, float lne[4])
//{
// im = imread("C:/Users/AKROBOT/Desktop/No_qml/trees1.png",IMREAD_COLOR);
//    double theMult = max(im.rows,im.cols);
//    // calculate start point
//    Point startPoint;
//    startPoint.x = lne[2]- theMult*lne[0];// x0
//    startPoint.y = lne[3] - theMult*lne[1];// y0
//    // calculate end point
//    Point endPoint;
//    endPoint.x = lne[2]+ theMult*lne[0];//x[1]
//    endPoint.y = lne[3] + theMult*lne[1];//y[1]

//    // draw overlay of bottom lines on image
//    Size sz = im.size();
//    clipLine(sz, startPoint, endPoint);
//    line(im, startPoint, endPoint, Scalar(0,0,255),1, 8, 0);
//    imshow("im",im);
//}

int main()

{

  Mat trees = imread("E:/TTG proj/No_qml/trees.png",IMREAD_COLOR);

  //morphology performed on image
    int morph_elem_trees = 1;
    int morph_size_trees = 1;
    int morph_operator_trees = 4;

    int operation_trees = morph_operator_trees + 2;
    Mat element_trees = getStructuringElement( morph_elem_trees, Size( 2*morph_size_trees + 1, 2*morph_size_trees+1 ), Point( morph_size_trees, morph_size_trees ) );
    morphologyEx( trees,trees, operation_trees, element_trees );
//    imshow( "window_name", trees);

    //canny edge detection
    Mat treescan = trees.clone();

    Canny(trees,treescan,42,42*3,3);
//    imshow("Canny output",treescan);

//   //Probablistic Hough transfrom
   vector<Vec4i> linesP_trees;
   HoughLinesP(treescan,linesP_trees,1,CV_PI/180,35,45,600);
//   cvtColor(treescan,treescan,COLOR_GRAY2BGR);
   // Draw the lines
      for( size_t i = 0; i < linesP_trees.size(); i++ )
      {
          Vec4i l1 = linesP_trees[i];
          line( treescan, Point(l1[0], l1[1]), Point(l1[2], l1[3]), Scalar(200,200,255), 1, LINE_AA);
//          cout<<""<<linesP_trees.at(i)<<endl;
      }

      //noise removal from background
      threshold(treescan,treescan, 225, 255, THRESH_OTSU);

      int size = 3;
      Mat eroded;
      Mat erodeelement = getStructuringElement(2,Size(size,size));
      erode(treescan,eroded,erodeelement);

      //final output
//      imshow("better",eroded);

    ////blob detection////
Mat im = imread("E:/TTG proj/No_qml/trees1.png",IMREAD_COLOR);

//pre processing the image before blob
//int morph_elem_blob = 1;
//int morph_size_blob = 1;
//int morph_operator_blob = 4;

//int operation_blob = morph_operator_blob + 2;
//Mat element_blob = getStructuringElement( morph_elem_blob, Size( 2*morph_size_blob + 1, 2*morph_size_blob +1 ), Point( morph_size_blob, morph_size_blob ) );
//morphologyEx( im,im, operation_blob, element_blob );
////    imshow( "window_name", trees);

SimpleBlobDetector::Params params;
params.minDistBetweenBlobs = 10.0f;
//params.minThreshold = 30;
//params.maxThreshold = 200;
params.filterByInertia = false;
params.filterByConvexity = false;
//params.filterByColor = true;
//params.blobColor = 0;
params.filterByCircularity = false;
params.filterByArea = true;
params.minArea = 10.0f;
params.maxArea = 30.0f;

    vector<KeyPoint> keys;
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    detector->detect( im, keys );

      //draw blobs as red circles

      Mat im_with_kps;
      drawKeypoints(im,keys,im_with_kps,Scalar(0,0,255),DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
//      for( size_t ii = 0; ii < keys.size( ); ++ii )
//         cout << keys[ii].pt.x << " " << keys[ii].pt.y <<std::endl;
//      imshow ("kp",im_with_kps);

      //finding center of the blob
      Rect rr(8,8,15,15);
      Mat roi (im(rr));

//      im.copyTo(roi);

    Mat Gray1;
    cvtColor(roi,Gray1,COLOR_BGR2GRAY);
    threshold(Gray1, Gray1, 75, 255, THRESH_BINARY);

    Mat roiGray;
    cvtColor(Gray1, roiGray, COLOR_GRAY2BGR);
    roiGray.copyTo(roi);
     imshow("r",im);


      //blob inside roi
      SimpleBlobDetector::Params params1;
//      params1.minDistBetweenBlobs = 10.0f;
      //params.minThreshold = 30;
      //params.maxThreshold = 200;
      params1.filterByInertia = false;
      params1.filterByConvexity = false;
      params1.filterByColor = true;
      params1.blobColor = 0;
      params1.filterByCircularity = false;
      params1.filterByArea = true;
      params1.minArea = 10.0f;
      params1.maxArea = 20.0f;
      vector<KeyPoint> keys1;
      Ptr<SimpleBlobDetector> detector1 = SimpleBlobDetector::create(params1);
      detector->detect( roi, keys1 );

        //draw blobs as red circles

        Mat im_with_kps1;
        drawKeypoints(roi,keys1,im_with_kps1,Scalar(0,0,225),DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
              for( size_t ii = 0; ii < keys1.size( ); ++ii )
                 cout << keys1[ii].pt.x << " " << keys1[ii].pt.y <<std::endl;
        imshow("roi",im_with_kps1);
//accessing pixel values
        int pixel_value2 = 0;
        for (int x = 0;x < im.rows; x++)//To loop through all the pixels
        {
            for (int y = 0; y < im.cols; y++)
            {
                pixel_value2 = im.at<uchar>(x,y);
               if(pixel_value2 >=39 && pixel_value2 <= 80){

                   //defining the x and y coordinates at the resp pixel
                   vector<Vec2d> myvec;
                   myvec.push_back(pixel_value2);
                   cout<<"neeeded "<<pixel_value2<<endl;
                   int a;
//                   int array[]=new int [];

                  /* for(a=0 ; a < array.length() ; a++);
                   array[a]=pixel_value2;                    */             }
//                cout << "pixel_value2: " << pixel_value2 << endl;}
            }}

        //loop to store the keypoints
//        if(pixel_value2 >=39 && pixel_value2 <= 80)
//                cout<<pixel_value<<endl;


waitKey(0);

return 0;

}
