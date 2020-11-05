#ifndef MYWIDGET_H
#define MYWIDGET_H
class QErrorMessage;
#include <QWidget>
#include<QWizard>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);    //构造函数
    ~MyWidget();                            //析构函数

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    //void on_pushButton_5_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MyWidget *ui;
    QErrorMessage * errordlg;
    QWizardPage * createpage1();
    QWizardPage * createpage2();
    QWizardPage * createpage3();
};
#endif // MYWIDGET_H
