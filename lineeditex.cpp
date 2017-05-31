 #include "lineeditex.h"
#include <qcolordialog.h>

LineEditEx::LineEditEx(QWidget *parent): QLineEdit(parent)
{
    m_ptrPushButton = new QPushButton(this);
    connect(m_ptrPushButton, SIGNAL(clicked(bool)), this, SLOT(onPushButtonClicked()));
    setPushButton();
}

void LineEditEx::setDefaultText(QString str)
{
    if(!text().isEmpty())
        text().clear();
    setText(str);
}

void LineEditEx::setPushButton()
{
//    m_ptrPushButton->setGeometry(width()- PUSHBUTTONLENGTH - MARGIN, height() - MARGIN,
//                                 PUSHBUTTONLENGTH, PUSHBUTTONLENGTH);
    m_ptrPushButton->setFixedSize(PUSHBUTTONLENGTH,PUSHBUTTONLENGTH);
    m_ptrPushButton->move(width()- PUSHBUTTONLENGTH - MARGIN,MARGIN);
    QPalette pal = m_ptrPushButton->palette();
    pal.setColor(QPalette::Background,QColor(255,0,0));
    m_ptrPushButton->setPalette(pal);
}

void LineEditEx::mousePressEvent(QMouseEvent *event)
{
//    onLineEditClicked();
}

void LineEditEx::onLineEditClicked()
{
    setFocus();
    text().clear();
}

void LineEditEx::onPushButtonClicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "选择颜色", QColorDialog::ShowAlphaChannel);
    QPalette pal = m_ptrPushButton->palette();
    pal.setColor(QPalette::Background,QColor(color));
    m_ptrPushButton->setPalette(pal);
}

