#ifndef LOOPER_H
#define LOOPER_H

#include <QObject>
#include <QQuickItem>
#include <QNetworkAccessManager>
#include <QUuid>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


class looper: public QThread
{
    Q_OBJECT
    QNetworkAccessManager * manager;
    QNetworkReply *reply;
    volatile int qrcode_id;
private slots:
    void replyFinished(QNetworkReply *reply);
 public:
    looper(QObject* parent = 0) : QThread(parent) {
        qrcode_id=0;
        manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &looper::replyFinished);

    };
    void run();
    //this function will open the machine window in order to recieve the butts
    Q_INVOKABLE int stageOne();
    //this function will transfert the butts image to the server, the server shall returns the number of butts + the uuid of the Qr Code
    Q_INVOKABLE int stageTwo();
    Q_INVOKABLE int parseJson(QString);
signals:
    void finishedGatheringDataForItem(QString signalString, unsigned int signalInt);

};

#endif // LOOPER_H
