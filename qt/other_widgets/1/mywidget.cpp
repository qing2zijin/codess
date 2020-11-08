#include "mywidget.h"
#include "ui_mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    //定义QFrame 属性
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    //QLabel 标签，显示文本，图片用的

    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = tr("标题太长，需要进行省略！");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);
    //设置图片
    ui->label->setPixmap(QPixmap("D:/备份/1-图片/me.jpg"));

    //QLCDNumber可以让数码字符显示类似液晶数字

    //QStackedWidget 类提供一个部件栈，可以有多个界面（称为页面），每个界面可以拥有自己的部件，不过每次只能显示一个界面。
    //这个部件需要使用QComboxBox或者QListWidget来选择他的各个页面

    //QToolBox类提供了一列层叠窗口部件，就像QQ中的抽屉效果



}

myWidget::~myWidget()
{
    delete ui;
}

