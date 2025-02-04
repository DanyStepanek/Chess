#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loaddialog.h"
#include "savedialog.h"
#include "customtab.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewTab()
{
    tabCount += 1;
    QString text = "Game (" + QString::number(tabCount) + ")";
    ui->tabWidget->insertTab(tabCount, new QTabWidget(), QIcon(QString("")), text);
}
//File Menu
void MainWindow::on_actionNew_Tab_triggered()
{
   addNewTab();
}

void MainWindow::loadFile(){
   QFile file(lDialog->path);


   if(file.open(QIODevice::ReadWrite)){
        QTextStream input(&file);
        while(!input.atEnd()){
            QString move = input.readLine();
            moves.append(move);

        }

   }
   else{
        perror("File cannot be opened.");
   }

    ui->listWidget->addItems(moves);

    file.close();

}

void MainWindow::on_actionLoad_triggered()
{
    lDialog = new LoadDialog(this);
    lDialog->show();
    QObject::connect(lDialog, SIGNAL(loadButtonClicked()), this, SLOT(loadFile()));




}

void MainWindow::on_actionSave_triggered()
{
    sDialog = new SaveDialog(this);
    sDialog->show();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_addButton_clicked()
{
    addNewTab();
}



void MainWindow::on_actionClose_Tab_triggered()
{
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::on_actionAbout_triggered()
{
    aDialog = new AboutDialog(this);
    aDialog->show();
}
