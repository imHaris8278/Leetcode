/**
 * @param {number} buckets
 * @param {number} minutesToDie
 * @param {number} minutesToTest
 * @return {number}
 */
var poorPigs = function(buckets, minutesToDie, minutesToTest)
{
    const rounds = Math.floor(minutesToTest / minutesToDie);
    let pigs = 0;

    while (Math.pow(rounds + 1, pigs) < buckets)
    {
        pigs++;
    }

    return pigs;
};