import QtQuick
import QtQuick.Window
import QtQuick.Controls.Fusion
import qtcplus



Window {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property int temp:0
    Backend{
    id:myBackend
    onNumberEmitted:(num)=>{temp=num}
    }
    Column{
        anchors.centerIn: parent
        spacing:15
        Text{
        font.pointSize:10
        anchors.horizontalCenter: parent.horizontalCenter
        text:"fake temperature slider"
        }
       Row{
       id:myRow
       anchors.horizontalCenter: parent.horizontalCenter
       spacing:15







       }
       Text {
                   id: valueText

                   text: "change temperature to:" + slider.value
                   font.pixelSize: 16
               }

               Slider {
                   id: slider

                   from: 0
                   to: 100
                   stepSize: 1
                   value: 50 // Initial value
                   visible: true


               }
       Button{
       id:generateButton

       height:50
       width:200

       text:"change temperature"

           onClicked: {
               myBackend.generateNumber(slider.value,temp)
               myBackend.numbersGenerated++
           }

       }
       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           font.pointSize:18
           font.bold:true
           text:"times you changed temperature:"+myBackend.numbersGenerated
       }
       Text{
           anchors.horizontalCenter: parent.horizontalCenter
           font.pointSize:18
           font.bold:true
           text:"current temperature:"+temp
       }
    }


}
