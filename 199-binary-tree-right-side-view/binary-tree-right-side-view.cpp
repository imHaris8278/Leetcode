/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }
        
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) 
        {
            int size = levelQueue.size();

            for (int i = 0; i < size; ++i) 
            {
                TreeNode* currentNode = levelQueue.front();
                levelQueue.pop();

                if (i == size - 1) 
                {
                    result.push_back(currentNode->val);
                }

                if (currentNode->left)
                {
                    levelQueue.push(currentNode->left);
                }

                if (currentNode->right)
                {
                    levelQueue.push(currentNode->right);
                }
            }
        }

        return result;
    }
};