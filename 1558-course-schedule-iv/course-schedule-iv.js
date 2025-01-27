var checkIfPrerequisite = function(numCourses, prerequisites, queries)
{
    const isPrerequisite = Array.from({ length: numCourses }, () => Array(numCourses).fill(false));
    
    for (const [u, v] of prerequisites)
    {
        isPrerequisite[u][v] = true;
    }

    for (let k = 0; k < numCourses; k++)
    {
        for (let i = 0; i < numCourses; i++)
        {
            for (let j = 0; j < numCourses; j++)
            {
                if (isPrerequisite[i][k] && isPrerequisite[k][j])
                {
                    isPrerequisite[i][j] = true;
                }
            }
        }
    }

    const result = [];
    for (const [u, v] of queries)
    {
        result.push(isPrerequisite[u][v]);
    }

    return result;
};