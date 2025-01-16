class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        vector<pair<int,int>> rx, ry;
        for (auto &r : rectangles)
        {
            rx.emplace_back(r[0], r[2]);
            ry.emplace_back(r[1], r[3]);
        }
        
        return canInsert(rx) || canInsert(ry);
    }

private:
    bool canInsert(vector<pair<int,int>>& intervals)
    {
        if (intervals.empty())
        {
            return false;
        }

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0].second);
        int partitions = 0;
        
        for (int i = 1; i < (int)intervals.size(); i++)
        {
            int start = intervals[i].first;
            int end = intervals[i].second;
        
            while (!minHeap.empty() && start >= minHeap.top())
            {
                minHeap.pop();
            }
            
            if (minHeap.empty())
            {
                partitions++;
            }
            
            minHeap.push(end);
        }
        
        return partitions >= 2;
    }
};