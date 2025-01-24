var eventualSafeNodes = function(graph)
{
    let n = graph.length;
    let color = new Array(n).fill(0);
    
    const dfs = (node) => {
        if (color[node] !== 0)
        {
            return color[node] === 2;
        }
        
        color[node] = 1;
        for (let neighbor of graph[node])
        {
            if (color[neighbor] === 1 || !dfs(neighbor))
            {
                return false;
            }
        }
        
        color[node] = 2;
        return true;
    };
    
    let result = [];
    for (let i = 0; i < n; i++)
    {
        if (dfs(i))
        {
            result.push(i);
        }
    }
    
    return result;
};