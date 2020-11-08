#include "mywidget.h"
#include "ui_mywidget.h"
#include "QDebug"
#include "QMenu"
//3.3.2按钮部件 QAbstractButton类是按钮部件的抽象基类，提供了按钮的通用功能
    //1.QPushButton 提供一个标准的按钮
    //2.QChecked QRadioButton和QGroupBox 对于调查表之类的应用，往往提供多个选择供选择。
        //QChecked提供多个选择，QRadioButton提供一个选择，一般把一组按钮放到QGroupBox里面进行管理。
    //3.QLineEdit部件是一个单行的文本编辑器，它允许用户输入和编辑单行的纯文本内容

myWidget::myWidget(QWidget *parent): QWidget(parent), ui(new Ui::myWidget)
{
    ui->setupUi(this);
   //1
    ui->pushBtn1->setText("&nihao");
    ui->pushBtn2->setText(tr("帮助(&H)"));
    ui->pushBtn3->setText(tr("z&oom"));
    QMenu * menu = new QMenu(this);
    ui->pushBtn3->setMenu(menu);

    //2
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &myWidget::isChecked_Box);

    //3

}

myWidget::~myWidget()
{
    delete ui;
}


void myWidget::on_pushBtn1_toggled(bool checked)
{
    qDebug() << tr("按钮是否按下：") << checked;
}

void myWidget::isChecked_Box(bool n)
{
    qDebug() << tr("选择框被勾选！：")<< n;
}
