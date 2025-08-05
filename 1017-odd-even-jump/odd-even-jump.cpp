class Solution {
public:
    int oddEvenJumps(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> nextHigher(n, -1);
        vector<int> nextLower(n, -1);

        auto makeMonotonicStack = [&](vector<int>& indices, vector<int>& result)
        {
            stack<int> s;
            for (int i : indices)
            {
                while (!s.empty() && i > s.top())
                {
                    result[s.top()] = i;
                    s.pop();
                }

                s.push(i);
            }
        };

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return arr[a] == arr[b] ? a < b : arr[a] < arr[b];
        });

        makeMonotonicStack(idx, nextHigher);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return arr[a] == arr[b] ? a < b : arr[a] > arr[b];
        });

        makeMonotonicStack(idx, nextLower);
        vector<bool> canReachOdd(n, false), canReachEven(n, false);
        canReachOdd[n - 1] = canReachEven[n - 1] = true;

        for (int i = n - 2; i >= 0; --i)
        {
            if (nextHigher[i] != -1)
            {
                canReachOdd[i] = canReachEven[nextHigher[i]];
            }

            if (nextLower[i] != -1)
            {
                canReachEven[i] = canReachOdd[nextLower[i]];
            }
        }

        return count(canReachOdd.begin(), canReachOdd.end(), true);
    }
};