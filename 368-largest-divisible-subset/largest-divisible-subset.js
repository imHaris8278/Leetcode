var largestDivisibleSubset = function(nums)
{
    const n = nums.length;
    if (n <= 1)
    {
        return nums;
    }

    nums.sort((a, b) => a - b);
    const dp = new Array(n).fill(1);
    const prev = new Array(n).fill(-1);
    let maxIndex = 0;

    for (let i = 1; i < n; ++i)
    {
        for (let j = 0; j < i; ++j)
        {
            if (nums[i] % nums[j] === 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }

        if (dp[i] > dp[maxIndex])
        {
            maxIndex = i;
        }
    }

    const result = [];
    while (maxIndex !== -1)
    {
        result.push(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    return result.reverse();
};