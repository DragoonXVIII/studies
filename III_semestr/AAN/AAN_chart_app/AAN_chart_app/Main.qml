import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import QtCharts



Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle
    {
        id: charRectangle
        width: parent.width/10*7
        height: parent.height/10*8
        anchors.top: parent.top
        anchors.left: parent.left
        color:"red"
        ChartView
        {
            title: "Line Chart"
            anchors.fill: parent
            antialiasing: true
            LineSeries
            {
                name: "Line"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1; y: 2 }
                //jako punkty dodac punkty oddalone o 1/4 dalej z przodu i z tylu wyliczone z wzoru niz najdalszy i nablizszy punkt
            }
        }

    }

    Rectangle
    {
        id: formulaChoiceRectangle
        width: parent.width/10*3
        height: parent.height/10*1
        anchors.top:parent.top
        anchors.right: parent.right
        color: "blue"

        ListModel
        {
            id: mathFormulasModel
            ListElement { name: "Funkcja Kwadratowa"; formula: "y = ax^2 + bx + c" }
            ListElement { name: "Funkcja Liniowa"; formula: "y = mx + b" }
            ListElement { name: "Funkcja Wykładnicza"; formula: "y = a * e^(bx)" }
            ListElement { name: "Funkcja Logarytmiczna"; formula: "y = a * log(x) + b" }
            ListElement { name: "Funkcja Sinusoidalna"; formula: "y = A * sin(Bx + C) + D" }
        }

        ComboBox
        {
            id: formulaComboBox
            width: parent.width - 20
            anchors.centerIn: parent
            model: mathFormulasModel
            textRole: "name"
        }
    }

    Rectangle
    {
        id: dataRectangle
        width: parent.width/10*3
        height: parent.height/10*7
        anchors.top: formulaChoiceRectangle.bottom
        anchors.right: parent.right
        color:"yellow"

        TextEdit
        {
            id: textField
            width: parent.width/8*6
            height: parent.height/8*6
            anchors.centerIn: parent
            color: "white"
        }

        Button
        {
            id: sendDataButton
            width: 90
            height: 30
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "calculate"
            onClicked:
            {
                LSMcalculator.getData(textField.text, formulaComboBox.currentIndex);
            }
        }
    }

    Rectangle
    {
        id: formulaRectangle
        width: parent.width
        height: parent.height/10*2
        anchors.bottom: parent.bottom
        color:"green"
        Text
        {
            id: formulaText
            anchors.centerIn: parent
            text: qsTr("formula will be displayed here")
        }
    }
}

