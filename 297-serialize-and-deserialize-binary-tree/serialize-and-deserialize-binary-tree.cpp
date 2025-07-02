/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
        {
            return "null";
        }
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
            {
                str += "null,";
            }
            else
            {
                str += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null")
        {
            return NULL;
        }
        stringstream ss(data);
        string nodeValue;
        getline(ss, nodeValue, ',');
        TreeNode* root = new TreeNode(stoi(nodeValue));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            getline(ss, nodeValue, ',');
            if (nodeValue != "null")
            {
                node->left = new TreeNode(stoi(nodeValue));
                q.push(node->left);
            }
            getline(ss, nodeValue, ',');
            if (nodeValue != "null")
            {
                node->right = new TreeNode(stoi(nodeValue));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));