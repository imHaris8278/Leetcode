class Solution
{
public:
    int strongPasswordChecker(string password)
    {
        int n = password.size();    
        bool hasLower = false, hasUpper = false, hasDigit = false;
        int missingTypes = 3;

        for (char c : password)
        {
            if (islower(c))
            {
                hasLower = true;
            }
        
            if (isupper(c))
            {
                hasUpper = true;
            }
        
            if (isdigit(c))
            {
                hasDigit = true;
            }
        }

        if (hasLower)
        {
            missingTypes--;
        }

        if (hasUpper)
        {
            missingTypes--;
        }
        
        if (hasDigit)
        {
            missingTypes--;
        }
        
        int changeCount = 0;
        vector<int> repeats;
        
        for (int i = 2; i < n; i++)
        {
            if (password[i] == password[i-1] && password[i] == password[i-2])
            {
                int len = 2;
                while (i < n && password[i] == password[i-1])
                {
                    len++;
                    i++;
                }
                
                repeats.push_back(len);
            }
        }
        
        int totalChange = 0, totalDelete = 0;
        for (int len : repeats)
        {
            changeCount += len / 3;
        }
        
        if (n < 6)
        {
            return max(missingTypes, 6 - n);
        }
        else if (n <= 20)
        {
            return max(missingTypes, changeCount);
        }
        else
        {
            totalDelete = n - 20;
            for (int& len : repeats)
            {
                if (totalDelete <= 0)
                {
                    break;
                }
            
                if (len % 3 == 0)
                {
                    int toDelete = min(totalDelete, 1);
                    totalDelete -= toDelete;
                    len -= toDelete;
                    changeCount -= toDelete;
                }
            }

            for (int& len : repeats)
            {
                if (totalDelete <= 0)
                {
                    break;
                }

                if (len % 3 == 1)
                {
                    int toDelete = min(totalDelete, 2);
                    totalDelete -= toDelete;
                    len -= toDelete;
                    changeCount -= toDelete / 2;
                }
            }

            for (int& len : repeats)
            {
                if (totalDelete <= 0)
                {
                    break;
                }

                int toDelete = min(totalDelete, len - 2);
                totalDelete -= toDelete;
                len -= toDelete;
                changeCount -= toDelete / 3;
            }
            
            return n - 20 + max(missingTypes, changeCount);
        }
    }
};