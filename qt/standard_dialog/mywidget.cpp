#include "mywidget.h"
#include "ui_mywidget.h"
#include "QColorDialog"
#include "QFileDialog"
#include "QFontDialog"
#include "QInputDialog"
#include "QMessageBox"
#include "QProgressDialog"
#include "QErrorMessage"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}
QWizardPage * MyWidget::createpage1(){      //向导页面1
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return  page;
}
QWizardPage * MyWidget::createpage2(){      //向导页面2
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}
QWizardPage * MyWidget::createpage3(){
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("结束"));
    return  page;
}

//颜色对话框
void MyWidget::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话框"));
    //QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话框"), QColorDialog::ShowAlphaChannel);
    qDebug() << "color : " << color;
}

/*
void MyWidget::on_pushButton_clicked()
{
    QColorDialog dialog(Qt::white, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    QColor color = dialog.currentColor();
    qDebug() << "color : " << color;
}
*/
//字体对话框
void MyWidget::on_pushButton_2_clicked(bool checked)
{
    QFont font = QFontDialog::getFont(&checked, this);
    if(checked){
        ui->pushButton_2->setFont(font);
        qDebug() << font ;
    }
    else
        qDebug() << tr("没有选择字体！");
}

//文件对话框
/*
void MyWidget::on_pushButton_4_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("文件对话框"), "D:");
    qDebug() << "FileName : " << FileName; //打开单个文件
}
*/
/*
void MyWidget::on_pushButton_4_clicked()
{
    QStringList FileNames = QFileDialog::getOpenFileNames(this,tr("文件对话框"), "D:", tr("图片文件（*png *jpg）"));
    qDebug() << "FileName : " << FileNames; //打开多个文件
}
    */
void MyWidget::on_pushButton_4_clicked()
{
    QUrl ExitDirecity = QFileDialog::getExistingDirectoryUrl(this,tr("文件夹对话框")/*, tr("图片文件（*png *jpg）")*/);
    qDebug() << "ExitDirecity : " << ExitDirecity; //得到某个文件夹位置地址
}

//输入对话框
void MyWidget::on_pushButton_5_clicked(bool checked)
{
    //获取字符串
    QString string = QInputDialog::getText(this, tr("输入字符串对话框"),tr("请输入用户名"),QLineEdit::Normal,tr("hi"), &checked);
    if(checked)
        qDebug()<< "string: " <<string;
    //获取整数
    int value1 = QInputDialog::getInt(this, tr("输入整数对话框"),tr("请输入-1000到1000之间的整数"),100, -1000, 1000, 1, &checked);
    if(checked)
        qDebug()<<"int: "<<value1;
    //获取条目
    QStringList items;
    items <<tr("条目1")<<tr("条目2");
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"),tr("请选择或者输入一个条目"), items, 0, true, &checked);
    if(checked)
        qDebug() <<"items: "<<items;

}

//消息对话框   由QMessageBox类提供
void MyWidget::on_pushButton_7_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this, tr("问题对话框"),tr("你了解Qt吗？"),QMessageBox::Yes, QMessageBox::No);
    if(ret1 == QMessageBox::Yes)
        qDebug() <<tr("问题!");

    //提示对话框
    int ret2 = QMessageBox::information(this, tr("提示对话框"),tr("这是Qt书籍!"), QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok)
        qDebug() << tr("提示");

    //警告对话框
    int ret3 = QMessageBox::warning(this, tr("警告对话框"),tr("不能提前结束"), QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort)
        qDebug() <<tr("警告");

    //错误对话框
    int ret4 = QMessageBox::critical(this, tr("严重错误对话框"), tr("发现一个严重错误"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll)
        qDebug() << tr("错误");

    //关于对话框，没有返回值，因为默认只有一个按钮
    QMessageBox::about(this, tr("关于对话框"), tr("致力于Qt的普及工作"));
}

//进度对话框
void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 50000, this);
    dialog.setWindowTitle(tr("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0; i<50000; ++i)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())
            break;
    }
    dialog.setValue(50000);
    qDebug()<< tr("复制结束");
}

//错误信息对话框

void MyWidget::on_pushButton_3_clicked()
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("这里是出错信息"));
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createpage1());				//添加页面1
    wizard.addPage(createpage2());				//添加页面2
    wizard.addPage(createpage3());				//添加页面3
    wizard.exec();
}
