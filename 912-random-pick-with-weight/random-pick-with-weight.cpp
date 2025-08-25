class Solution {
private:
    vector<int> prefix;
    int total;
    mt19937 rng;
    uniform_int_distribution<int> dist;

public:
    Solution(vector<int>& w)
    {
        prefix.resize(w.size());
        partial_sum(w.begin(), w.end(), prefix.begin());
        total = prefix.back();
        rng.seed(random_device{}());
        dist = uniform_int_distribution<int>(1, total);
    }
    
    int pickIndex() {
        int target = dist(rng);
        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};