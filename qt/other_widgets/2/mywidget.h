#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private slots:

    void on_pushBtn1_toggled(bool checked);
    void isChecked_Box(bool);

private:
    Ui::myWidget *ui;
};
#endif // MYWIDGET_H
