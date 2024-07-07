#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QString>

class JsonUtils {
public:
    template<typename T>
    static QString toJson(const T& object) {
        QJsonObject jsonObj = QJsonObject::fromVariantMap(object.toVariantMap());
        QJsonDocument doc(jsonObj);
        return doc.toJson(QJsonDocument::Compact);
    }

    template<typename T>
    static T fromJson(const QString& jsonString) {
        QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
        QJsonObject jsonObj = doc.object();
        T object;
        object.fromVariantMap(jsonObj.toVariantMap());
        return object;
    }
};

#endif // JSONUTILS_H
