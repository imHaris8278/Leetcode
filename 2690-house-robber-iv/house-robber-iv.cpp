class Solution {
    bool isPossible(int maxCapability, int k, vector<int>& nums) 
    {
        int prevPrevMax = 0;
        int prevMax = 0;

        if (nums[0] <= maxCapability)
        {
            prevMax = 1;
        }

        int n = nums.size();
        for (int i = 1; i < n; i++) 
        {
            int currentMax = prevMax;
            if (nums[i] <= maxCapability) 
            {
                currentMax = max(prevPrevMax + 1, prevMax);
            }
            
            if (currentMax >= k)
            {
                return true;
            }

            prevPrevMax = prevMax;
            prevMax = currentMax;
        }

        return max(prevPrevMax, prevMax) >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) {  

        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        int left = 0, right = n - 1;
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (isPossible(sortedNums[mid], k, nums)) 
            {
                right = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        
        return sortedNums[left];
    }
};
