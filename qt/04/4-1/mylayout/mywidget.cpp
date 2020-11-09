#include "mywidget.h"
#include "ui_mywidget.h"
//#include <QHBoxLayout>
//#include <QGridLayout>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{

    ui->setupUi(this);
    /*
    QHBoxLayout * layout = new QHBoxLayout;     //水平布局 ，新建一个布局管理器
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);
    layout->setContentsMargins(0, 0, 50, 100);

    setLayout(layout);
    */
    /*
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2); //从第0行0列开始，占据1行2列
    layout->addWidget(ui->pushButton, 0, 2, 1, 1);  //从第0行2列开始，占据1行1列
    layout->addWidget(ui->textEdit, 1, 0, 1, 2);    //从第1行0列开始，占据1行3列
    setLayout(layout);
    */



}

myWidget::~myWidget()
{
    delete ui;
}

