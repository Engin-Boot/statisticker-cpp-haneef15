#include <vector>

struct Stats
{
    double average, min, max;
    void ComputeAverage(const std::vector<double>&);
    void ComputeMax(const std::vector<double>&);
    void ComputeMin(const std::vector<double>&);
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<double>&);
}
