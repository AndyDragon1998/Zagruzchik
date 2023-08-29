#include "zagruzchik.h"
#include "./ui_zagruzchik.h"

Zagruzchik::Zagruzchik(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zagruzchik)
{
    ui->setupUi(this);
}

Zagruzchik::~Zagruzchik()
{
    delete ui;
}

