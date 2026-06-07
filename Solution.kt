
import kotlin.math.ceil
import kotlin.math.max

class Solution {

    private companion object {
        const val BRIGHTNESS_PER_BULB = 3
    }

    fun minEnergy(numberOfLightBulbs: Int, targetBrightness: Int, intervals: Array<IntArray>): Long {
        intervals.sortWith() { x, y -> x[0] - y[0] }
        var totalActiveTime: Long = 0
        var start = intervals[0][0]
        var end = intervals[0][1]

        for (i in 1..<intervals.size) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1])
                continue
            }
            totalActiveTime += end - start + 1
            start = intervals[i][0]
            end = intervals[i][1]
        }
        totalActiveTime += end - start + 1
        val numberOfBulbsForTargetBrightness = ceil(targetBrightness.toDouble() / BRIGHTNESS_PER_BULB).toInt()

        return totalActiveTime * numberOfBulbsForTargetBrightness
    }
}
