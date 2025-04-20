class Solution
{
public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int, int> count;
        int result = 0;
        
        for (int a : answers)
        {
            count[a]++;
        }
        
        for (auto [x, freq] : count)
        {
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize;
            result += groups * groupSize;
        }
        
        return result;
    }
};