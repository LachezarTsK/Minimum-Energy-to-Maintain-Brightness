
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
using namespace std;

class Solution {

    static const int BRIGHTNESS_PER_BULB = 3;

public:
    long long minEnergy(int numberOfLightBulbs, int targetBrightness, vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const auto& x, const auto& y) {return x[0] < y[0]; });
        long long totalActiveTime = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                continue;
            }
            totalActiveTime += end - start + 1;
            start = intervals[i][0];
            end = intervals[i][1];
        }
        totalActiveTime += end - start + 1;
        int numberOfBulbsForTargetBrightness = ceil(static_cast<double>(targetBrightness) / BRIGHTNESS_PER_BULB);

        return totalActiveTime * numberOfBulbsForTargetBrightness;
    }
};
