/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

/// @file
/// @brief Auto connect settings

#pragma once

#include <QtQmlIntegration/QtQmlIntegration>

#include "SettingsGroup.h"

/// Auto connect settings
/// Defines which links should be automatically created and started at runtime
class AutoConnectSettings : public SettingsGroup
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("")
public:
    AutoConnectSettings(QObject* parent = nullptr);

    DEFINE_SETTING_NAME_GROUP()

    DEFINE_SETTINGFACT(autoConnectUDP)
    DEFINE_SETTINGFACT(autoConnectPixhawk)
    DEFINE_SETTINGFACT(autoConnectSiKRadio)
    DEFINE_SETTINGFACT(autoConnectRTKGPS)
    DEFINE_SETTINGFACT(autoConnectLibrePilot)
    DEFINE_SETTINGFACT(autoConnectNmeaPort)
    DEFINE_SETTINGFACT(autoConnectNmeaBaud)
    DEFINE_SETTINGFACT(autoConnectZeroConf)
    DEFINE_SETTINGFACT(udpListenPort)
    DEFINE_SETTINGFACT(udpTargetHostIP)
    DEFINE_SETTINGFACT(udpTargetHostPort)
    DEFINE_SETTINGFACT(nmeaUdpPort)
};
