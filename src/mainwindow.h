#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

#include "loaddialog.h"
#include "savedialog.h"
#include "aboutdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionNew_Tab_triggered();

    void on_addButton_clicked();

    void on_actionExit_triggered();

    void on_actionClose_Tab_triggered();

    void on_actionAbout_triggered();

    void addNewTab();

    void loadFile();

private:
    Ui::MainWindow *ui;
    LoadDialog *lDialog;
    SaveDialog *sDialog;
    AboutDialog *aDialog;

    QFile file;
    int tabCount = 0;
    QList<QString> moves;
};

#endif // MAINWINDOW_H
