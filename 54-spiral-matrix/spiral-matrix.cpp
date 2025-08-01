class Solution {
public:
    vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        vector<int> res;

        if (matrix.empty())
        {
            return res;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

        while (top <= bottom && left <= right) 
        {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }

            top++;

            for (int i = top; i <= bottom; ++i) 
            {
                res.push_back(matrix[i][right]);
            }

            right--;

            if (top <= bottom) 
            {
                for (int i = right; i >= left; --i) 
                {
                    res.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            if (left <= right) 
            {
                for (int i = bottom; i >= top; --i) 
                {
                    res.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return res;
    }
};