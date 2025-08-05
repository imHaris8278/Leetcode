class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> left_max(n), right_min(n + 1);

        left_max[0] = arr[0];
        for (int i = 1; i < n; ++i)
        {
            left_max[i] = max(left_max[i - 1], arr[i]);
        }

        right_min[n] = INT_MAX;
        for (int i = n - 1; i >= 0; --i)
        {
            right_min[i] = min(right_min[i + 1], arr[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; ++i)
        {
            if (left_max[i] <= right_min[i + 1])
            {
                ++chunks;
            }
        }

        return chunks;
    }
};