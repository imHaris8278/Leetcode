/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) 
{
    const lastOccurrence = {};
    for (let i = 0; i < s.length; i++) 
    {
        lastOccurrence[s[i]] = i;
    }

    const partitions = [];
    let start = 0;
    let end = 0;

    for (let i = 0; i < s.length; i++) 
    {
        end = Math.max(end, lastOccurrence[s[i]]);
        
        if (i === end) 
        {
            partitions.push(end - start + 1);
            start = i + 1;
        }
    }

    return partitions;
};
