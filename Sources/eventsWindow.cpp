#include "Headers/eventsWindow.h"


EventsWindow::EventsWindow(EventListElementModel *eventModel, User *user)
    : eventModel(eventModel), user(user) {}


void EventsWindow::updateModel(){
    eventModel->resetEventsModel(user);
    if (user->getCarListSize() > 0){
        (*user->getCarList()[user->getUserChosenCarId()]).updateStatistics();
        user->getCarList()[user->getUserChosenCarId()]->updateCarMileage();
    }
};
