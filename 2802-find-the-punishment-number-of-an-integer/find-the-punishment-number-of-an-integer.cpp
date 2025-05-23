class Solution {
public:
    bool findPartitions(int startIndex, int sum, string stringNum, int target, vector<vector<int>>& memo)
    {
        if (startIndex == stringNum.size())
        {
            return sum == target;
        }

        if (sum > target)
        {
            return false;
        }

        if (memo[startIndex][sum] != -1)
        {
            return memo[startIndex][sum];
        }

        bool partitionFound = false;

        for (int currentIndex = startIndex; currentIndex < stringNum.size(); currentIndex++)
        {
            string currentString = stringNum.substr(startIndex, currentIndex - startIndex + 1);
            int addend = stoi(currentString);

            partitionFound = partitionFound || findPartitions(currentIndex + 1, sum + addend,
 stringNum, target, memo);
            
            if (partitionFound == true)
            {
                return true;
            }
        }

        return memo[startIndex][sum] = partitionFound;
    }

    int punishmentNumber(int n)
    {
        int punishmentNum = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++)
        {
            int squareNum = currentNum * currentNum;
            string stringNum = to_string(squareNum);

            vector<vector<int>> memoArray(stringNum.size(), vector<int>(currentNum + 1, -1));

            if (findPartitions(0, 0, stringNum, currentNum, memoArray))
            {
                punishmentNum += squareNum;
            }
        }
        
        return punishmentNum;
    }
};