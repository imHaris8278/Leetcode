class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int requiredNum = target - nums[i];

            if (mp.count(requiredNum))
            {
                return {mp[requiredNum], i};
            }

            if (!mp.count(nums[i]))
            {
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};