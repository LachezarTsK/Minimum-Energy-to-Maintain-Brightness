
package main

import (
    "math"
    "slices"
)

const BRIGHTNESS_PER_BULB = 3

func minEnergy(numberOfLightBulbs int, targetBrightness int, intervals [][]int) int64 {
    slices.SortFunc(intervals, func(first []int, second []int) int { return first[0] - second[0] })
    var totalActiveTime int64 = 0
    start := intervals[0][0]
    end := intervals[0][1]

    for i := 1; i < len(intervals); i++ {
        if intervals[i][0] <= end {
            end = max(end, intervals[i][1])
            continue
        }
        totalActiveTime += int64(end - start + 1)
        start = intervals[i][0]
        end = intervals[i][1]
    }
    totalActiveTime += int64(end - start + 1)
    numberOfBulbsForTargetBrightness := int64(math.Ceil(float64(targetBrightness) / BRIGHTNESS_PER_BULB))

    return totalActiveTime * numberOfBulbsForTargetBrightness
}
