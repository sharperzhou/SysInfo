#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include "sysinfowidget.h"

namespace QtCharts {
    class QLineSeries;
}

class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    explicit MemoryWidget(QWidget* parent = nullptr);

    // SysInfoWidget interface
protected slots:
    void updateSeries() override;

private:
    QtCharts::QLineSeries* series_;
    qint64 pointPosX;
};

#endif // MEMORYWIDGET_H
