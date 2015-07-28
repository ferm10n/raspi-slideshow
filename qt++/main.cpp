#include <QApplication>
#include <QtGui>
#include <iostream>

int main(int argc, char *argv[ ])
{
	QApplication app(argc, argv);
    QWidget *window = new QWidget;

    //Working
//    QGraphicsScene scene;
//    QPixmap imgA;
//    imgA.load("slides/download.jpg");
//    scene.addPixmap(imgA);

    //Not exactly working, preserved
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    QPixmap img;
    img.load("slides/download.jpg");
    item.setPixmap(img);
    scene.addItem(&item);

    QGraphicsView view(&scene, window);

    window->showFullScreen();
    return app.exec();
}
