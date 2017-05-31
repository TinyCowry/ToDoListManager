#include "listwidgetex.h"
#include <QHBoxLayout>
#include <qcombobox.h>
#include <qdebug.h>

ListWidgetEx::ListWidgetEx(ListWidgetType type, QColor BeginColor, QColor EndColor, QWidget *parent) : QListWidget(parent)
  ,m_beginColor(BeginColor), m_endColor(EndColor)
{
    connect(this, SIGNAL(currentRowChanged(int)),SLOT(updateBackground()));
    connect(this, SIGNAL(itemEntered(QListWidgetItem*)), SLOT(appearfunctionButton(QListWidgetItem*)));
}

void ListWidgetEx::appearfunctionButton(QListWidgetItem *item)
{
//    qDebug() << "in there";
//    QWidget *listWidgetItem = new QWidget;
//    QHBoxLayout *layout = new QHBoxLayout;
//    QComboBox *box = new QComboBox;
//    box->addItem("shanchu");
//    layout->addWidget(box);
//    listWidgetItem->setLayout(layout);
//    setItemWidget(item, listWidgetItem);
}

void ListWidgetEx::updateBackground()
{
    for(int i = 1; i < count(); i += 2)
    {
        item(i)->setBackground(QBrush(QColor(qMin(m_beginColor.red()+15*i, m_endColor.red()),qMin(m_beginColor.green()+15*i, m_endColor.green()), qMin(m_beginColor.blue()+15*i, m_endColor.blue()))));
        item(i)->setTextColor(QColor(255,255,255));
    }
    for(int i = 0; i< count();i += 2)
    {
        item(i)->setBackground(QBrush(QColor(255,255,255)));
        item(i)->setTextColor(QColor(0,0,0));
    }
}



