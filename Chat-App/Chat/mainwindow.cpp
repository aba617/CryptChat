//main window after login
//contains friends list and convos
//send and receives messages


#include "QtGui/qmainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "user.h"
#include <QtNetwork>
#include <QTcpSocket>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Crypt-Chat");

    QString username= QString::fromStdString(usr->getusername());

     ui->thisusr->setText(username);
     TabDialog *t= new TabDialog(usr,this) ;

     //t->tabsocket=mainsocket;
     addnew=new addnewfriend();

     size=loadFriends();
     friends=new int[size];
     ui->convowidget->setLayout(t->mainlayout);


    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);




   this->connect(ui->listoffriends,SIGNAL(itemDoubleClicked(QListWidgetItem*)), t, SLOT(newconvo(QListWidgetItem*)));
   this->connect(this,SIGNAL(convonode(QListWidgetItem*)), t, SLOT(newconvo(QListWidgetItem*)));
   this->connect(this,SIGNAL(testrec(string,string)), t, SLOT(testrev(string,string)));
   this->connect(ui->addfriend, SIGNAL(clicked()),this, SLOT(addfriend()) );
    connect(this, SIGNAL(addthis(QString)), this, SLOT(add(QString)));
     connect(this, SIGNAL(newfriend(QString)), this, SLOT(add(QString)));

    connect(t,SIGNAL(senttomain(string*)), this, SLOT(sentosock(string*)));


   this->connect(ui->logoffbutton, SIGNAL(clicked()),this, SLOT(logoff()));



}
void MainWindow::addfriend(){
    //add a friend request

     QString friendname;
     friendname=ui->friendtoadd->text();
     emit addthis(friendname);
     //this->close();


}
void MainWindow::add(QString g){
    //add friend to friends list
qDebug("add new friend");
ui->listoffriends->insertItem(ui->listoffriends->count()+1,g );
addtofriends(g, usr->getusername());
qDebug("returning friend");
return;
}
void MainWindow::Temprec(string tg){

    //parses received string and finds where to distribute

    string delm="*";
    qDebug("received in main....");
    qDebug(tg.c_str());

    std::string recmsg=tg;
    //test for if message
    std::size_t found = recmsg.find(delm);

    if(found!=std::string::npos&& recmsg.length()>0){
        stringstream stream(recmsg.substr(5));
        qDebug(recmsg.c_str());
        string from;
        getline(stream, from,'*');
        qDebug(from.c_str());
        string message=recmsg.substr(recmsg.find(delm)+1);
        qDebug(message.c_str());
        int test=showtab(from);
//        if(test==0){
//            qDebug("not found");
//            qDebug("not found, new friend");
//            emit newfriend(QString::fromStdString(from));
//            qDebug("not found, showtab");
//            showtab(from);
//            qDebug("new friend message");
//             //emit convonode(ui->listoffriends->item(pos+1));
//            QMessageBox msgBox;
//            //messag.append();
//            msgBox.setText(" You have a new friend");

//            msgBox.setStandardButtons(QMessageBox::Close);
//            msgBox.setDefaultButton(QMessageBox::Close);
//            int ret = msgBox.exec();
//            emit testrec(from, message);

//        }
//        else
            emit testrec(from, message);

    }


     this->update();

    return;


}
void MainWindow::receivingmessage(string msg){
    if(msg=="FALSE"){
        QMessageBox msgBox;
        msgBox.setText("The user you have requested is not online");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();

    }else
         Temprec(msg);

}
int MainWindow::showtab(string item){

    //open convo tab for a new received message
    bool newf=false;
    int pos;
    int ret=0;
    QString receivefrom=QString::fromStdString(item);
    for(pos=0; pos<size; pos++)
    {

        if(ui->listoffriends->item(pos)->text()==receivefrom){
            newf=true;
            qDebug("found");
            emit convonode(ui->listoffriends->item(pos));
            ret=1;
            //tabbox->addWidget(tabwidg->widget(pos));
            break;
        }


    }
//    qDebug("showtab break");
//    //QString messag=receivefrom;
//    if(newf==false)
//    {
//        qDebug("not found, new friend");
//        emit newfriend(receivefrom);
//        qDebug("not found, showtab");
//        showtab(item);
//        qDebug("new friend message");
//         //emit convonode(ui->listoffriends->item(pos+1));
//        QMessageBox msgBox;
//        //messag.append();
//        msgBox.setText(" You have a new friend");

//        msgBox.setStandardButtons(QMessageBox::Close);
//        msgBox.setDefaultButton(QMessageBox::Close);
//        int ret = msgBox.exec();

//    }

    return ret;

}
string MainWindow::searchFrom(string rec){
    string dt="";
 //not used if final version
    return dt;
}
string MainWindow::getMessage(string mes){

    string message=mes;
 //not used if final version

    return message;
}

int MainWindow:: loadFriends(){
    //loads friends list


    QList<QStringList> list;
    QStringList templist;
    QStringList onlinefriends;
    QList<QStringList> offlist;
    QStringList offtemplist;
    QStringList offlinefriends;



    onlinefriends=(getusers(usr->getusername()));
    templist=onlinefriends;
    list.append(templist);


    offlinefriends=(getOffline(usr->getusername()));
    offtemplist=offlinefriends;
    offlist.append(offtemplist);



    QString temper;
    int i=0;

    foreach(temper, list[i]){
        if(temper.length()>0){
        ui->listoffriends->insertItem(i,temper);
        }
    i++;
    }

    QString offtemper;
    int j=0;

    foreach(offtemper, offlist[j]){

    //ui->offlinelist->insertItem(j,offtemper);
    j++;
    }

    return i;

}
void MainWindow::logoff(){

    //send log off request
    string *loff;
    loff->append("LOGOFF=");
    loff->append(usr->getusername());
    emit sendtologoff(loff);
}
void MainWindow::sentosock(string *g){

    emit sendtolog(g);

}

void MainWindow::closeEvent(QCloseEvent *event){


    this->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
