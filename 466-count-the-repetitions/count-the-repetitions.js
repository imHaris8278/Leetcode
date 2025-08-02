/**
 * @param {string} s1
 * @param {number} n1
 * @param {string} s2
 * @param {number} n2
 * @return {number}
 */
var getMaxRepetitions = function(s1, n1, s2, n2)
{
    if (n1 === 0)
    {
        return 0;
    }

    let s1Count = 0, s2Count = 0, index = 0;
    const recall = new Map();

    while (s1Count < n1)
    {
        for (let i = 0; i < s1.length; i++)
        {
            if (s1[i] === s2[index])
            {
                index++;
                if (index === s2.length)
                {
                    s2Count++;
                    index = 0;
                }
            }
        }

        s1Count++;

        if (!recall.has(index))
        {
            recall.set(index, [s1Count, s2Count]);
        }
        else
        {
            const [s1CountPrev, s2CountPrev] = recall.get(index);
            const loopS1Count = s1Count - s1CountPrev;
            const loopS2Count = s2Count - s2CountPrev;
            const remainingS1 = n1 - s1Count;
            const loops = Math.floor(remainingS1 / loopS1Count);
            s1Count += loops * loopS1Count;
            s2Count += loops * loopS2Count;
        }
    }

    return Math.floor(s2Count / n2);
};