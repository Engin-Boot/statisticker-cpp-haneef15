#include "stats.h"
#include <math.h>
#include <algorithm>

Stats Statistics::ComputeStatistics(const std::vector<double>& sample) {
    Stats stats_obj;
    stats_obj.ComputeAverage(sample);
    stats_obj.ComputeMax(sample);
    stats_obj.ComputeMin(sample);
    return stats_obj;
}

std::vector<double> RemoveNaNElements(const std::vector<double>& sample)
{
    std::vector<double> nan_filtered_sample;
    for(double element : sample)
    {
        if(!isnan(element)) nan_filtered_sample.push_back(element);
    }
    return nan_filtered_sample;
}

void Stats::ComputeAverage(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::average = (double)NAN;
    }
    else
    {
        double sum = 0;
        std::vector<double> nan_filtered_sample = RemoveNaNElements(sample);
        for (double element : nan_filtered_sample)
        {
            sum += element;
        }
        Stats::average = sum / nan_filtered_sample.size();
    }
}

void Stats::ComputeMax(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::max = (double)NAN;
    }
    else
    {
        Stats::max = *std::max_element(sample.begin(), sample.end());
    }
}

void Stats::ComputeMin(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::min = (double)NAN;
    }
    else
    {
        Stats::min = *std::min_element(sample.begin(), sample.end());
    }
}
