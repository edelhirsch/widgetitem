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

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <widgetitem.h>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<WidgetItem>("WidgetItem", 1, 0, "WidgetItem");

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    WidgetItem* widgetItem = nullptr;

    QPushButton button("good old push button");

    // Could we move this inside WidgetItem?
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     [&button, &widgetItem](QObject* object, const QUrl /*&url*/) {
        widgetItem = object->findChild<WidgetItem*>();
        Q_ASSERT(widgetItem);
        widgetItem->setWidget(&button);
    });

    engine.load(url);

    return app.exec();
}
