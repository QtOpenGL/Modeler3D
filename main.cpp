//#include "View/mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#ifndef QT_NO_OPENGL
#include "View/perspective3dwidget.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    a.setApplicationName("Modeler3D");
    a.setApplicationVersion("0.0.1");
#ifndef QT_NO_OPENGL
    Perspective3DWidget widget;
    widget.show();
#else
    QLabel note("OpenGL Support required");
    note.show();
#endif

    return a.exec();
}