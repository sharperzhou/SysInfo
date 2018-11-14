#include "memorywidget.h"

#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QLinearGradient>
#include <QPen>

#include "sysinfo.h"

using namespace QtCharts;

const int CHART_X_RANGE_COUNT = 100;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;
const int COLOR_DARK_BLUE = 0x209fdf;
const int COLOR_LIGHT_BLUE = 0xbfdfef;
const int PEN_WIDTH = 3;

MemoryWidget::MemoryWidget(QWidget* parent/* = nullptr*/)
    :SysInfoWidget (parent),
      series_(new QLineSeries(this)),
      pointPosX(0)
{
    QPen pen(COLOR_DARK_BLUE);
    pen.setWidth(PEN_WIDTH);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(1.0, COLOR_DARK_BLUE);
    gradient.setColorAt(0.0, COLOR_LIGHT_BLUE);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    auto areaSeries = new QAreaSeries(series_);
    areaSeries->setPen(pen);
    areaSeries->setBrush(gradient);

    auto chart = chartView().chart();
    chart->addSeries(areaSeries);
    chart->setTitle(tr("Memory used"));
    chart->createDefaultAxes();
    chart->axisX()->setVisible(false);
    chart->axisX()->setRange(0, CHART_X_RANGE_MAX);
    chart->axisY()->setRange(0, 100);
}

void MemoryWidget::updateSeries()
{
    double memoryUsed = SysInfo::instance().memoryUsed();
    series_->append(pointPosX++, memoryUsed);

    if (series_->count() > CHART_X_RANGE_COUNT) {
        QChart* chart = chartView().chart();
        chart->scroll(chart->plotArea().width() / CHART_X_RANGE_MAX, 0);

        series_->remove(0);
    }
}
