var maxCoins = function(nums) 
{
    const n = nums.length;
    const extendedNums = [1, ...nums, 1];
    const dp = Array.from({ length: n + 2 }, () => Array(n + 2).fill(0));

    for (let length = 1; length <= n; length++) 
    {
        for (let left = 1; left <= n - length + 1; left++) 
        {
            const right = left + length - 1;
            for (let k = left; k <= right; k++) 
            {
                dp[left][right] = Math.max(
                    dp[left][right],
                    dp[left][k-1] + dp[k+1][right] + extendedNums[left-1] * extendedNums[k] * extendedNums[right+1]
                );
            }
        }
    }

    return dp[1][n];
};