#ifndef REFUELING_H
#define REFUELING_H

#include "Headers/event.h"

class User;

class Refueling : public Event, public Presaveable, public Preloadable{
    friend User;
    FUEL_TYPE fuelType;
    float amountOfLitres;
    float pricePerLitre;
public:
    int getRefuelingId() const;
    FUEL_TYPE getFuelType() const override;
    void setFuelType(FUEL_TYPE carFuelType) override;
    float getAmountOfLitres() const override;
    void setAmountOfLitres(float amountOfLitres) override;
    float getPricePerLitre() const override;
    void setPricePerLitre(float pricePerLitre) override;

    QVariantMap preSaveData() const override;
    void preLoadData(QVariantMap &map) override;


    void setServiceType(SERVICE_NAME serviceType) override{};
    SERVICE_NAME getServiceType() const override {return SERVICE_NAME::OTHER_SERVICE;}

    QJsonObject toJson() const override {
        QJsonObject refuelingObj = Event::toJson();
        refuelingObj["fuelType"] = static_cast<int>(fuelType);
        refuelingObj["amountOfLitres"] = amountOfLitres;
        refuelingObj["pricePerLitre"] = pricePerLitre;
        return refuelingObj;
    }

};

#endif // REFUELING_H
