class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int maxProd = nums[0];
        int currMaxProd = nums[0];
        int currMinProd = nums[0];
        
        for (int i = 1; i < n; i++) {
            int tempMax = currMaxProd;
            currMaxProd = max({nums[i], nums[i] * currMaxProd, nums[i] * currMinProd});
            currMinProd = min({nums[i], nums[i] * tempMax, nums[i] * currMinProd});
            maxProd = max(maxProd, currMaxProd);
        }
        return maxProd;
    }
};