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
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root, nullptr, nullptr);
    }

    bool isValidBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if (root == nullptr)
        {
            return true;
        }

        if ((minNode != nullptr && root->val <= minNode->val) || (maxNode != nullptr && root->val >= maxNode->val))
        {
            return false;
        }

        return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
    }
};