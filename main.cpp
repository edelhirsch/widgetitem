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

//    QProgressBar progressBar;
//    progressBar.setRange(0, 100);
//    progressBar.setValue(0);

//    QTimer timer;
//    timer.setInterval(500);

//    QObject::connect(&timer, &QTimer::timeout, [&progressBar, &widgetItem]() {
//        progressBar.setValue(progressBar.value() + 1);
//        widgetItem->update();
//    });

    QPushButton button("good old push button");

    // Could we move this inside WidgetItem?
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     [&button, &widgetItem](QObject* object, const QUrl /*&url*/) {
        widgetItem = object->findChild<WidgetItem*>();
        Q_ASSERT(widgetItem);
        widgetItem->setWidget(&button);
    });

//    timer.start();

    engine.load(url);

    return app.exec();
}
