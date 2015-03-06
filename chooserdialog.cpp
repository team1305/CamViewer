#include "chooserdialog.h"
#include "ui_chooserdialog.h"

ChooserDialog::ChooserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooserDialog),
    camlist(QCameraInfo::availableCameras())
{
    ui->setupUi(this);
    populateList();
    connect(ui->lstDevices, SIGNAL(currentRowChanged(int)), this, SLOT(updateSelected(int)));
    connect(ui->btnSelect, SIGNAL(clicked()), this, SLOT(emitSelectButtonPress()));
    currentCamera = camlist.at(0);
}

void ChooserDialog::populateList()
{
    //first get al of the camera infos
    foreach(const QCameraInfo &cam, camlist)
    {
       ui->lstDevices->addItem(cam.description());
       ui->lstDevices->setCurrentRow(0);
    }
}

void ChooserDialog::updateSelected(int row){
    currentCamera = (camlist.at(row));
}

void ChooserDialog::emitSelectButtonPress()
{
    emit selectButtonPressed(&currentCamera);
}


ChooserDialog::~ChooserDialog()
{
    delete ui;
}


