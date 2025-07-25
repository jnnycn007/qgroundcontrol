/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick

import QGroundControl
import QGroundControl.Controls

QGCFileDialog {
    id:             kmlOrSHPLoadDialog
    folder:         QGroundControl.settingsManager.appSettings.missionSavePath
    title:          qsTr("Select File")
    nameFilters:    ShapeFileHelper.fileDialogKMLOrSHPFilters
}
