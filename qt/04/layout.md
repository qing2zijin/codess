## 第四章，布局管理


Qt主要提供了`QLayout`类及其子类来作为布局管理器，他们可以实现常见的布局管理功能。

Qt包含了一组布局管理类，从而在应用程序的用户界面中队部件进行布局，例如：QLayout的几个子类，这里将他们称为布局管理器。所有QWidget的子类的实例都可以使用布局管理器管理位于他们之中的子部件，`QWidget::setLayout()`函数可以在一个部件上应用布局管理器。

### 4.1.1布局管理器

部件采用布局管理器之后，会完成以下几个任务：
* 定位子部件
* 感知窗口的默认大小
* 感知 窗口的最小大小
* 窗口大小变化时进行处理
* 当内容改变时自动更新
	* 字体大小、文本或子部件的其他内容随之改变
	* 隐藏或显示子部件
	* 移除一个子部件
	
1. 垂直布局，ui手动
2. 水平布局，先使用**打破布局**
在mywidget.cpp文件中添加头文件`#include<QHBoxLayout>`在myWidget类的构造函数中添加如下代码：（前提是要在ui界面设计器上面，提前添加了这两个部件）

```
#include <QHBoxLayout>
------------------------------
    QHBoxLayout * layout = new QHBoxLayout;     //水平布局 ，新建一个布局管理器
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);
    layout->setContentsMargins(0, 0, 50, 100);

    setLayout(layout);
```

3. 栅格布局管理器（QGridLayout）

```
include <QGridLayout>
--------------------------
  QGridLayout * layout = new QGridLayout;
    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2); //从第0行0列开始，占据1行2列
    layout->addWidget(ui->pushButton, 0, 2, 1, 1);  //从第0行2列开始，占据1行1列
    layout->addWidget(ui->textEdit, 1, 0, 1, 2);    //从第1行0列开始，占据1行3列
    setLayout(layout);
```

4. 窗体布局管理器（QFormLayout）

### 4.1.2设置部件大小





