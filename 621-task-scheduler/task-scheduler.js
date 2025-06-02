/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function(tasks, n) 
{
    const taskCounts = new Map();

    for (const task of tasks) 
    {
        taskCounts.set(task, (taskCounts.get(task) || 0) + 1);
    }
    
    let maxCount = 0;
    
    for (const count of taskCounts.values()) 
    {
        maxCount = Math.max(maxCount, count);
    }
    
    let maxCountTasks = 0;

    for (const count of taskCounts.values()) 
    {
        if (count === maxCount) 
        {
            maxCountTasks++;
        }
    }
    
    const partCount = maxCount - 1;
    const partLength = n - (maxCountTasks - 1);
    const emptySlots = partCount * partLength;
    const availableTasks = tasks.length - maxCount * maxCountTasks;
    const idles = Math.max(0, emptySlots - availableTasks);
    
    return tasks.length + idles;
};