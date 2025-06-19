class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (!isValidRow(board, i))
            {
                return false;
            }
        }

        for (int j = 0; j < 9; ++j)
        {
            if (!isColumnValid(board, j))
            {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j+= 3)
            {
                if (!isValidSubGrid(board, i, j))
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidRow(vector<vector<char>> &board, int row)
    {
        unordered_set<char> seen;
        for (int j = 0; j < 9; ++j)
        {
            char digit = board[row][j];

            if (digit == '.')
            {
                continue;
            }

            if (seen.count(digit))
            {
                return false;
            }

            seen.insert(digit);
        }

        return true;
    }

    bool isColumnValid(vector<vector<char>> &board, int col)
    {
        unordered_set<char> seen;
        for (int i = 0; i < 9; ++i)
        {
            char digit = board[i][col];

            if (digit == '.')
            {
                continue;
            }

            if (seen.count(digit))
            {
                return false;
            }

            seen.insert(digit);
        }

        return true;
    }

    bool isValidSubGrid(vector<vector<char>> &board, int row, int col)
    {
        unordered_set<char> seen;
        
        for (int i = row; i < row + 3; ++i)
        {
            for (int j = col; j < col + 3; ++j)
            {
                char digit = board[i][j];

                if (digit == '.')
                {
                    continue;
                }

                if (seen.count(digit))
                {
                    return false;
                }

                seen.insert(digit);
            }
        }

        return true;
    }
};