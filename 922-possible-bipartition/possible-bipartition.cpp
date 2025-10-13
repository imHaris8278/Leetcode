class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(n + 1);

        for (auto& d : dislikes)
        {
            int a = d[0], b = d[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> color(n + 1, -1);

        function<bool(int, int)> dfs = [&](int person, int col)
        {
            color[person] = col;
            for (int neighbor : graph[person])
            {
                if (color[neighbor] == -1)
                {
                    if (!dfs(neighbor, 1 - col))
                    {
                        return false;
                    }
                } else if (color[neighbor] == col)
                {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 0))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};