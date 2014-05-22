//a convo object for each conversation
// its a way to track which message should go
// to who or from who

#include "convoTab.h"
#include "ui_convoTab.h"


//

convoTab::convoTab(allUsers *currentuser, const QString &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::convoTab)
{
    ui->setupUi(this);
    convouser=currentuser;
    thiskey=const_cast<char*>(convouser->getkey().c_str());

    thisiv=const_cast<char*>(convouser->getiv().c_str());

    ui->tabsendbutton->setDefault(true);

      buffer = new QBuffer(this);
      buffer->open(QIODevice::ReadWrite);

    receiverof=user;

    this->connect(ui->tabsendbutton,SIGNAL(clicked()),this, SLOT(createmessage()));




}

QString convoTab::getmessage(){
    QString recmsg;
    recmsg=ui->tabmessage->toPlainText();
    ui->tabmessage->clear();
    return recmsg;



}


void convoTab::createmessage(){
    string from_delimiter="FROM:";
    string message_delimiter="MESSAGE:";
    string star_delimiter="*";
    string sendoption="SENDMESSAGE=TO:";
    string to=receiverof.toStdString();
    QString ms=sender;
    string encrypted;
    ms.append(": ");
    string sendto="";
    sendToEncrypt sendencrypt;

    //sendToClient *thissend;

   ms.append(getmessage());
    sendto.append(sendoption);
    sendto.append(to);
    sendto.append(star_delimiter+message_delimiter);
    Encryption cryp;

    //encrypting outgoing message using
    //encryption object
    encrypted=sendencrypt.encryptMessage(ms.toStdString(), thiskey, thisiv);

    sendto.append(encrypted);


    emit sendthis(&sendto);


  updateconvo(ms);
    //emit trackingbefore(QString::fromStdString(encrypted));



}
void convoTab::receiveMsg(string mess){

    //decrypting outgoing message using
    //decrypting object
    Encryption cryp;
    sendToEncrypt sendencrypt;

    string decrypt;

    decrypt=sendencrypt.decryptMessage(mess, thiskey, thisiv);

    updateconvo(QString::fromStdString(decrypt));


}
void convoTab::updateconvo(QString addmsg){



    int position= ui->tabconvo->count()+1;
    ui->tabconvo->insertItem(position,addmsg);

}


convoTab::~convoTab()
{
    delete ui;
}
