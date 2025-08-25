class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<double> pre(n + 1, 0.0);
        for (int i = 0; i < n; ++i)
        {
            pre[i + 1] = pre[i] + nums[i];
        }

        auto avg = [&](int l, int r) -> double {
            return (pre[r] - pre[l]) / (r - l);
        };

        vector<vector<double>> dp(k + 1, vector<double>(n + 1, 0.0));

        for (int i = 1; i <= n; ++i)
        {
            dp[1][i] = avg(0, i);
        }

        for (int g = 2; g <= k; ++g)
        {
            for (int i = g; i <= n; ++i)
            {
                double best = 0.0;
                for (int j = g - 1; j < i; ++j)
                {
                    best = max(best, dp[g - 1][j] + avg(j, i));
                }
                
                dp[g][i] = best;
            }
        }

        return dp[k][n];
    }
};