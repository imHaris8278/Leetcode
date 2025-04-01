class Solution
{
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;

        for (auto& meeting : meetings)
        {
            previousDay = min(previousDay, meeting[0]);
            dayMap[meeting[0]]++;
            dayMap[meeting[1] + 1]--;
        }

        freeDays += (previousDay - 1);
        for (auto& day : dayMap)
        {
            int currentDay = day.first;

            if (prefixSum == 0)
            {
                freeDays += currentDay - previousDay;
            }

            prefixSum += day.second;
            previousDay = currentDay;
        }

        freeDays += days - previousDay + 1;
        return freeDays;
    }
};