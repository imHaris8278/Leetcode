class Solution
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                pos[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowPainted(m, 0), colPainted(n, 0);
        for (int i = 0; i < arr.size(); ++i)
        {
            auto [r, c] = pos[arr[i]];
            rowPainted[r]++;
            colPainted[c]++;
            if (rowPainted[r] == n || colPainted[c] == m)
            {
                return i;
            }
        }
        
        return -1;
    }
};