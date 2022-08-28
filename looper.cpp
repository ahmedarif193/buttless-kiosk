#include "looper.h"


int looper::stageOne(){
    qDebug()<<"stageOne 1 function called";

    return 32;
}

int looper::stageTwo(){
    qDebug()<<"stageTwo 2 function called";

    QUrl url("http://localhost:8001/");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("function", "analyze");
    // etc


    manager->post(request, params.query().toUtf8());
    return 32;
}
