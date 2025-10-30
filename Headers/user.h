#ifndef USER_H
#define USER_H

#include <QSettings>
#include <QObject>
#include <vector>
#include <QFileDialog>
#include "car.h"
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>

class User : public QObject{

    Q_OBJECT

    CustomContainer<std::shared_ptr<Car>> carList;
    int userChosenCarId = 0;

public:

    Q_INVOKABLE void addCar(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume, QString newCarFilepath);

    Q_INVOKABLE void addEvent(QString newEventType, QString newEventName, QString newEventMoneyValue, QString newEventDate, QString newEventMileage,
                              QString newEventComment, QString newEventServiceType, QString newEventAmountOfLitres, QString newEventPricePerLitre);

    Q_INVOKABLE void editChosenCarInfo(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume, QString newCarFilepath);

    Q_INVOKABLE void editChosenEventInfo(int chosenEventId, int eventType, QString newEventName, QString newEventMoney, QString newEventDate, QString newEventMileage,
                                         QString newEventComment, QString newEventLitres, QString newEventPricePerLitre, QString newEventServiceType);

    Q_INVOKABLE void updateChosenCarStatistics();

    Q_INVOKABLE QString getInfoAboutCar(int carIndex, QString infoType) const;

    Q_INVOKABLE QString getInfoAboutEvent(int carIndex, int eventIndex, QString infoType) const;

    Q_INVOKABLE void deleteChosenCar(int chosenDeleteCarId);

    Q_INVOKABLE void deleteChosenEvent(int chosenEventId);


    Q_INVOKABLE int getUserChosenCarId() const;
    Q_INVOKABLE void setUserChosenCarId(int newUserChosenCarId);

    Q_INVOKABLE CustomContainer<std::shared_ptr<Car>> &getCarList();
    Q_INVOKABLE int getCarListSize() const;

    Q_INVOKABLE void setChosenCarImage(int chosenCarId);
    Q_INVOKABLE QString getImagePath();

    Q_INVOKABLE void saveUserData() const;
    Q_INVOKABLE void loadUserData();

    Q_INVOKABLE int getNowDate(QString type) const;

    Q_INVOKABLE CustomContainer<std::shared_ptr<Event>> &getChosenCarEventList();

    Q_INVOKABLE int getChosenCarTankVolume();



    Q_INVOKABLE void saveJsonFile(int chosenCarId, int chosenEventType, int chosenEventMinPrice);

    QJsonObject toJson(int chosenCarId, int chosenEventType, int chosenEventMinPrice) const;

};

#endif // USER_H
