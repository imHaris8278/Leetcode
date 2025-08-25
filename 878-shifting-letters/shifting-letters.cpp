class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts)
    {
        long long add = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            add = (add + shifts[i]) % 26;
            int x = s[i] - 'a';
            s[i] = char('a' + (x + add) % 26);
        }
        
        return s;
    }
};