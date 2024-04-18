import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import QtCharts



Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("LSM - unoptimized LestSquareMethod calculator B) ")
    color: "#0E0F11"
    Rectangle
    {
        id: leftRectangle
        width: parent.width/10*7
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
        color: "#0E0F11"
        Rectangle
        {
            id: charRectangle
            width: parent.width/10*8
            height: parent.height/10*8
            anchors.centerIn: parent
            color: "#0E0F11"
            ChartView
            {
                id: fChart
                title: "<b>Least Square Method</b>"
                anchors.fill: parent
                antialiasing: true
                LineSeries
                {
                    id: fLine
                    name: formulaComboBox.currentText
                    XYPoint { x: -3; y: -3}
                    XYPoint { x: 3; y: 3 }
                    property double minX: -5
                    property double maxX: 5
                    property double minY: -5
                    property double maxY: 5
                    //jako punkty dodac punkty oddalone o 1/4 dalej z przodu i z tylu wyliczone z wzoru niz najdalszy i nablizszy punkt

                    axisX: ValuesAxis
                    {
                        id: xAxis
                        max: fLine.maxX
                        min: fLine.minX
                    }

                    axisY: ValuesAxis
                    {
                        id: yAxis
                        max: fLine.maxY
                        min: fLine.minY
                    }
                }
            }
        }
    }

    Rectangle
    {
        id: rightRectangle
        width: parent.width/10*3
        height: parent.height
        anchors.top: parent.top
        anchors.right: parent.right
        color: "#0E0F11"

        Rectangle
        {
            id: formulaRectangle
            width: parent.width
            height: parent.height/10*2
            anchors.top: parent.top
            color: "#0E0F11"

            Text
            {
                id: formulaTextTitle
                width: parent.width
                height: parent.height/2
                anchors.top:parent.top
                color: "white"
                wrapMode: TextInput.Wrap
                text: ("Formula")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Text
            {
                id: formulaText
                width: parent.width
                height: parent.height/2
                anchors.bottom:parent.bottom
                color: "white"
                wrapMode: TextInput.Wrap
                text: ("formula will be displayed here")
                font.italic: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle
        {
            id: formulaChoiceRectangle
            width: parent.width
            height: parent.height/10*1
            anchors.top:formulaRectangle.bottom
            anchors.right: parent.right
            color: "#0E0F11"

            ComboBox
            {
                id: formulaComboBox
                width: parent.width - 40
                anchors.centerIn: parent
                model: mathFormulasModel
                textRole: "name"
            }

            ListModel
            {
                id: mathFormulasModel
                ListElement { name: "Linear: "; formula: "a1*x+a0" }
                ListElement { name: "Power: "; formula: "x^a1+a0" }
                ListElement { name: "Exponential: "; formula: "a1^x+a0" }
                ListElement { name: "Fractional(P^(-1)): "; formula: "x/a1+a0" }
            }

            Connections
            {
                target: LSMcalculator
                function onSetChart(data,formula,minXR,maxXR,minYR,maxYR)
                {
                    formulaText.text = formula
                    fLine.clear()
                    //var minX=-5,maxX=5,minY=-5,maxY=5
                    for(var i = 0; i < data.length; ++i)
                    {
                        var point = data[i];
                        fLine.append( point.x,point.y)
                    }
                    fLine.minX = minXR
                    fLine.maxX = maxXR
                    fLine.minY = minYR
                    fLine.maxY = maxYR
                }
            }
        }

        Rectangle
        {
            id: helpvarRectangle
            width: parent.width
            height: parent.height/10*1
            anchors.top: formulaChoiceRectangle.bottom
            anchors.right: parent.right
            color: "#0E0F11"
            visible: formulaComboBox.currentIndex !== 0 ? true : false

            Rectangle
            {
                id: helpvarRectanglev2
                width: parent.width/8*6
                height: parent.height/8*6
                anchors.centerIn: parent
                color: "white"
                radius: 5
                TextEdit
                {
                    id: helpvarText
                    width: parent.width/8*6
                    height: parent.height/8*6
                    anchors.centerIn: parent
                    wrapMode: TextInput.Wrap
                    text: "Enter an additional value"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        Rectangle
        {
            id: dataRectangle
            width: parent.width
            height: parent.height/10*4
            anchors.top: helpvarRectangle.bottom
            anchors.right: parent.right
            color: "#0E0F11"

            Rectangle
            {
                width: parent.width/8*6
                height: parent.height/8*6
                anchors.centerIn: parent
                color: "white"
                radius: 5
                TextEdit
                {
                    id: textField
                    width: parent.width/8*6
                    height: parent.height/8*6
                    anchors.centerIn:parent
                    wrapMode: TextInput.Wrap
                    text: "Paste coordinates in the format: \nx;y \nx;y \nx;y \n..."
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        Rectangle
        {
            id: buttonRectangle
            width: parent.width
            height: parent.height/10*1
            anchors.top: dataRectangle.bottom
            color: "#0E0F11"
            Button
            {
                id: sendDataButton
                width: parent.width/8*4
                height: parent.height/2
                anchors.centerIn: parent
                text: "Calculate!"
                onClicked:
                {
                    LSMcalculator.getData(textField.text, formulaComboBox.currentIndex,helpvarText.text);
                }
            }

        }
    }
}
