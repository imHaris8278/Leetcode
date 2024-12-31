var mincostTickets = function(days, cost)
{
    let dp = new Array(days[days.length - 1] + 1);
    dp[0] = 0;

    for (let i = 1; i < dp.length; i++)
    {
        if (!days.includes(i))
        {
        dp[i] = dp[i - 1];
        }
        else
        {
        dp[i] = Math.min(
            dp[Math.max(0, i - 1)] + cost[0],
            dp[Math.max(0, i - 7)] + cost[1],
            dp[Math.max(0, i - 30)] + cost[2]
        );
        }
    }
    
    return dp[dp.length - 1];
};