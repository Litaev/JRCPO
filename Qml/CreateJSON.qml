import QtQuick
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: createJSONWindow
    visible: true
    clip: false
    width: parent.width
    height: parent.height


    property int chosenCarId: -1;
    property int chosenEventType: -1;
    property int chosenMinEventPrice: 0;

    Rectangle{
        id: createJSONRect
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        radius: 5
        height: 50
        color: "#495057"
        Text{
            id: createJSONText
            anchors.fill: parent
            text: "Create JSON File"
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
        }

        Button{
            id: backButton
            visible: true
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 7
            width: parent.height - 14
            height: width
            onClicked: stackView.pop();
            background: Image {
                id: backIcon
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "qrc:/test11/icons/back_white_icon.png"
            }
        }
        Button{
            id: confirmButton
            visible: true
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 7
            width: parent.height - 14
            height: width
            background: Image {
                id: confirmIcon
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "qrc:/test11/icons/confirm_white_icon.png"
            }
            onClicked: {
                if (chooseCarParamsCheckBox.checkState == Qt.Checked){
                    chosenCarId = -1;
                }
                else{
                    chosenCarId = chooseCarParamsComboBox.currentIndex;
                }

                if (chooseEventTypeCheckBox.checkState == Qt.Checked){
                    chosenEventType = -1;
                }
                else{
                    chosenEventType = chooseEventTypeComboBox.currentIndex;
                }
                chosenMinEventPrice = chooseEventMinPriceTextField.text;

                user.saveJsonFile(chosenCarId, chosenEventType, chosenMinEventPrice);

                stackView.pop();
            }
        }

    }

    ScrollView{
        id: saveParamsScrollView
        anchors.top: createJSONRect.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5

        Rectangle{
            id: chooseCarParamsRect
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: 150
            color: "white"
            radius: 10
            Text{
                id: chooseCarParamsText
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: (parent.height / 2) - 5
                text: "Choose Car to Event Data From:"
                color: "black"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }

            ComboBox {
               anchors.top: chooseCarParamsText.bottom
               anchors.left: parent.left
               width: parent.width - 50
               anchors.margins: 10
               id: chooseCarParamsComboBox
               height: 40
               anchors.centerIn: parent
               model: carListElementModel
               currentIndex: 0
               textRole: "name"
           }
            Text{
                id: chooseCarParamsForCheckBoxText
                anchors.left: parent.left
                anchors.top: chooseCarParamsComboBox.bottom
                anchors.bottom: parent.bottom
                width: parent.width / 3
                text: "ALL CARS:"
                color: "black"
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }

            CheckBox{
                id: chooseCarParamsCheckBox
                anchors.left: chooseCarParamsForCheckBoxText.right
                anchors.top: chooseCarParamsComboBox.bottom
                anchors.bottom: parent.bottom
                width: height
                anchors.margins: 5
                onCheckedChanged: {
                    if (checkState === Qt.Checked){
                        chooseCarParamsComboBox.visible = false;
                    }
                    else{
                        chooseCarParamsComboBox.visible = true;
                    }
                }
            }
        }

        Rectangle{
            id: chooseEventTypeRect
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: chooseCarParamsRect.bottom
            anchors.topMargin: 10
            height: 150
            color: "grey"
            radius: 10
            Text{
                id: chooseEventTypeText
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: (parent.height / 2) - 5
                text: "Choose Events Type To Save:"
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }

            ComboBox {
               id: chooseEventTypeComboBox
               anchors.top: chooseEventTypeText.bottom
               anchors.left: parent.left
               width: parent.width - 50
               anchors.margins: 10
               height: 40
               anchors.centerIn: parent
               model: ["REFUELING", "SERVICE"]
               currentIndex: 0
           }
            Text{
                id: chooseEventTypeForCheckBoxText
                anchors.left: parent.left
                anchors.top: chooseEventTypeComboBox.bottom
                anchors.bottom: parent.bottom
                width: parent.width / 3
                text: "ALL TYPE:"
                color: "white"
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }

            CheckBox{
                id: chooseEventTypeCheckBox
                anchors.left: chooseEventTypeForCheckBoxText.right
                anchors.top: chooseEventTypeComboBox.bottom
                anchors.bottom: parent.bottom
                width: height
                anchors.margins: 5
                onCheckedChanged: {
                    if (checkState === Qt.Checked){
                        chooseEventTypeComboBox.visible = false;
                    }
                    else{
                        chooseEventTypeComboBox.visible = true;
                    }
                }
            }
        }

        Rectangle{
            id: chooseEventMinPriceRect
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: chooseEventTypeRect.bottom
            anchors.topMargin: 10
            height: 70
            color: "white"
            radius: 10
            Text{
                id: chooseEventMinPriceText
                anchors.left: parent.left
                width: parent.width/2
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 10
                text: "Choose Min Price For Event:"
                color: "#000000"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 14
            }
            TextField{
                id: chooseEventMinPriceTextField
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: chooseEventMinPriceText.right
                anchors.right: parent.right
                anchors.margins: 10
                color: "#000000"
                placeholderText: "BYN"
                text: "0"
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
            }

        }

    }

}
