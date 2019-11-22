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
