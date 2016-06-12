/*
*   Author: audoban <audoban@openmailbox.org>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU Library General Public License as
*   published by the Free Software Foundation; either version 2 or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details
*
*   You should have received a copy of the GNU Library General Public
*   License along with this program; if not, write to the
*   Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QColor>

#include <Plasma>

#include "ui_generalconfig.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget ( QWidget* parent );
    virtual ~GeneralWidget();

public:
    inline int compactStyle() const
    {
        Q_ASSERT ( m_ui.kcfg_CompactStyle->currentIndex() >= 0
                   && m_ui.kcfg_CompactStyle->currentIndex() <= 2 );
        return m_ui.kcfg_CompactStyle->currentIndex();
    }

    inline int buttonsAppearance() const
    {
        return m_ui.kcfg_Flat->isChecked() ? 0 : 1;
    }

    inline bool flat() const
    {
        return m_ui.kcfg_Flat->isChecked();
    }

    inline bool toolButton() const
    {
        return m_ui.kcfg_ToolButton->isChecked();
    }

    inline bool showStop() const
    {
        return m_ui.kcfg_ShowStop->isChecked();
    }

    inline int coverSize() const
    {
        Q_ASSERT ( m_ui.kcfg_CoverSize->value() >= 2
                   && m_ui.kcfg_CoverSize->value() <= 5 );
        return m_ui.kcfg_CoverSize->value();
    }

    inline int backgroundHint() const
    {
        if ( m_ui.kcfg_CustomColors->isChecked() ) {
            return 0;
        } else if ( m_ui.kcfg_Normal->isChecked() ) {
            return 1;
        }
        return 2;
    }

    inline bool customColors() const
    {
        return m_ui.kcfg_CustomColors->isChecked();
    }

    inline QColor frontColor() const
    {
        return m_ui.kcfg_FrontColor->color();
    }

    inline QColor backgroundColor() const
    {
        return m_ui.kcfg_BackgroundColor->color();
    }

    inline bool normal() const
    {
        return m_ui.kcfg_Normal->isChecked();
    }

    inline bool translucent() const
    {
        return m_ui.kcfg_Translucent->isChecked();
    }

Q_SIGNALS:
    void frontColorChanged ( const QColor& color );
    void backgroundColorChanged ( const QColor& color );

private:
    mutable Ui::GeneralWidget m_ui;
};

#endif // GENERALWIDGET_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
