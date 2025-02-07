class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        unordered_map<int, int> ballColorMap;

        for (int i = 0; i < n; i++)
        {
            int ball = queries[i][0], color = queries[i][1];

            if (ballColorMap.find(ball) != ballColorMap.end())
            {
                int prevColor = ballColorMap[ball];
                colorMap[prevColor]--;

                if (colorMap[prevColor] == 0)
                {
                    colorMap.erase(prevColor);
                }
            }

            ballColorMap[ball] = color;
            colorMap[color]++;
            result[i] = colorMap.size();
        }

        return result;
    }
};