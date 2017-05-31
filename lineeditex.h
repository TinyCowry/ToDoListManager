#ifndef LINEEDITEX_H
#define LINEEDITEX_H
#define PUSHBUTTONLENGTH 5
#define MARGIN 3
#include <qpushbutton.h>
#include <qlineedit.h>


class LineEditEx : public QLineEdit
{
    Q_OBJECT
public:
    LineEditEx(QWidget *parent);

public:
    void setDefaultText(QString str);

    QString getText();

protected:
    void setPushButton();

    void mousePressEvent(QMouseEvent *event);

private slots:
    void onLineEditClicked();
    void onPushButtonClicked();


private:
    QPushButton *m_ptrPushButton;
};

#endif // LINEEDITEX_H
