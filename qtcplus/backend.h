#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QtQml>
class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int numbersGenerated MEMBER m_numbersGenerated NOTIFY updateToNumbersGenerated )
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void generateNumber(int min,int temp);
public slots:
    void onUpdateToNumbersGenerated();
signals:
    void numberEmitted(int num);
    void updateToNumbersGenerated();

private:
    int m_numbersGenerated=0;
};

#endif // BACKEND_H
