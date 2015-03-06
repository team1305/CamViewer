#ifndef CHOOSERDIALOG_H
#define CHOOSERDIALOG_H

#include <QDialog>
#include <QCameraInfo>
#include <QList>

namespace Ui {
class ChooserDialog;
}

class ChooserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooserDialog(QWidget *parent = 0);
    ~ChooserDialog();

public slots:
    void populateList();
    void updateSelected(int row);

private slots:
    void emitSelectButtonPress();

signals:
    void cameraSelected(QCameraInfo cam);
    void selectButtonPressed(QCameraInfo* cam);

private:
    Ui::ChooserDialog *ui;
    QList<QCameraInfo> camlist;
    QCameraInfo currentCamera;
};

#endif // CHOOSERDIALOG_H
