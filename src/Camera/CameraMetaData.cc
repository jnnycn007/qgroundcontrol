/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "CameraMetaData.h"
#include "QGCLoggingCategory.h"

QGC_LOGGING_CATEGORY(CameraMetaDataLog, "qgc.camera.camerametadata")

CameraMetaData::CameraMetaData(const QString &canonicalName,
                               const QString &brand,
                               const QString &model,
                               double sensorWidth,
                               double sensorHeight,
                               double imageWidth,
                               double imageHeight,
                               double focalLength,
                               bool landscape,
                               bool fixedOrientation,
                               double minTriggerInterval,
                               const QString &deprecatedTranslatedName)
    : canonicalName(canonicalName)
    , brand(brand)
    , model(model)
    , sensorWidth(sensorWidth)
    , sensorHeight(sensorHeight)
    , imageWidth(imageWidth)
    , imageHeight(imageHeight)
    , focalLength(focalLength)
    , landscape(landscape)
    , fixedOrientation(fixedOrientation)
    , minTriggerInterval(minTriggerInterval)
    , deprecatedTranslatedName(deprecatedTranslatedName)
{
    qCDebug(CameraMetaDataLog) << this;
}

CameraMetaData::~CameraMetaData()
{
    qCDebug(CameraMetaDataLog) << this;
}
