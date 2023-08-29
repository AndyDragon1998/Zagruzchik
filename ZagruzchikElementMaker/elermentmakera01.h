#ifndef ELERMENTMAKERA01_H
#define ELERMENTMAKERA01_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class ElermentMakerA01; }
QT_END_NAMESPACE

class ElermentMakerA01 : public QMainWindow
{
    Q_OBJECT

public:
    ElermentMakerA01(QWidget *parent = nullptr);
    ~ElermentMakerA01();

    QGraphicsScene ElementScene;
    QPixmap Element;

private slots:
    void on_actionOpen_triggered();

    void on_comboBoxGraphics_currentIndexChanged(int index);

    void on_ElementList_currentRowChanged(int currentRow);

    void on_ButtonAddPoint_clicked();

    void on_ButtonRemovePoint_clicked();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionAbout_triggered();

    void Draw();

    void SetUpData();

    void ListElementFiles(QString ElementFolderName, int i);

    void on_comboBoxGraphicsFolder_currentIndexChanged(int index);

    void on_comboBoxGraphicsFile_currentIndexChanged(int index);

    void on_buttonAddElement_clicked();

private:
    Ui::ElermentMakerA01 *ui;
};
#endif // ELERMENTMAKERA01_H
