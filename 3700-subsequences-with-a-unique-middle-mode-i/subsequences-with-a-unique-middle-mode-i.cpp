
#define int64 long long
const int64 MOD = 1e9 + 7;

class Solution
{
private:
    int64 chooseTwo(int64 n)
    {
        return n * (n - 1) / 2;
    }

public:
    int subsequencesWithMiddleMode(vector<int>& nums)
    {
        int N = nums.size();
        int64 ans = 0;
        unordered_map<int, int> lfreq, rfreq;
        int64 rightSquaredSum = 0, leftSquaredSum = 0;
        
        for (int i = 0; i < N; i++)
        {
            if (i < 2)
            {
                lfreq[nums[i]]++;
            }
            else
            {
                rfreq[nums[i]]++;
            }
        }

        for (auto [_, f] : rfreq)
        {
            rightSquaredSum += f * f;
        }
        
        for (auto [_, f] : lfreq)
        {
            leftSquaredSum += f * f;
        }
        
        for (int i = 2; i < N - 2; i++)
        {
            rightSquaredSum -= rfreq[nums[i]] * rfreq[nums[i]];
            rfreq[nums[i]]--;
            int lf = lfreq[nums[i]], rf = rfreq[nums[i]];
            rightSquaredSum += rf * rf;
            int64 leftTerm = lf * (i - lf);
            int64 rightTerm = rf * (N - i - 1 - rf);
            ans = (ans + leftTerm * rightTerm) % MOD;
            int64 coef = chooseTwo(lf);
            int64 val = chooseTwo(N - i - 1) - chooseTwo(rf);
            ans = (ans + coef * val) % MOD;
            coef = chooseTwo(rf);
            val = chooseTwo(i) - chooseTwo(lf);
            ans = (ans + coef * val) % MOD;
            int64 cand = chooseTwo(lf) * chooseTwo(rf) % MOD;
            ans = (ans + cand) % MOD;

            for (int j = 0; j < N; j++)
            {
                if (nums[i] == nums[j])
                {
                    continue;
                }

                int lfj = lfreq[nums[j]], rfj = rfreq[nums[j]];
                
                if (j < i)
                {
                    int64 rightSum = N - i - 1 - rf - rfj;
                    int64 squaredSumCorrected = rightSquaredSum - rf * rf - rfj * rfj;
                    int64 cand = ((rightSum * rightSum - squaredSumCorrected) / 2) % MOD;
                    int64 totalCand = lf * cand % MOD;
                    ans = (ans + totalCand) % MOD;
                }
                else
                {
                    int64 leftSum = i - lf - lfj;
                    int64 squaredSumCorrected = leftSquaredSum - lf * lf - lfj * lfj;
                    int64 cand = ((leftSum * leftSum - squaredSumCorrected) / 2) % MOD;
                    int64 totalCand = rf * cand % MOD;
                    ans = (ans + totalCand) % MOD;
                }
            }

            leftSquaredSum -= lf * lf;
            lfreq[nums[i]]++;
            leftSquaredSum += lfreq[nums[i]] * lfreq[nums[i]];
        }
        
        return ans;
    }
};