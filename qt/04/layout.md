## �����£����ֹ���


Qt��Ҫ�ṩ��`QLayout`�༰����������Ϊ���ֹ����������ǿ���ʵ�ֳ����Ĳ��ֹ����ܡ�

Qt������һ�鲼�ֹ����࣬�Ӷ���Ӧ�ó�����û������жӲ������в��֣����磺QLayout�ļ������࣬���ｫ���ǳ�Ϊ���ֹ�����������QWidget�������ʵ��������ʹ�ò��ֹ���������λ������֮�е��Ӳ�����`QWidget::setLayout()`����������һ��������Ӧ�ò��ֹ�������

### 4.1.1���ֹ�����

�������ò��ֹ�����֮�󣬻�������¼�������
* ��λ�Ӳ���
* ��֪���ڵ�Ĭ�ϴ�С
* ��֪ ���ڵ���С��С
* ���ڴ�С�仯ʱ���д���
* �����ݸı�ʱ�Զ�����
	* �����С���ı����Ӳ���������������֮�ı�
	* ���ػ���ʾ�Ӳ���
	* �Ƴ�һ���Ӳ���
	
1. ��ֱ���֣�ui�ֶ�
2. ˮƽ���֣���ʹ��**���Ʋ���**
��mywidget.cpp�ļ������ͷ�ļ�`#include<QHBoxLayout>`��myWidget��Ĺ��캯����������´��룺��ǰ����Ҫ��ui������������棬��ǰ�����������������

```
#include <QHBoxLayout>
------------------------------
    QHBoxLayout * layout = new QHBoxLayout;     //ˮƽ���� ���½�һ�����ֹ�����
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);
    layout->setContentsMargins(0, 0, 50, 100);

    setLayout(layout);
```

3. դ�񲼾ֹ�������QGridLayout��

```
include <QGridLayout>
--------------------------
  QGridLayout * layout = new QGridLayout;
    layout->addWidget(ui->fontComboBox, 0, 0, 1, 2); //�ӵ�0��0�п�ʼ��ռ��1��2��
    layout->addWidget(ui->pushButton, 0, 2, 1, 1);  //�ӵ�0��2�п�ʼ��ռ��1��1��
    layout->addWidget(ui->textEdit, 1, 0, 1, 2);    //�ӵ�1��0�п�ʼ��ռ��1��3��
    setLayout(layout);
```

4. ���岼�ֹ�������QFormLayout��

### 4.1.2���ò�����С





