class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> answer(n, -1);
        
        for (auto& r : richer)
        {
            int a = r[0], b = r[1];
            graph[b].push_back(a);
        }
        
        function<int(int)> dfs = [&](int person)
        {
            if (answer[person] != -1)
            {
                return answer[person];
            }
            
            answer[person] = person;
            
            for (int richerPerson : graph[person])
            {
                int quietest = dfs(richerPerson);
                if (quiet[quietest] < quiet[answer[person]])
                {
                    answer[person] = quietest;
                }
            }
            
            return answer[person];
        };
        
        for (int i = 0; i < n; i++)
        {
            dfs(i);
        }
        
        return answer;
    }
};