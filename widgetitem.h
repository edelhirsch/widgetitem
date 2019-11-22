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

#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QQuickPaintedItem>
#include <QWidget>
#include <QPointer>

class WidgetItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    WidgetItem(QQuickItem* parent = nullptr);

    void setWidget(QWidget* widget);

    virtual void paint(QPainter* painter) override;

protected:

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QPointer<QWidget> m_widget;
};

#endif // WIDGETITEM_H
