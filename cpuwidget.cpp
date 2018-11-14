#include "cpuwidget.h"

#include <QtCharts/QPieSeries>

#include "sysinfo.h"

using namespace QtCharts;

CpuWidget::CpuWidget(QWidget* parent/* = nullptr*/)
    : SysInfoWidget (parent),
      series_(new QPieSeries(this))
{
    series_->setHoleSize(0.35);
    series_->append(tr("CPU Load"), 30.0);
    series_->append(tr("CPU Free"), 70.0);

    auto chart = chartView().chart();
    chart->addSeries(series_);
    chart->setTitle(tr("CPU average load"));
}

void CpuWidget::updateSeries()
{
    double cpuLoadAvg = SysInfo::instance().cpuLoadAverage();
    series_->clear();
    series_->append(tr("Load"), cpuLoadAvg);
    series_->append(tr("Free"), 100.0 - cpuLoadAvg);
}
