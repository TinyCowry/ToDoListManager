#include "widget.h"
#include <lineeditex.h>
#include <QHBoxLayout>
#include <qcolordialog.h>
#include <QHBoxLayout>
#include <planwidgetitem.h>
#include <qlistview.h>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent) //多重继承，继承了basewidget属性和ui的界面
{
    QListWidget *listWidget = new QListWidget(this);
    listWidget->setFrameShape(QFrame::NoFrame);
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QListWidgetItem *item = new QListWidgetItem(listWidget);
    PlanWidgetItem *w = new PlanWidgetItem(TodayItme, QColor(0,0,0),"a", this);
//    PlanWidgetItem *h = new PlanWidgetItem(TodayItme, QColor(0,0,0),"aaaa", 0);
    QHBoxLayout *layout = new QHBoxLayout(this);

////    QListView *listView = new QListView(this);
////    QListModel *listModel = new QListModel(this);
////    listView->setModel(listModel);
////    listModel.
////    listWidget->addItem();

    item->setSizeHint(w->sizeHint());

    listWidget->setItemWidget(item, w);

    layout->addWidget(listWidget);
//    QVBoxLayout *layout = new QVBoxLayout(this);
//    layout->setSpacing(0);
//    layout->addWidget(w);
//    layout->addWidget(h);
    setLayout(layout);


//    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), SLOT(paintbackground()));

//    m_listWidgetToday = new ListWidgetEx(TodayList,QColor(255,50,50), QColor(255,200,200),this);
//    m_listWidgetFutrue = new ListWidgetEx(FutrueList, QColor(255,50,50),QColor(255,200,200),this);
//    m_listWidgetComplete = new ListWidgetEx(CompleteList,QColor(255,50,50),QColor(255,200,200),this);
//    m_listWidgetRecycle = new ListWidgetEx(ReycleList,QColor(255,50,50),QColor(255,200,200),this);
//    QHBoxLayout *layout = new QHBoxLayout(this);
//    layout->addWidget(m_listWidgetToday);
//    ui->widget_3->setLayout(layout);
//    ui->widget_3->layout()->addWidget(m_listWidgetToday);

}

Widget::~Widget()
{

}

//void Widget::on_toolButton_clicked()
//{
//    QColor color = QColorDialog::getColor(Qt::red, this, "选择颜色", QColorDialog::ShowAlphaChannel);
////    QPalette pal = ui->toolButton->palette();
////    pal.setColor(QPalette::Button,QColor(color));
////    ui->toolButton->setPalette(pal);
//    //how can it be so
//    ui->toolButton->setStyleSheet(QString("background-color:rgb(%1,%2,%3);border:none;border-radius:5px;")
//                                  .arg(color.red()).arg(color.green()).arg(color.blue()));
//}






