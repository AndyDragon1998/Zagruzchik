#ifndef ELEMENTEDITOR_H
#define ELEMENTEDITOR_H

#include <QDialog>

namespace Ui {
class ElementEditor;
}

class ElementEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ElementEditor(QWidget *parent = nullptr);
    ~ElementEditor();

private:
    Ui::ElementEditor *ui;
};

#endif // ELEMENTEDITOR_H
