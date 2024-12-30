var countGoodStrings = function(low, high, zero, one)
{
    const MOD = 10**9 + 7;
    const memo = {};

    function count(length)
    {
        if (length > high)
        {
            return 0;
        }

        if (memo[length] !== undefined)
        {
            return memo[length];
        }

        let total = 0;

        if (length >= low)
        {
            total = 1;
        }

        total += count(length + zero);
        total += count(length + one);
        total %= MOD;
        memo[length] = total;
        return total;
    }

    return count(0);
};