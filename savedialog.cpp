#include "savedialog.h"
#include "ui_savedialog.h"

SaveDialog::SaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog)
{
    ui->setupUi(this);

    QString rPath = QDir::homePath();
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(rPath);
    ui->treeView->setModel(filemodel);
}

SaveDialog::~SaveDialog()
{
    delete ui;
}

void SaveDialog::on_cancelButton_clicked()
{

}

void SaveDialog::on_saveButton_clicked()
{

}
