#ifndef ZAGRUZCHIK_H
#define ZAGRUZCHIK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Zagruzchik; }
QT_END_NAMESPACE

class Zagruzchik : public QMainWindow
{
    Q_OBJECT

public:
    Zagruzchik(QWidget *parent = nullptr);
    ~Zagruzchik();

private:
    Ui::Zagruzchik *ui;
};
#endif // ZAGRUZCHIK_H
