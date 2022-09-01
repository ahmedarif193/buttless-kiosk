#include "looper.h"
#include <QHttpPart>
#include <QFile>
#include <QProcess>

#define QRCODE_URL_REQUEST "http://localhost:9002/api/qrcode/request"
#define QRCODE_URL_ID "http://localhost:9002/api/qrcode/"

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
    multiPart->setParent(reply); // delete the multiPart with the reply
//    file->close();

    return 32;
}
void looper::replyFinished(QNetworkReply *reply){
    QByteArray bytes = reply->readAll(); // bytes
    qDebug()<<bytes;
    qDebug()<<"reply received---------------"<<bytes.length();
    parseJson(bytes);

    start();

}
Q_INVOKABLE int looper::parseJson(QString output){
    QJsonDocument jsonResponse = QJsonDocument::fromJson(output.toUtf8());
    if(!jsonResponse.isEmpty()){

        QJsonObject jsonObject = jsonResponse.object();
        auto uuid = jsonObject["uuid"].toString();
        auto uuid_count = jsonObject["value"].toInt();
        this->qrcode_id = jsonObject["id"].toInt();

        qDebug()<<uuid;
        qDebug()<<uuid_count;
        emit finishedGatheringDataForItem(uuid, uuid_count);
    }
}

void looper::run(){
    while (1) {
        qDebug()<<"--------------- ";
        QThread::msleep(2000);
        qDebug()<<"--------------- ";

        QString sUrl = QString("curl -s ") + QRCODE_URL_ID + QString::number(qrcode_id);

        FILE *fp;
        char path[1035];
        /* Open the command for reading. */
         fp = popen(sUrl.toStdString().c_str(), "r");
         if (fp == NULL) {
           printf("Failed to run command\n" );
           exit(1);
         }

         /* Read the output a line at a time - output it. */
         while (fgets(path, sizeof(path), fp) != NULL) {
           printf("%s", path);
         }

         /* close */
         pclose(fp);
        qDebug()<<"--------------- "<<path;
        parseJson(path);
    }

}
