#include "planwidgetitem.h"
#include <QHBoxLayout>
#include <qlabel.h>
#include <qpalette.h>
#include <qpushbutton.h>
#include <qdebug.h>
#include <qlineedit.h>

PlanWidgetItem::PlanWidgetItem(PlanWidgetType type,const QColor color,QString str, QWidget *parent) : QWidget(parent)
  ,m_itemType(type)
  ,m_frontColor(color)
  ,m_labelStr(str)
{
    m_functionWidget = new QWidget(this);
    initButton();
    setFunctionWidget();
//    setMaximumHeight(60);
    setFixedHeight(m_functionWidget->height());
    initlayout();

}

PlanWidgetItem::~PlanWidgetItem()
{
    delete m_functionWidget;
    delete addButton;
    delete delayButton;
    delete completeButton;
    delete deleteButton;
}

void PlanWidgetItem::initlayout()
{
    setContentsMargins(0,0,0,0);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setSpacing(0);
    QWidget *colorWidget = new QWidget(this);
    colorWidget->setFixedWidth(10);

//    QPalette pal;
//    pal.setColor(QPalette::Background, QColor(255,0,0));
//    colorWidget->setPalette(pal);
    colorWidget->setStyleSheet("background:rgb(255,0,10)");//背景颜色好好总结

    layout->addWidget(colorWidget);
    QLabel *TextLabel = new QLabel(m_labelStr);
//    QLineEdit *TextLabel = new QLineEdit(m_labelStr);
    TextLabel->setStyleSheet("padding-left:10px;font-size:20px;");
//    TextLabel->setMaximumWidth(300);
    TextLabel->sizeHint();
    layout->addWidget(TextLabel);
//    layout->addStretch();
    layout->addWidget(m_functionWidget);
    layout->setStretch(1,1);//设置文字框保持最大,重要
    setLayout(layout);
    m_functionWidget->setVisible(false);
}

void PlanWidgetItem::setFunctionWidget()
{
    QHBoxLayout *layout = new QHBoxLayout;
    qDebug() << layout->contentsMargins();

    switch (m_itemType) {
    case TodayItme:
        layout->addWidget(addButton);
        layout->addWidget(delayButton);
        layout->addWidget(completeButton);
        layout->addWidget(deleteButton);
//        m_functionWidget->setMaximumWidth(24*4);
        break;
    default:
        break;

    }
    m_functionWidget->setLayout(layout);
//    m_functionWidget->setFixedHeight(addButton->height());
    m_functionWidget->setStyleSheet("background:rgb(250, 225, 152);padding-top:0px;");
}

//找便捷的方法
void PlanWidgetItem::initButton()
{
    addButton = new QPushButton(this);
    addButton->setFixedSize(QPixmap(":/res/btn_location_hover.png").size());
    connect(addButton, &QPushButton::clicked,[this](){
        emit onAddButtonClicked(AddItem, m_frontColor, m_labelStr);
    });
    addButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/btn_location_hover.png)}\
                             QPushButton{border-image:url(:/res/btn_location_normal.png)};");

    delayButton =new QPushButton(this);
    delayButton->setFixedSize(QPixmap(":/res/btn_location_hover.png").size());
    connect(delayButton, &QPushButton::clicked, [this]() {
        emit onAddButtonClicked(DelayItem, m_frontColor, m_labelStr);
        });
    delayButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/btn_location_hover.png)}\
                               QPushButton{border-image:url(:/res/btn_location_normal.png)};");

    completeButton = new QPushButton(this);
    completeButton->setFixedSize(QPixmap(":/res/btn_location_hover.png").size());
    connect(delayButton, &QPushButton::clicked, [this]() {
        emit onAddButtonClicked(CompleteItem1, m_frontColor, m_labelStr);
        });
    completeButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/btn_location_hover.png)}\
                                  QPushButton{border-image:url(:/res/btn_location_normal.png)};");

    deleteButton = new QPushButton(this);
    deleteButton->setFixedSize(QPixmap(":/res/btn_location_hover.png").size());
    connect(delayButton, &QPushButton::clicked, [this]() {
        emit onAddButtonClicked(RemoveItem, m_frontColor, m_labelStr);
        });
    deleteButton->setStyleSheet("QPushButton:hover{border-image:url(:/res/btn_location_hover.png)}\
                                QPushButton{border-image:url(:/res/btn_location_normal.png)};");


}

void PlanWidgetItem::enterEvent(QEvent *)
{
    m_functionWidget->setVisible(true);
    setStyleSheet("background:rgb(252, 240, 193)");
}

void PlanWidgetItem::leaveEvent(QEvent *)
{
    m_functionWidget->setVisible(false);
    setStyleSheet("background:rgb(255,255,255)");
}



