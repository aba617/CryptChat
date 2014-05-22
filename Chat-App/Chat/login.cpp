//creates login screen
//connects user to server



#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


    setWindowTitle("Welcome to Crypt-Chat!");

    logincounter=0;
    mysocket = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);
    ui->login_2->setDefault(true);


    this->connect(ui->createnew,SIGNAL(clicked()),this,SLOT(opennew()));
    this->connect(ui->changepass,SIGNAL(clicked()),this,SLOT(changepassw()));
    this->connect(ui->login_2,SIGNAL(clicked()),this,SLOT(checklogin()));
    connect(this, SIGNAL(enterlogin()), this, SLOT(checklogin()));
    this->connect(ui->settingsbutton,SIGNAL(clicked()), this, SLOT(settingsb()));

    connect(mysocket, SIGNAL(readyRead()), SLOT(receiveMessage()));
    connect(this, SIGNAL(loginfosend(string*)), SLOT(sendMessage(string*)));
    connect(this, SIGNAL(sendforkey(string*)), SLOT(sendMessage(string*)));
    connect(this, SIGNAL(sendping(string*)), SLOT(sendMessage(string*)));
    connect(this, SIGNAL(gotlogstatus(string)), this, SLOT(getlogstatus(string)));
    connect(this, SIGNAL(gotkeyandiv(string)), this, SLOT(getkeyandiv(string)));
    connect(this, SIGNAL(logconnect()), SLOT(toggleConnection()));
    connect(this, SIGNAL(connectfailed()), this, SLOT(connectfalse()));
    connect(this, SIGNAL(connectworked()), this, SLOT(connecttrue()));

 }
 void login::settingsb(){


     s=new settings();
     s->connect(s,SIGNAL(saved()),this, SLOT(updateip()));
     s->show();

     temp.setip(s->getip().toStdString());
     temp.setport(s->getport().toStdString());

 }
void login::updateip(){
    temp.setip(s->getip().toStdString());
    temp.setport(s->getport().toStdString());
//    ui->ipaddress->setText(s->getip());
//    ui->p->setText(s->getip());

}
void login::opennew(){
    n= new newuser();
    n->show();
}
void login::changepassw(){
    p= new changepassword();
   p->show();
}
void login::checklogin(){

//validates user info

    QString thisuser=ui->user->text();
    QString thispass=ui->pass->text();

    if(thisuser.count()==0||thispass.count()==0){
        QMessageBox msgBox;
        msgBox.setText("Username or Password cannot be empty");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();
    }else if(checkvalid(thisuser,thispass )) {


    temp.setusername(ui->user->text().toStdString());
    temp.setpassword(ui->pass->text().toStdString());
    temp.setip(ui->ip->text().toStdString());
    temp.setport(ui->port->text().toStdString());



    emit logconnect();





    }
}
bool login::checkvalid(QString thisusr, QString thispassw){

     //not used if final version
    return true;


}
bool login::encryptLogin(string usr, string passw){

    //not used if final version
    bool result;
    string salt;
    string encryptedUsern, encryptedPassw;
    sendToEncrypt loginfo;
    //encryptedUsern= loginfo.sendLoginToEncrypt(usr);
    encryptedPassw=loginfo.hashPass(passw, salt);
    return result;

}
void login::connectfalse(){
    QMessageBox msgBox;
    msgBox.setText("Could not connect to server");

    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    int ret = msgBox.exec();

}
void login::connecttrue(){
    *logger="LOGIN="+temp.getusername();
    *logger+="*PASS:" +temp.getpassword();
    emit loginfosend(logger);
    logincounter=1;
    //pass(&temp);

//    this->hide();

}

void login::pass(allUsers *t){
    //opens mainwindow if all validations pass
    w->usr->setusername(t->getusername());
    w->usr->setpassword(t->getpassword());
    w->usr->setip(t->getip());
    w->usr->setstatus(t->getstatus());
    w->usr->setkey(t->getkey());
    w->usr->setiv(t->getiv());
     //w->mainsocket=mysocket;
    w=new MainWindow();
    connect(w, SIGNAL(sendtolog(string*)), this, SLOT(sendMessage(string*)));
    connect(w, SIGNAL(sendtologoff(string*)), this, SLOT(logoff(string*)));
    this->hide();
    w->show();


    }
void login::keyPressEvent(QKeyEvent *e){
 if (e->key()==Qt::Key_Enter)
 {
  qDebug() << "1";
  emit enterlogin();
 }
}
void login::logoff(string* t){

    emit loginfosend(t);
//    w->close();
//    this->close();

}
void login::getlogstatus(string t){

    //ask server for key and iv for encryption
    string *cred;
    cred->append("CREDREQ");
    qDebug("get status");
    if(1){
        //temp.setstatus("t");
        qDebug("sending for CREDREQ");
        emit sendforkey(cred);
        //pass(&temp);
        //pass(&temp);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Username or Password are invalid");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);

    }

//    w->close();
//    this->close();

}
void login::getkeyandiv(string t){

    //parses key and iv from server

    Encryption cryp;
    sendToEncrypt sendencrypt;

    string decrypt;
    string line;
    char* thiskey;
    char* thisiv;
     qDebug("opening file");
    QString current= QDir::currentPath();
     string dc = current.toStdString();
     dc.append("/Credentials.txt");


    ifstream readkey;
    readkey.open(dc.c_str());
    getline(readkey,line);
    readkey.close();

    qDebug("closing file");
    qDebug(line.c_str());
    int dcpos=line.find("*IV");
    string tkey=line.substr(4,dcpos-4);
     qDebug("getting 1st key");
    string tiv=line.substr((dcpos+4));
     qDebug("getting 1st iv");
    thiskey=const_cast<char*>(tkey.c_str());
    thisiv=const_cast<char*>(tiv.c_str());


    decrypt=sendencrypt.decryptMessage(t.substr(5), thiskey, thisiv);
    string th=decrypt;

    int pos=th.find("*IV");
    qDebug("getting key");
    string key=th.substr(4,pos-4);
    qDebug(key.c_str());
    qDebug("getting iv");
    string iv=th.substr((pos+4));
    qDebug(iv.c_str());
    temp.setkey(key);
    temp.setiv(iv);
    pass(&temp);
    //this->hide();




}
void login::recfuntion(int *sock){

    //rectest *tp=new rectest(sock);
    //tp->show();
   // tp->test(sock);

}
void login::toggleConnection()
{
    //the login screen defines a variable of type QTcpsocket
    //
    // QTcpSocket *mysocket = new QTcpSocket(this);
    //
    // QTcpsocket is a QObject (just like any object)
    // QTcpsocket has a set of protocols which when
    // it creates a connection between two hosts
    // they can exchange data

    // mysocket->state() returns if it is already connected
    // if not, create a connection

    if (mysocket->state() == QAbstractSocket::UnconnectedState)
    {
       mysocket->connectToHost(QString::fromStdString(temp.getip()), atoi(temp.getport().c_str()));


       if(mysocket->waitForConnected(20000)){
           qDebug("connect");
           emit connectworked();


       }else{
       QMessageBox msgBox;
       msgBox.setText(" Could not connect to host. Try again");

       msgBox.setStandardButtons(QMessageBox::Close);
       msgBox.setDefaultButton(QMessageBox::Close);
       int ret = msgBox.exec();
        }


    }
    else
    {
        mysocket->disconnectFromHost();
        qDebug("didnt work");
        emit connectfailed();
    }
}
void login::sendMessage(string *t)
{
    //example of how the gui and client generate a message to
    //the server

    // "SENDMESSAGE=TO:george*MESSAGE:hi");

    qDebug("sending");
    qDebug(t->c_str());
    mysocket->write(t->c_str());
    qDebug("sent");


}
void login::receiveMessage()
{
    //receive message is signaled by the QTcpsocket
    //if its signaled it reads a line
    //sends it to the mainwindow to be displayed
     string cred="CREDREQ";
    char recmess[1024];
    memset(recmess,0,1024);
   // int receivecounter=0;
    string line;

     qDebug("read...");

    //qint64 bytes = (mysocket->readLine(recmess,sizeof(recmess)));
    qint64 bytes=mysocket->read(recmess,sizeof(recmess));
//     QByteArray pArray=mysocket->readAll();
//     int nSize= pArray.size();
//     memcpy(&recmess, pArray.data(), nSize);
    qDebug(recmess);
    line= string(recmess);
     //qDebug(line.c_str());
    if(line.compare("TRUE")==0){ //emit gotlogstatus(line);
        qDebug("sending for creds");
         logincounter=1;

        //credappend("CREDREQ");
        qDebug("get status");
        qDebug(cred.c_str());
        emit sendforkey(&cred);

        //logincounter++;
        }
    else if(line.substr(0,5)=="CRED="){
         qDebug(recmess);
         logincounter=2;
        emit gotkeyandiv(line);


    }
    else if(line.compare("PING")==0){
        emit sendping(&line);

    }
    else if(line.compare("FALSE")==0){
        QMessageBox msgBox;
        msgBox.setText(" Login info failed. Try again");

        msgBox.setStandardButtons(QMessageBox::Close);
        msgBox.setDefaultButton(QMessageBox::Close);
        int ret = msgBox.exec();
    }

    else if(line.length()>0&& logincounter>1)
    {    w->receivingmessage(line);

    }

}

login::~login()
{
    delete ui;
}
