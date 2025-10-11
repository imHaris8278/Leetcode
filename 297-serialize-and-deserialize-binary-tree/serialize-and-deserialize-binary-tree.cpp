class Codec {
public:
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