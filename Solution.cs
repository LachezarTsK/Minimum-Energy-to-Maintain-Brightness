
public class Solution
{
    private static readonly int BRIGHTNESS_PER_BULB = 3;

    public long MinEnergy(int numberOfLightBulbs, int targetBrightness, int[][] intervals)
    {
        Array.Sort(intervals, (x, y) => x[0] - y[0]);
        long totalActiveTime = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.Length; ++i)
        {
            if (intervals[i][0] <= end)
            {
                end = Math.Max(end, intervals[i][1]);
                continue;
            }
            totalActiveTime += end - start + 1;
            start = intervals[i][0];
            end = intervals[i][1];
        }
        totalActiveTime += end - start + 1;
        int numberOfBulbsForTargetBrightness = (int)Math.Ceiling((double)targetBrightness / BRIGHTNESS_PER_BULB);

        return totalActiveTime * numberOfBulbsForTargetBrightness;
    }
}
