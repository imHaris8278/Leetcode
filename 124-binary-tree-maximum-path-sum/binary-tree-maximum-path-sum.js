/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) 
{
    let maxSum = -Infinity;

    const dfs = (node) => {
        if (node === null) 
        {
            return 0;
        }

        let leftMax = Math.max(dfs(node.left), 0);
        let rightMax = Math.max(dfs(node.right), 0);

        let currentMaxPath = node.val + leftMax + rightMax;

        maxSum = Math.max(maxSum, currentMaxPath);

        return node.val + Math.max(leftMax, rightMax);
    };

    dfs(root);
    
    return maxSum;
};
