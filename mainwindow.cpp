#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create the camera object and view object
    camera = new QCamera(QCameraInfo::defaultCamera());
    view = new QCameraViewfinder();

    //add the view to the layout and bind the camera to it
    ui->gridLayout->addWidget(view, 0, 0);
    camera->setViewfinder(view);
    camera->setCaptureMode(QCamera::CaptureVideo);
    //start the camera
    camera->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete camera;
    delete view;

}
