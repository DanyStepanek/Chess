#include "loaddialog.h"
#include "ui_loaddialog.h"

LoadDialog::LoadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadDialog)
{
    ui->setupUi(this);

    QString rPath = QDir::homePath();
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(rPath);

    ui->treeView->setModel(filemodel);

    QModelIndex index = filemodel->index(rPath);

    ui->treeView->expand(index);
    ui->treeView->setCurrentIndex(index);


}

LoadDialog::~LoadDialog()
{
    delete ui;
}

void LoadDialog::on_cancelButton_clicked()
{

}

void LoadDialog::on_loadButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid())
        return;

    path = filemodel->filePath(index);

    emit loadButtonClicked();

}
