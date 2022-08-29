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


class looper: public QObject
{
    Q_OBJECT
    QNetworkAccessManager * manager;
    QNetworkReply *reply;
private slots:
    void replyFinished(QNetworkReply *reply);
 public:
    looper(QObject* parent = 0) : QObject(parent) {
        manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &looper::replyFinished);
    };

    //this function will open the machine window in order to recieve the butts
    Q_INVOKABLE int stageOne();
    //this function will transfert the butts image to the server, the server shall returns the number of butts + the uuid of the Qr Code
    Q_INVOKABLE int stageTwo();
signals:
    void finishedGatheringDataForItem(QString signalString, unsigned int signalInt);

};

#endif // LOOPER_H
