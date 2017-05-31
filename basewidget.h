#ifndef BASEWIDGET_H
#define BASEWIDGET_H
#define MARGIN 5//四个角的长度
#define MOVELENGTH 20//拖动窗口的宽度
#include <QWidget>

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = 0);

    int countFlag(QPoint p, int row);
    void setCursorType(int flag);
    int countRow(QPoint p);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool isLeftPressed;
    int curPos;
    QPoint pLast;
    double m_curPosY;
};

#endif // BASEWIDGET_H
