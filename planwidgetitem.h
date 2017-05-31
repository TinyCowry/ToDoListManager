#ifndef PLANWIDGETITEM_H
#define PLANWIDGETITEM_H

#include <QWidget>
#include <qpushbutton.h>
#include <QEvent>

enum PlanWidgetType{
    TodayItme,
    FutrueItem,
    CompleteItem,
    ReycleItem,
};

enum MenuListName{
    AddItem,
    DelayItem,
    RemoveItem,
    CompleteItem1,
};

class PlanWidgetItem : public QWidget
{
    Q_OBJECT
public:
    explicit PlanWidgetItem(PlanWidgetType type = TodayItme, const QColor color = QColor(0,0,0), QString str = "default", QWidget *parent = 0);
    virtual ~PlanWidgetItem();
signals:
    void onAddButtonClicked(MenuListName, QColor, QString);
public slots:

protected:
    void initlayout();
    void setFunctionWidget();
    void initButton();

    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

private:
    PlanWidgetType m_itemType;
    QString m_labelStr;
    const QColor m_frontColor;
    QWidget *m_functionWidget;
    QPushButton *addButton;
    QPushButton *delayButton;
    QPushButton *completeButton;
    QPushButton *deleteButton;
};

#endif // PLANWIDGETITEM_H
