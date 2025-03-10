var numWays = function(words, target)
{
    const mod = 1e9 + 7;
    const m = words.length;
    const n = words[0].length;
    const freq = Array.from({ length: n }, () => Array(26).fill(0));
    
    for (let j = 0; j < n; j++)
    {
        for (let i = 0; i < m; i++)
        {
            freq[j][words[i].charCodeAt(j) - 97]++;
        }
    }
    
    const dp = Array(target.length + 1).fill(0);
    dp[0] = 1;
    
    for (let j = 0; j < n; j++)
    {
        for (let i = target.length; i > 0; i--)
        {
            dp[i] += dp[i-1] * freq[j][target.charCodeAt(i-1) - 97];
            dp[i] %= mod;
        }
    }
    
    return dp[target.length];
};