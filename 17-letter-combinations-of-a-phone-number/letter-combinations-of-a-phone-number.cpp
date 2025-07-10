class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;

        if (digits.empty())
        {
            return result;
        }

        vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string current = "";

        letterCombinationsHelper(digits, result, mapping, current, 0);

        return result;
    }

private:
    void letterCombinationsHelper(const string& digits, vector<string>& result, vector<string>& mapping, string& current, int index)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters)
        {
            current.push_back(c);

            letterCombinationsHelper(digits, result, mapping, current, index + 1);

            current.pop_back();
        }
    }
};