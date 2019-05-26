

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROI
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += main.cpp \
        mainwindow.cpp

HEADERS +=  \
             mainwindow.h \
    imgproc.h

FORMS += mainwindow.ui


INCLUDEPATH += D:/OpenCV/opencv/build/install/include

LIBS += -LD:/OpenCV/opencv/build/install/x64/vc15/lib\
            -lopencv_core400d\
            -lopencv_features2d400d\
            -lopencv_highgui400d\
            -lopencv_imgproc400d\
            -lopencv_objdetect400d\
            -lopencv_imgcodecs400d\
            -lopencv_video400d\
            -lopencv_calib3d400d\
            -lopencv_dnn400d\
            -lopencv_flann400d\
            -lopencv_gapi400d\
            -lopencv_ml400d\
            -lopencv_photo400d\
            -lopencv_stitching400d\
            -lopencv_video400d\
            -lopencv_videoio400d
#if we wanna run in release mode then add the librabries  commented out below
#            -lopencv_core400\
#            -lopencv_features2d400\
#            -lopencv_highgui400\
#            -lopencv_imgproc400\
#            -lopencv_objdetect400\
#            -lopencv_imgcodecs400\
#            -lopencv_video400\
#            -lopencv_calib3d400\
#            -lopencv_dnn400\
#            -lopencv_flann400\
#            -lopencv_gapi400\
#            -lopencv_ml400\
#            -lopencv_photo400\
#            -lopencv_stitching400\
#            -lopencv_video400\
#            -lopencv_videoio400

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
