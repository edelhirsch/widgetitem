/******************************************************************************
 * WidgetItem - Copyright (C) 2019 Edelhirsch Software GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *****************************************************************************/

#include "widgetitem.h"

#include <QPainter>
#include <QTimer>

WidgetItem::WidgetItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setAcceptTouchEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void WidgetItem::setWidget(QWidget *widget)
{
    m_widget = widget;
}

void WidgetItem::paint(QPainter *painter)
{
    if(m_widget) {
        m_widget->render(painter);
    }
}

void WidgetItem::mousePressEvent(QMouseEvent *event)
{
    if(m_widget) {
        QCoreApplication::sendEvent(m_widget, event);
        update();
    }
}

void WidgetItem::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_widget) {
        QCoreApplication::sendEvent(m_widget, event);
        update();
    }
}
