#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QDialog>
#include <QFileSystemModel>


namespace Ui {
class LoadDialog;
}

class LoadDialog : public QDialog
{
    Q_OBJECT

public:

    QString path;

    explicit LoadDialog(QWidget *parent = 0);
    ~LoadDialog();

private slots:
    void on_cancelButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::LoadDialog *ui;
    QFileSystemModel *filemodel;

};

#endif // LOADDIALOG_H
