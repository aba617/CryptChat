#ifndef CONVOTAB_H
#define CONVOTAB_H

#include <QWidget>
#include <tabdialog.h>
#include <QString>
#include "sendtoencrypt.h"
//#include "sendtoclient.h"
#include "QtNetwork"
#include "rectest.h"
#include "allusers.h"

namespace Ui {
class convoTab;
}

class convoTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit convoTab(allUsers *currentuser, const QString &name, QWidget *parent = 0);
    QString sender;
    int* sock;
    QString receiverof;
   // QTcpSocket*		convosocket;
    QBuffer*		buffer;
    string *mesSend;
     char *thiskey;
     char *thisiv;
      rectest *test;
    void receiveMsg(string mess);

    ~convoTab();

public slots:
    void createmessage();
//    void sendMessage();


signals:
    void sendthis(string *n);
    void trackingbefore(QString n);
    void trackingafter(QString n);

    
private:
    Ui::convoTab *ui;
    QString getmessage();
    allUsers *convouser;
    void updateconvo(QString addmsg);
};

#endif // CONVOTAB_H
