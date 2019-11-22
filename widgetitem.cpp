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

        // There is no way of knowing when the widget has finished drawing (or is there?),
        // so we just try updating again after a while.
        QTimer::singleShot(30, this, [this]() {
            update();
        });
    }
}

void WidgetItem::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_widget) {
        QCoreApplication::sendEvent(m_widget, event);
        update();

        // see above
        QTimer::singleShot(30, this, [this]() {
            update();
        });
    }
}
