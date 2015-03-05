#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCameraViewfinder>
#include <QCamera>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QDialog* dialogAbout;

    QCamera* camera;
    QCameraViewfinder* view;

    QDialog* setup_aboutDialog();
};

#endif // MAINWINDOW_H
