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

        let leftMax = Math.max(dfs(node.left), 0); // (2, 0) -> 2

        let rightMax = Math.max(dfs(node.right), 0); // (3, 0) -> 3

        let currentMaxPath = node.val + leftMax + rightMax; // 1 + 2 + 3 -> 6

        maxSum = Math.max(maxSum, currentMaxPath); // (0, 6) -> 6

        return node.val + Math.max(leftMax, rightMax); // 1 + 3 -> 4
    };

    dfs(root);

    return maxSum;
};