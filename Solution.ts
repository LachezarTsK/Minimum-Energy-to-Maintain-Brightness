
function minEnergy(numberOfLightBulbs: number, targetBrightness: number, intervals: number[][]): number {
    const BRIGHTNESS_PER_BULB = 3;

    intervals.sort((x, y) => x[0] - y[0]);
    let totalActiveTime = 0;
    let start = intervals[0][0];
    let end = intervals[0][1];

    for (let i = 1; i < intervals.length; ++i) {
        if (intervals[i][0] <= end) {
            end = Math.max(end, intervals[i][1]);
            continue;
        }
        totalActiveTime += end - start + 1;
        start = intervals[i][0];
        end = intervals[i][1];
    }
    totalActiveTime += end - start + 1;
    const numberOfBulbsForTargetBrightness = Math.ceil(targetBrightness / BRIGHTNESS_PER_BULB);

    return totalActiveTime * numberOfBulbsForTargetBrightness;
};
