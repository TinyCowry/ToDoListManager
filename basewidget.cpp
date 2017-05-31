#include "basewidget.h"
#include <qpainter.h>
#include <QDebug>
#include <QMouseEvent>
#include <qapplication.h>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{
    this->setMouseTracking(true);
    //设置在不按鼠标的情况下也触发鼠标移动事件，注意QMainWindow的情况:centralWidget()->setMouseTracking(true);
    isLeftPressed=false;
    curPos=0;//标记鼠标左击时的位置
    this->setMinimumSize(200,100);//设置最小尺寸
    QCursor cursor;
    cursor.setShape(Qt::ArrowCursor);//设置鼠标为箭头形状
   // ui->pushButton->setCursor(cursor);//当放在按钮上时，为箭头
   // cursor.setShape(Qt::OpenHandCursor);
//    QWidget::setCursor(cursor);//当放在主窗口上时，为手形
    qDebug()<<"h="<<this->height();
    setWindowFlags(Qt::FramelessWindowHint);//设置主窗口无边框
    qDebug()<<this->minimumHeight();
}

void BaseWidget::mousePressEvent(QMouseEvent *event)//鼠标按下事件
{
    if(event->button()==Qt::LeftButton)
    {
        this->isLeftPressed=true;
        QPoint temp=event->globalPos();
        pLast=temp;
        curPos=countFlag(event->pos(),countRow(event->pos()));
        m_curPosY = event->pos().y();
        event->ignore();
    }
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event)//鼠标释放事件
{
    if(isLeftPressed)
        isLeftPressed=false;
    QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    event->ignore();
}

void BaseWidget::mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击 全屏
{
    if(event->button()==Qt::LeftButton)
    {
        if(windowState()!=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);//恢复正常模式
    }
    event->ignore();
}

void BaseWidget::mouseMoveEvent(QMouseEvent *event)//鼠标移动事件
{

    int poss=countFlag(event->pos(),countRow(event->pos()));
    setCursorType(poss);
    if(isLeftPressed)//是否左击
    {
        QPoint ptemp=event->globalPos();
        ptemp=ptemp-pLast;
        if(curPos==22 && m_curPosY < (MARGIN + MOVELENGTH))//移动窗口
        {
            ptemp=ptemp+pos();
            move(ptemp);
        }
        else
        {
            QRect wid=geometry();

            switch(curPos)//改变窗口的大小
            {

            case 11:wid.setTopLeft(wid.topLeft()+ptemp);break;//左上角
            case 13:wid.setTopRight(wid.topRight()+ptemp);break;//右上角
            case 31:wid.setBottomLeft(wid.bottomLeft()+ptemp);break;//左下角
            case 33:wid.setBottomRight(wid.bottomRight()+ptemp);break;//右下角
            case 12:wid.setTop(wid.top()+ptemp.y());break;//中上角
            case 21:wid.setLeft(wid.left()+ptemp.x());break;//中左角
            case 23:wid.setRight(wid.right()+ptemp.x());break;//中右角
            case 32:wid.setBottom(wid.bottom()+ptemp.y());break;//中下角
            }
            setGeometry(wid);
        }


        pLast=event->globalPos();//更新位置
    }
    event->ignore();
}

int BaseWidget::countFlag(QPoint p,int row)//计算鼠标在哪一列和哪一行
{
    if(p.y()<MARGIN)
        return 10+row;
    else if(p.y()>this->height()-MARGIN)
        return 30+row;
    else
        return 20+row;
}

void BaseWidget::setCursorType(int flag)//根据鼠标所在位置改变鼠标指针形状
{
    Qt::CursorShape cursor;
    switch(flag)
    {
    case 11:
    case 33:
        cursor=Qt::SizeFDiagCursor;break;
    case 13:
    case 31:
        cursor=Qt::SizeBDiagCursor;break;
    case 21:
    case 23:
        cursor=Qt::SizeHorCursor;break;
    case 12:
    case 32:
        cursor=Qt::SizeVerCursor;break;
    case 22:
//        cursor=Qt::OpenHandCursor;break;
    default:
       //  QApplication::restoreOverrideCursor();//恢复鼠标指针性状
         break;

    }
    setCursor(cursor);
}

int BaseWidget::countRow(QPoint p)//计算在哪一列
{
    return (p.x()<MARGIN)?1:(p.x()>(this->width()-MARGIN)?3:2);
}


