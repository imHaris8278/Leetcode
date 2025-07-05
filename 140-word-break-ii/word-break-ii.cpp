class Solution
{
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    int maxLen;

    vector<string> dfs(const string& s, int start)
    {
        if (memo.count(start)) return memo[start];

        vector<string> res;
        int n = s.size();
        if (start == n)
        {
            res.push_back("");
        }
        else
        {
            for (int len = 1; len <= maxLen && start + len <= n; ++len)
            {
                string w = s.substr(start, len);
                if (dict.count(w))
                {
                    auto tails = dfs(s, start + len);
                    for (auto& tail : tails)
                    {
                        res.push_back(w + (tail.empty() ? "" : " ") + tail);
                    }
                }
            }
        }

        return memo[start] = res;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        maxLen = 0;
        for (auto& w : wordDict) maxLen = max(maxLen, (int)w.size());
        return dfs(s, 0);
    }
};