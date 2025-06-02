class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() > 1)
        {
            std::sort(stones.begin(), stones.end());
            int n = stones.size();
            int x = stones[n - 1], y = stones[n - 2];

            if (x == y)
            {
                stones.resize(n - 2);
            }
            else
            {
                stones[n - 2] = x - y;
                stones.resize(n - 1);
            }
        }
        
        return stones.size() > 0 ? stones[0] : 0;
    }
};