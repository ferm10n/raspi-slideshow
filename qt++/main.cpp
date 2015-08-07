#include <QApplication>
#include <QtGui>
#include <iostream>

int main(int argc, char *argv[ ])
{
	QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setStyleSheet("QWidget{background-color: #000000;}");

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    QPixmap img;
    img.load("slides/download.jpg");
    item.setPixmap(img);
    QGraphicsOpacityEffect *opef = new QGraphicsOpacityEffect;
    QPropertyAnimation *anim = new QPropertyAnimation(opef,"opacity");
    anim->setDuration(7000);
    anim->setStartValue(1);
    anim->setEndValue(0);
    anim->start();
    item.setGraphicsEffect(opef);
    scene.addItem(&item);
    QGraphicsView view(&scene, window);

    window->showFullScreen();
    return app.exec();
}
