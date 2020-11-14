#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "QMenu"
#include "QAction"
#include "QAction"
#include "QToolButton"
#include "QSpinBox"

myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));   //添加编辑菜单
    QAction * action_open = editMenu->addAction(              //添加打开菜单
        QIcon(":/imagines/imagine/openfile.jpg"),tr("打开文件(&o)")
                );
    action_open->setShortcut(QKeySequence("Ctrl+o"));       //设置快捷键
    ui->toolBar->addAction(action_open);                  //在工具栏中添加动作

    QActionGroup *group = new QActionGroup(this);           //建立动作组

    QAction * action_L = group->addAction(tr("左对齐(&L)"));   //向动作组中添加动作
    action_L->setCheckable(true);
    action_L->setChecked(true);                               //指定action_L为选中对象

    QAction *action_R = group->addAction(tr("右对齐(&R)"));  //向动作组中添加动作
    action_R->setCheckable(true);

    QAction *action_C = group->addAction(tr("居中对齐(&C)"));   //向动作组中添加动作
    action_C->setCheckable(true);

    editMenu->addSeparator();                                    //向菜单中添加间隔器
    editMenu->addAction(action_L);                               //向菜单中添加动作
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    //-------------------------------------
    ui->toolBar->setAllowedAreas(Qt::LeftToolBarArea);      //设置可以拖动到的区域，toolBar
    QToolButton * toolbtn = new QToolButton(this);    //创建QToolButton
    toolbtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);               //创建一个菜单
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    colorMenu->addAction(tr("黄色"));
    toolbtn->setMenu(colorMenu);                        //添加菜单
    toolbtn->setPopupMode(QToolButton::MenuButtonPopup);    //设置弹出模式
    ui->toolBar->addWidget(toolbtn);        //向工具栏添加QToolButton按钮

    QSpinBox * spinBox = new QSpinBox(this);    //创建QSpinBox
    ui->toolBar->addWidget(spinBox);        //向工具栏添加QSpinBox部件

}

myMainWindow::~myMainWindow()
{
    delete ui;
}

