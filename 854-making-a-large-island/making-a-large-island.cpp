class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int color)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
        {
            return 0;
        }
        
        grid[i][j] = color;
        
        int area = 1;
        
        area += dfs(grid, i + 1, j, color);
        area += dfs(grid, i - 1, j, color);
        area += dfs(grid, i, j + 1, color);
        area += dfs(grid, i, j - 1, color);
        
        return area;
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int maxArea = 0;
        int color = 2;
        unordered_map<int, int> areas;
        
        for (int i = 0; i < grid.size(); ++i) 
        {
            for (int j = 0; j < grid[0].size(); ++j) 
            {
                if (grid[i][j] == 1) 
                {
                    int area = dfs(grid, i, j, color);
                    
                    maxArea = max(maxArea, area);
                    
                    areas[color] = area;
                    
                    color++;
                }
            }
        }
        
        for (int i = 0; i < grid.size(); ++i) 
        {
            for (int j = 0; j < grid[0].size(); ++j) 
            {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedColors;
                    
                    if (i > 0)
                    {
                        connectedColors.insert(grid[i - 1][j]);
                    }
                    
                    if (i < grid.size() - 1)
                    {
                        connectedColors.insert(grid[i + 1][j]);
                    }

                    if (j > 0)
                    {
                        connectedColors.insert(grid[i][j - 1]);
                    }

                    if (j < grid[0].size() - 1)
                    {
                        connectedColors.insert(grid[i][j + 1]);
                    }
                    
                    int totalArea = 1;
                    
                    for (int color : connectedColors)
                    {
                        totalArea += areas[color];
                    }
                    
                    maxArea = max(maxArea, totalArea);
                }
            }
        }
        
        return maxArea;
    }
};