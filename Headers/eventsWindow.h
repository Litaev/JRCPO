#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H


#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringList>
#include "eventListElementModel.h"
#include <QDebug>
#include "user.h"


class EventsWindow : public QObject
{
    Q_OBJECT
public:
    EventsWindow(EventListElementModel *eventModel = nullptr, User *user = nullptr);
    Q_INVOKABLE void updateModel();

private:
    EventListElementModel *eventModel;
    User *user;

};


#endif // EVENTSWINDOW_H
