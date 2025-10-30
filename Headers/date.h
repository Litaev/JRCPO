#ifndef DATE_H
#define DATE_H

#include <QVariantMap>
#include <string>
#include <QJsonObject>
#include <QJsonArray>

class Date {
    int year = 1970;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
public:
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setYear(int new_year);
    void setMonth(int new_month);
    void setDay(int new_day);
    void setNowDate();

    std::string getDateAndTimeForDebug(Date &messageDate);

    bool operator > (const Date &secondDate);

    long int getDateForSort() const;

    QVariant getDate() const;
    static QVariant DateToVariant(const Date& date);
    static Date VariantToDate(const QVariant& var);

    QJsonObject toJson() const {
        QJsonObject dateObj;
        dateObj["year"] = year;
        dateObj["month"] = month;
        dateObj["day"] = day;
        dateObj["hour"] = hour;
        dateObj["minute"] = minute;
        dateObj["second"] = second;
        return dateObj;
    }
};

#endif // DATE_H
