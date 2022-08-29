#include "looper.h"
#include <QHttpPart>
#include <QFile>

#define QRCODE_URL_REQUEST "http://localhost:9002/api/qrcode/request"

int looper::stageOne(){
    qDebug()<<"stageOne 1 function called";

    return 32;
}
//
int looper::stageTwo(){
    qDebug()<<"stageTwo 2 function called";

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart photo;
    photo.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"file\"; filename=\"1.jpg\""));
    photo.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
    QFile *file = new QFile("/home/ahmed/Pictures/GOPR0184.JPG");
    file->open(QIODevice::ReadWrite);
    photo.setBodyDevice(file);
    file->setParent(multiPart);

    multiPart->append(photo);
    qDebug()<<"                                   "<<multiPart;
    QUrl url(QRCODE_URL_REQUEST);
    QNetworkRequest request(url);

    reply = manager->post(request, multiPart);
    connect(manager, &QNetworkAccessManager::finished, this, &looper::replyFinished);
    multiPart->setParent(reply); // delete the multiPart with the reply
//    file->close();

    return 32;
}
void looper::replyFinished(QNetworkReply *reply){
    QByteArray bytes = reply->readAll(); // bytes

    QJsonDocument jsonResponse = QJsonDocument::fromJson(bytes);
    if(!jsonResponse.isEmpty()){
        qDebug()<<"reply received---------------"<<bytes.length();
        qDebug()<<bytes;

        QJsonObject jsonObject = jsonResponse.object();
        auto uuid = jsonObject["uuid"].toString();
        auto uuid_count = jsonObject["value"].toInt();

        qDebug()<<uuid;
        qDebug()<<uuid_count;

        emit finishedGatheringDataForItem(uuid, uuid_count);
    }

};
