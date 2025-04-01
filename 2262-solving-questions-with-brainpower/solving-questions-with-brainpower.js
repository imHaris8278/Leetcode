var mostPoints = function(questions)
{
    let n = questions.length;
    let dp = new Array(n + 1).fill(0);

    for (let i = n - 1; i >= 0; i--)
    {
        let points = questions[i][0];
        let skip = questions[i][1];
        let solve = points + (i + skip + 1 < n ? dp[i + skip + 1] : 0);
        let skipQuestion = dp[i + 1];
        dp[i] = Math.max(solve, skipQuestion);
    }

    return dp[0];
};