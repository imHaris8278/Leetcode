/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) 
{
    const totalSum = nums.reduce((acc, num) => acc + num, 0);
    
    if (totalSum % 2 !== 0) 
    {
        return false;
    }
    
    const target = totalSum / 2;
    const n = nums.length;
    const dp = Array(target + 1).fill(false);
    dp[0] = true;
    
    for (let num of nums) 
    {
        for (let i = target; i >= num; i--) 
        {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    
    return dp[target];
};
