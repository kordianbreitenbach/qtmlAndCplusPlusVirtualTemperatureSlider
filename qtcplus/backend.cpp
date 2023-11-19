#include "backend.h"
#include <QTimer>
Backend::Backend(QObject *parent)
    : QObject{parent}
{
    QObject::connect(this,&Backend::updateToNumbersGenerated,this,&Backend::onUpdateToNumbersGenerated);
}

void Backend::generateNumber(int min, int temp)
{
    const int duration = 3000; // 3 seconds
    const int steps = 100; // Number of steps
    const int stepDuration = duration / steps;

    // Create a QTimer for the interpolation
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, min, temp, steps, stepDuration, timer]() {
        static int stepCount = 0;

        // Calculate the intermediate value
        int tempNumber = temp + (min - temp) * stepCount / steps;

        // Emit the intermediate value
        emit numberEmitted(tempNumber);

        // Increment the step count
        ++stepCount;

        // Stop the timer when the interpolation is complete
        if (stepCount > steps) {
            timer->stop();
            stepCount = 0;
        }
    });

    // Start the timer with the step duration
    timer->start(stepDuration);
}
void Backend::onUpdateToNumbersGenerated()
{
    qInfo()<<"Property Updatet in Backend";
}
