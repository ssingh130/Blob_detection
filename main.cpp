////#include "mainwindow.h"
////#include <QApplication>

////int main(int argc, char *argv[])
////{
////    QApplication a(argc, argv);
////    MainWindow w;
////    w.show();

////    return a.exec();
////}

//#include "imgproc.h"

//#include <QString>
//#include <QDebug>
//#include <QDir>
//#include <QImage>
//#include <math.h>
//#include <iostream>
//#include <opencv2/opencv.hpp>

//using namespace cv;
//using namespace std;

//static Mat img,hsv,gray,element, merged;
//Mat src, src_gray;
//Mat dst, detected_edges;
//int lowThreshold = 80;
//const int max_lowThreshold = 290;
//const int cratio = 3;
//const int kernel_size = 3;
//const char* window_name = "Tree row edges";

//imgproc::imgproc(QObject *parent) : QObject(parent)
//{

//}

//QString imgproc::fileName()
//{
//    return m_fileName;
//}

//void imgproc::setfileName(const QString &fileName)
//{
//    if (fileName == m_fileName)
//        return;

//    m_fileName = fileName;
//    emit fileNameChanged();
//}

//void imgproc::readImage(const QString &fileName)
//{
//    QString path = QDir(QDir::currentPath()).filePath(fileName);
//    img = cv::imread(path.toStdString(),IMREAD_COLOR);
//    qDebug() << fileName;
//    qDebug() << "currentPath" << path;
////    cvtColor(img,gray,COLOR_BGR2GRAY);
//    cvtColor(img,hsv,COLOR_BGR2HSV);
////    imshow("result",gray);
//    vector<Mat> channels;
//    split(hsv, channels);
////    merge(channels, merged);

////    dst.create( hsv.size(), hsv.type() );
////    cvtColor( hsv, src_gray, COLOR_BGR2GRAY );
//    namedWindow( window_name, WINDOW_AUTOSIZE );

////    blur( src_gray, detected_edges, Size(3,3) );
//    src_gray = 3*channels[0] - channels[1];
//    Canny( src_gray, detected_edges, lowThreshold, max_lowThreshold, kernel_size, true );
////    dst = Scalar::all(0);
////    src.copyTo( dst, detected_edges);
//    imshow( window_name, detected_edges );

//}

//cv::Mat qimage_to_cvmat_copy(const QImage &img, int format)
//{
//    uchar* b = const_cast<uchar*> (img.bits ());
//    int c = img.bytesPerLine();
//    return cv::Mat(img.height(), img.width(), format, b, c).clone();
//}

//void imgproc::readImageStream(const QImage &file)
//{
//    QImage img2 = file.convertToFormat(QImage::Format_RGB32);
//    cv::Mat imageMat = qimage_to_cvmat_copy(img2, CV_8UC4);

////    img = cv::imread(imageMat,IMREAD_COLOR);
////    qDebug() << file;
//    imshow("result",imageMat);

//    ////////////////////////////////////////////////////////////////////////////

////    Mat image1,image2,image3,gray;

////    char keyPress;
////    cout << "Welcome to Qt. Output Displayed for blending of 2 images\n";

////    //read an image
////    image1 = imread("C:/Users/AKROBOT/Desktop/ROI_SEGMENTATION/ROI_SEGMENTATION/1.jpg",IMREAD_COLOR);

//    cvtColor(imageMat,gray,COLOR_BGR2GRAY);
////    imshow("result",gray);
//    cout<<"Gray image size:"<<gray.size()<<endl;

//    //erode image to filter noise
//    int erosion_size = 0.5;
//    element = getStructuringElement(MORPH_CROSS,Size (2*erosion_size+1,2*erosion_size+1),Point(erosion_size,erosion_size));

//    erode(gray,gray,element);
//    // Scan the image searching for points and store them in a vector
//    vector<cv::Point> points;
//    Mat_<uchar>::iterator it = gray.begin<uchar>();
//    Mat_<uchar>::iterator end = gray.end<uchar>();
//    for (; it != end; it++)
//    {
//        if (*it)
//            points.push_back(it.pos());
//    }

//    //figuring out the roi

//    int left,right,top,bottom;
//    for (int i=0;i < points.size();i++) {
//        if (i==0) //initialize corner values
//        {
//            left=right=points[i].x;
//            top=bottom=points[i].y;}
//        if (points[i].x < left)
//            left = points[i].x;

//        if (points[i].x > right)
//            right = points[i].x;

//        if (points[i].y < top)
//            top = points[i].y;

//        if (points[i].y > bottom)
//            bottom = points[i].y;
//            //points.push_back(it.pos());
//    }
//    vector<Point>box_points;
//    box_points.push_back(Point(left,top));
//    box_points.push_back(Point(left,bottom));
//    box_points.push_back(Point(right,top));
//    box_points.push_back(Point(left,bottom));

//    //minimal bounding box
//    RotatedRect box = minAreaRect(Mat(box_points));
//    cout << "box h:" << box.size.height << " w:" << box.size.width << endl;

//    Rect roi;
//    roi.x=200;
//    roi.y=100;
//    roi.width = 200;
//    roi.height=350;

//    cout<<"roi at "<<roi.x<<","<<roi.y << " " << roi.width << "x" << roi.height <<endl;

//    cv:: Mat crop = imageMat(roi);
////    imshow("ROI new",crop);

//    Mat crop2;
//// Drawing a rectangle

//       rectangle(imageMat,Point(200,100),Point(400,450),Scalar(100,245,201),1,LINE_8);
////       imshow("Rectangle",image1);


////    //creating a mask on the ROI
////    Mat mask(crop.rows,crop.cols,CV_8UC1,cv::Scalar(0));
////    imshow("mask",mask);

//  static Mat src,dst,detected_edges,canny_edges;
//  static int lowThreshold = 40;
//  const int max_lowThreshold = 100;
//  static const int ratio = 5;
//  const int kernel_size = 3;
//  static RNG rng(12345);
//  static const char* window_name = "Edge Map";

//    blur( imageMat, detected_edges, Size(3,3) );
//    Canny( detected_edges, canny_edges, lowThreshold, lowThreshold*ratio , kernel_size );
////    imshow( window_name, canny_edges );

//   crop2 = canny_edges(roi);
////   imshow ("cropped",crop2);
//   //    //creating a mask on the ROI
//   Mat mask(canny_edges.rows,canny_edges.cols,CV_8UC1,Scalar(1));
//    crop2.copyTo(mask(Rect(roi.x,roi.y,crop2.cols,crop2.rows)));
//    imshow("result",mask);

//}

