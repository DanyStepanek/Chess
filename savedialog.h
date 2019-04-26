#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QDialog>
#include <QFileSystemModel>


namespace Ui {
class SaveDialog;
}

class SaveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveDialog(QWidget *parent = 0);
    ~SaveDialog();

private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::SaveDialog *ui;
    QFileSystemModel *filemodel;
};

#endif // SAVEDIALOG_H
