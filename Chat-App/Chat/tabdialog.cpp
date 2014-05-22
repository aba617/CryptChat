//creates a tabbed tracker
// for all convos
// calls convotab to add to the tracker
// if a new message is called

#include "tabdialog.h"
#include "ui_tabdialog.h"

TabDialog::TabDialog(allUsers *currentuser,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabDialog)
{
    ui->setupUi(this);


       thisuser=currentuser;
      buffer = new QBuffer(this);
      buffer->open(QIODevice::ReadWrite);

    thissender=QString::fromStdString(currentuser->getusername());

    socket = currentuser->getsocket();

    tabWidget= new QTabWidget();

    mainlayout= new QVBoxLayout;


}
string TabDialog::searchFrom(string rec){
    string from;
    for(int i=0; i<rec.size();i++){
        if(rec.at(i)==':'){
            from=rec.substr(0,i);
            break;
        }
    }

    return from;
}
string TabDialog::getMessage(string mes){

    string message=mes;


    return message;
}

int TabDialog::newconvo(QListWidgetItem* item){
   int position;
    QString user=item->text();
    if(!checkifopen(user)){
    convoTab *temp= new convoTab( thisuser,user,this);

    temp->sender=thissender;

    temp->sock=socket;



    position=tabWidget->addTab(temp,user );

    tabWidget->setTabsClosable(true);
    mainlayout->addWidget(tabWidget);

    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(delmytab(int)));
    connect(temp, SIGNAL(sendthis(string*)), this, SLOT(sendtoser(string*)) );

    }
    return position;

}
bool TabDialog::checkifopen(QString find){
    bool open=false;

    for(int count=0; count<tabWidget->count(); count++)
   {     if(tabWidget->tabText(count)==find)
          {  open=true;
            break;
            }
    }
    return open;

}
void TabDialog::receiveConvo(string from, string message){

    QString sentfrom= QString::fromStdString(from);
    for(int count=0; count<tabWidget->count(); count++)
   {     if(tabWidget->tabText(count)==sentfrom)
          {  convoTab *thisconvo=dynamic_cast<convoTab*>(tabWidget->widget(count));
            thisconvo->receiveMsg(message);
            break;
            }
    }


}
void TabDialog::testrev(string f, string l){
    receiveConvo(f,l);
}

void TabDialog::delmytab(const int& x){
    QWidget* tabItem=tabWidget->widget(x);
    tabItem->close();
    tabItem->deleteLater();
    //tabWidget->removeTab(x);

}
void TabDialog::sendtoser(string *t){
    emit senttomain(t);

}

TabDialog::~TabDialog()
{
    delete ui;
}
