#include "mymainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainWindow w;
    w.show();
    return a.exec();
}

//1.Qt资源系统、菜单栏和工具栏
// 工具栏得自己添加。
    //1.1 使用资源

    //1.2 编写代码方式添加菜单
    //1.3 菜单栏，QMenu还提供了间隔器
        //动作组QActionGoup类，它可以包含一组动作QAction
    //1.4工具栏
        //QToolBar类提供了一个包含了一组控件的、可以移动的面板，演示程序里面可以看到工具栏可以拖动
        //在设计器中查看QToolBar属性栏，其中toolBarStyle属性用来设置图标和相应文本的显示及其位置
        //moveabel 属性用来设置状态栏是否可以移动。
        //allowedArea用来设置允许停靠的位置
        //iconsize属性用来设置图标的大小
        //floatable属性用来设置是否可以悬浮
        //当然，出此之外，还可以添加其他的窗口部件。
