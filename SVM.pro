TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        2.cpp \
        yolo5.cpp


INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv4 \
                /usr/local/include/opencv4/opencv2

LIBS += /usr/local/lib/libopencv_*

HEADERS += \
    yolo5.h
