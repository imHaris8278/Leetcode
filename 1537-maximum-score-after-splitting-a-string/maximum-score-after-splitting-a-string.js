var maxScore = function(s)
{
    let maxScore = 0;
    
    for (let i = 1; i < s.length; i++)
    {
        let left = s.slice(0, i);
        let right = s.slice(i);
        let score = left.split('0').length - 1 + right.split('1').length - 1;
        maxScore = Math.max(maxScore, score);
    }
    
    return maxScore;
};