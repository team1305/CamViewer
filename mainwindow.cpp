#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //construct the about dialog
    dialogAbout = setup_aboutDialog();
    connect(ui->actionAbout, SIGNAL(triggered()), dialogAbout, SLOT(show()));

    //create the camera object and view object
    camera = new QCamera(QCameraInfo::defaultCamera());
    view = new QCameraViewfinder();

    //add the view to the layout and bind the camera to it
    ui->gridLayout->addWidget(view, 0, 0);
    camera->setViewfinder(view);
    camera->setCaptureMode(QCamera::CaptureVideo);
    //start the camera
    camera->start();

    // setup the device chooser dialog
    d = new ChooserDialog();
    connect(ui->actionSelect_Device, SIGNAL(triggered()), d, SLOT(show()));
    connect(d, SIGNAL(selectButtonPressed(QCameraInfo*)), this, SLOT(changeCamera(QCameraInfo*)));



}

MainWindow::~MainWindow()
{
    delete ui;
    delete camera;
    delete view;
    delete dialogAbout;

}

QDialog* MainWindow::setup_aboutDialog()
{
    //set up the about dialog
    QDialog* aboutDialog = new QDialog();
    Ui::DialogAbout uiDialogAbout;
    uiDialogAbout.setupUi(aboutDialog);
    return aboutDialog;
}

void MainWindow::changeCamera(QCameraInfo* camInfo)
{
    if(camera != nullptr) delete camera;
    camera = new QCamera(*camInfo);
    camera->setViewfinder(view);
    camera->start();
}
