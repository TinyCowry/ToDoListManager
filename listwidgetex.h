#ifndef LISTWIDGETEX_H
#define LISTWIDGETEX_H

#include <qlistwidget.h>

enum ListWidgetType{
    TodayList,
    FutrueList,
    CompleteList,
    ReycleList,
};



class ListWidgetEx : public QListWidget
{
    Q_OBJECT
public:
    ListWidgetEx(ListWidgetType type, QColor BeginColor, QColor EndColor, QWidget *parent = 0);


public slots:
    //功能：设置间隔颜色
    void updateBackground();

    void appearfunctionButton(QListWidgetItem*item);

private:
    QColor m_beginColor;
    QColor m_endColor;

};

#endif // LISTWIDGETEX_H
