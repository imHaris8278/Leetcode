/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) 
{
    let totalSum = 0;
    let n = nums.length;
    let totalSubsets = 1 << n;

    for (let i = 0; i < totalSubsets; i++) 
    {
        let currentXOR = 0;
        for (let j = 0; j < n; j++) 
        {
            if (i & (1 << j)) 
            {
                currentXOR ^= nums[j];
            }
        }
        
        totalSum += currentXOR;
    }

    return totalSum;
};