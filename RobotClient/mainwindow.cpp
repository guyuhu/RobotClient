#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    getClientMessage();

    status = false;

    bool ok=false;
    port=this->ui->editPort->text().toInt(&ok,10);
    serverIP=new QHostAddress();

    this->ui->editServerIP->setText("59.67.235.254");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *填充本地客户端信息，得到基本属性信息。
 */
void MainWindow::getClientMessage()
{
    QString localHostName=QHostInfo::localHostName();
    QHostInfo hostInfo=QHostInfo::fromName(localHostName);//初始化界面，显示本地信息。
    QList<QHostAddress> listAddress=hostInfo.addresses();
    if(!listAddress.isEmpty())
    {
        clientID=localHostName+":"+listAddress.first().toString();
        this->ui->editLocalID->setText(clientID);
    }
}


/*
 * 连接服务器按钮触发事件，具体实施连接服务器功能。
*/
void MainWindow::on_btnConnect_clicked()
{
    this->ui->editLocalID->setText(clientID);
    if(!status)
    {
        QString ip = this->ui->editServerIP->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this,tr("error"),tr("服务器IP错误，请查看服务器IP!"));
            return;
        }
        if(this->ui->editLocalID->text()=="")
        {
            QMessageBox::information(this,tr("error"),tr("本机编号错误，请查看本机编号!"));
            return;
        }

        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
        tcpSocket->connectToHost(*serverIP,port);

        status=true;
    }
    else
    {
        int length=0;
        QString msg=clientID+"leave ...";
        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg. length())
        {
            //QMessageBox::information(this,tr("断开服务器错误"),tr("断开服务器错误，请重新尝试!"));
            return;
        }
        tcpSocket->disconnectFromHost();

        status=false;
    }
}

/*
 * 网络连接成功槽函数，实现和服务器连接成功后的功能。
*/
void MainWindow::slotConnected()
{
    int length=0;
    QString msg=clientID+"connect...";
    if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
    {
        QMessageBox::information(this,tr("连接服务器错误"),tr("连接服务器错误，请检查服务器地址!"));
        return;
    }
    this->ui->btnConnect->setText("断开服务器");
    sendData();
}

/*
 *通过tcpSocket，不断向服务器发送数据。
*/
void MainWindow::sendData()
{
    QString msg=clientID+"this is client";

    tcpSocket->write(msg.toLatin1(),msg.length());
}

/*
 * 网络连接断开槽函数，实现和服务器断开连接后操作。
*/
void MainWindow::slotDisconnected()
{
     this->ui->btnConnect->setText("连接服务器");
}

/*
 * 接收服务器传送来的数据。客户端数据接收槽函数。
*/
void MainWindow::dataReceived()
{
    while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());

        tcpSocket->read(datagram.data(),datagram.size());

        QString msg=datagram.data();

        //这一部分只用来调试程序，显示数据用。
       // ui->txtData->setText(msg);
        ui->txtData->append(msg);
    }
}
