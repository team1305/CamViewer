#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCameraViewfinder>
#include <QCamera>
#include "chooserdialog.h"
#include <QDialog>
#include <QCameraInfo>
#include <QWidget>
#include "ui_dialogAbout.h"
#include "chooserdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void changeCamera(QCameraInfo *camInfo);


private:
    Ui::MainWindow *ui;
    //dialogs
    QDialog* dialogAbout;
    ChooserDialog* d;

    QCamera* camera;
    QCameraViewfinder* view;

    QDialog* setup_aboutDialog();

};

#endif // MAINWINDOW_H
