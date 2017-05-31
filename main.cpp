#include "widget.h"
#include <QApplication>
#include <planwidgetitem.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    PlanWidgetItem *w = new PlanWidgetItem(TodayItme, QColor(0,0,0),"hahah", 0);
//    w->show();

    return a.exec();
}
