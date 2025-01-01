var sortColors = function(nums)
{
    let zeroIndex = 0, oneIndex = 0, twoIndex = nums.length - 1;

    while (oneIndex <= twoIndex)
    {
        if (nums[oneIndex] === 0)
        {
            [nums[zeroIndex], nums[oneIndex]] = [nums[oneIndex], nums[zeroIndex]];
            zeroIndex++;
            oneIndex++;
        }
        else if (nums[oneIndex] === 1)
        {
            oneIndex++;
        }
        else
        {
            [nums[oneIndex], nums[twoIndex]] = [nums[twoIndex], nums[oneIndex]];
            twoIndex--;
        }
    }
};