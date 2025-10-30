#include "Headers/chooseCarWindow.h"



ChooseCarWindow::ChooseCarWindow(CarListElementModel *carModel, User *user)
    : carModel(carModel), user(user) {}


void ChooseCarWindow::updateModel(){
    carModel->resetModel(user);
};




