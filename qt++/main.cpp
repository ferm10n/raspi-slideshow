#include <QApplication>
#include <QtGui>
#include <iostream>

int main(int argc, char *argv[ ])
{
	QApplication app(argc, argv);
    QWidget *window = new QWidget;

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    QPixmap img;
    img.load("slides/download.jpg");
    item.setPixmap(img);
    QGraphicsOpacityEffect *opef = new QGraphicsOpacityEffect;
    opef->setOpacity(0.1);
    item.setGraphicsEffect(opef);
    scene.addItem(&item);
    QGraphicsView view(&scene, window);

    window->showFullScreen();
    return app.exec();
}
