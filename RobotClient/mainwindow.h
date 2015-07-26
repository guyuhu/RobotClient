#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QMessageBox>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void sendData();
        void getClientMessage();
    private:
        Ui::MainWindow *ui;

        bool status;
        int port;
        QHostAddress *serverIP;
        QString clientID;
        QTcpSocket *tcpSocket;

    public slots:
        void slotConnected();
        void slotDisconnected();
        void dataReceived();

    private slots:
        void on_btnConnect_clicked();
};

#endif // MAINWINDOW_H
