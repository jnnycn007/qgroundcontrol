import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QGroundControl
import QGroundControl.ScreenTools
import QGroundControl.Controls

import QGroundControl.FactControls

ColumnLayout {
    spacing: _margin
    visible: tabBar.currentIndex === 2

    property var missionItem

    MouseArea {
        Layout.preferredWidth:  childrenRect.width
        Layout.preferredHeight: childrenRect.height

        onClicked: {
            var removeModes = []
            var updateFunction = function(altMode){ missionItem.cameraCalc.distanceMode = altMode }
            removeModes.push(QGroundControl.AltitudeModeMixed)
            if (!missionItem.masterController.controllerVehicle.supportsTerrainFrame) {
                removeModes.push(QGroundControl.AltitudeModeTerrainFrame)
            }
            if (!QGroundControl.corePlugin.options.showMissionAbsoluteAltitude || !_missionItem.cameraCalc.isManualCamera) {
                removeModes.push(QGroundControl.AltitudeModeAbsolute)
            }
            altModeDialogComponent.createObject(mainWindow, { rgRemoveModes: removeModes, updateAltModeFn: updateFunction }).open()
        }

        Component { id: altModeDialogComponent; AltModeDialog { } }

        RowLayout {
            spacing: ScreenTools.defaultFontPixelWidth / 2

            QGCLabel { text: QGroundControl.altitudeModeShortDescription(missionItem.cameraCalc.distanceMode) }
            QGCColoredImage {
                height:     ScreenTools.defaultFontPixelHeight / 2
                width:      height
                source:     "/res/DropArrow.svg"
                color:      qgcPal.text
            }
        }
    }

    GridLayout {
        Layout.fillWidth:   true
        columnSpacing:      _margin
        rowSpacing:         _margin
        columns:            2
        enabled:            missionItem.cameraCalc.distanceMode === QGroundControl.AltitudeModeCalcAboveTerrain

        QGCLabel { text: qsTr("Tolerance") }
        FactTextField {
            fact:               missionItem.terrainAdjustTolerance
            Layout.fillWidth:   true
        }

        QGCLabel { text: qsTr("Max Climb Rate") }
        FactTextField {
            fact:               missionItem.terrainAdjustMaxClimbRate
            Layout.fillWidth:   true
        }

        QGCLabel { text: qsTr("Max Descent Rate") }
        FactTextField {
            fact:               missionItem.terrainAdjustMaxDescentRate
            Layout.fillWidth:   true
        }
    }
}
