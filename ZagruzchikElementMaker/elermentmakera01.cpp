#include "elermentmakera01.h"
#include "./ui_elermentmakera01.h"

/* #### QLibrary Header Files #### */
#include <QFileDialog>
#include <QFileInfo>
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QVector>
#include <QImage>
#include <QGraphicsScene>
#include <QPainter>
#include <QPixmap>

/* #### Language Header Files #### */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>

using namespace std;

string projectPath;

typedef struct
{
    char ElementName[64];
    int pointX[16];
    int pointY[16];
    bool isInput[16];
} ElementStruct;

QString ElementFolders[999];
QString ElementImages[999];

ElementStruct Elementys[512];


ElermentMakerA01::ElermentMakerA01(QWidget *parent) : QMainWindow(parent), ui(new Ui::ElermentMakerA01)
{
    ui->setupUi(this);
}

ElermentMakerA01::~ElermentMakerA01()
{
    delete ui;
}


void ElermentMakerA01::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Zagruzchik Project", "~",
            tr("Zagruzchik(*.zagruz);;All Files (*)"));
    QFileInfo fi(fileName);
    QDir d = QFileInfo(fileName).absoluteDir();
    QString absolute=d.absolutePath();
    projectPath = absolute.toStdString();
    SetUpData();
}


void ElermentMakerA01::on_comboBoxGraphics_currentIndexChanged(int index)
{

}


void ElermentMakerA01::on_ElementList_currentRowChanged(int currentRow)
{

}


void ElermentMakerA01::on_ButtonAddPoint_clicked()
{

}


void ElermentMakerA01::on_ButtonRemovePoint_clicked()
{

}


void ElermentMakerA01::on_actionSave_triggered()
{

}


void ElermentMakerA01::on_actionSave_As_triggered()
{

}


void ElermentMakerA01::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}


void ElermentMakerA01::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("About\nZagruzchik do not have to comply with QT Creator licence terms, unless source material contains QT Libraries.");
    msgBox.exec();
}

// This function handles any drawing that will ocur on the engine.
void ElermentMakerA01::Draw()
{
    ElementScene.clear();

    QGraphicsPixmapItem *ElementItem = ElementScene.addPixmap(Element);
    ElementItem->setScale(0.5f);
    ui->graphicsView->setScene(&ElementScene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->show();

}

// This function loads all data into needed positions of the controlls
void ElermentMakerA01::SetUpData()
{

    string EIMGPath = projectPath + "/Graphics/Elements/";
    // First thing we do is load all background data into the memory
    const char* path = EIMGPath.c_str();

    DIR *dir = opendir(path);

    if (!dir)
    {
        QMessageBox msgBox;
        msgBox.setText("Directory for loading Elements not found!");
        msgBox.exec();
      return;
    }

    struct dirent *entry = readdir(dir);

    int j = 0;

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR && !(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")))
        {
            ElementFolders[j] = entry->d_name;
            ui->comboBoxGraphicsFolder->insertItem(j,entry->d_name);
            j++;
        }

        entry = readdir(dir);
    }


}


void ElermentMakerA01::ListElementFiles(QString ElementFolderName, int i)
{
    string EIMGPath = projectPath + "/Graphics/Elements/" + ElementFolderName.toStdString();
    cout << ElementFolderName.toStdString() <<endl;
    const char* path = EIMGPath.c_str();

    DIR *dir = opendir(path);

    if (!dir)
    {
        QMessageBox msgBox;
        msgBox.setText("Directory for loading Elements not found!");
        msgBox.exec();
      return;
    }

    struct dirent *entry = readdir(dir);

    int j = 0;

    while (entry != NULL)
    {
        if (entry->d_type != DT_DIR && !(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")))
        {
            ElementImages[j] = entry->d_name;
            ui->comboBoxGraphicsFile->insertItem(j,entry->d_name);
        }
        j++;
        entry = readdir(dir);
    }
}

void ElermentMakerA01::on_comboBoxGraphicsFolder_currentIndexChanged(int index)
{
    ui->comboBoxGraphicsFile->clear();
    ListElementFiles(ElementFolders[index], index);
}

void ElermentMakerA01::on_comboBoxGraphicsFile_currentIndexChanged(int index)
{
    string pathys = projectPath + "/Graphics/Elements/" + ui->comboBoxGraphicsFolder->itemText(ui->comboBoxGraphicsFolder->currentIndex()).toStdString();
    pathys += "/" + ui->comboBoxGraphicsFile->itemText(ui->comboBoxGraphicsFile->currentIndex()).toStdString();
    QImage EIMG(QString::fromStdString(pathys));
    if(EIMG.isNull())
    {
        QMessageBox msgBox;
        msgBox.setText("Could not load the image\n" + QString::fromStdString(pathys));
        msgBox.exec();
        return;
    }
    Element = QPixmap::fromImage(EIMG);
    Draw();
}

void ElermentMakerA01::on_buttonAddElement_clicked()
{
    ui->ElementList->insertItem(0,":LOADACTOR");
}
