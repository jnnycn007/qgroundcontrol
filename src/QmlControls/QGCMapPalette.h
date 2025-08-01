/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#pragma once

#include <QtCore/QObject>
#include <QtGui/QColor>
#include <QtQmlIntegration/QtQmlIntegration>

/*!
 QGCMapPalette is a variant of QGCPalette which is used to hold colors used for display over
 the map control. Since the coloring of a satellite map differs greatly from the coloring of
 a street map you need to be able to switch between sets of color based on map type.

 Usage:

         1.0

        FlightMap {
            id:             map
            anchors.fill:   parent

            QGCMapPalette { id: mapPal: lightColors: map.isSatelliteMap }

            QGCLabel {
                text:   "Text over map"
                color:  mapPal.text
            }
        }
**/

class QGCMapPalette : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    
    Q_PROPERTY(bool lightColors READ lightColors WRITE setLightColors NOTIFY paletteChanged)

    Q_PROPERTY(QColor text          READ text          NOTIFY paletteChanged)
    Q_PROPERTY(QColor textOutline   READ textOutline   NOTIFY paletteChanged)

public:    
    QGCMapPalette(QObject* parent = nullptr);
    
    /// Text color
    QColor text(void)           const { return _text[_lightColors ? 0 : 1]; }
    QColor textOutline(void)    const { return _textOutline[_lightColors ? 0 : 1]; }

    bool lightColors(void) const { return _lightColors; }
    void setLightColors(bool lightColors);    

signals:
    void paletteChanged(void);
    void lightColorsChanged(bool lightColors);
    
private:
    bool _lightColors = false;

    static const int _cColorGroups = 2;

    static QColor _text[_cColorGroups];
    static QColor _textOutline[_cColorGroups];
};
