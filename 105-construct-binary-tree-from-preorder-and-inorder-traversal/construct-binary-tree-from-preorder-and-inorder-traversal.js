/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) 
{
    if (preorder.length === 0 || inorder.length === 0) 
    {
        return null;
    }

    const rootVal = preorder[0];
    const root = new TreeNode(rootVal);

    const rootIndexInInorder = inorder.indexOf(rootVal);

    const leftInorder = inorder.slice(0, rootIndexInInorder);
    const rightInorder = inorder.slice(rootIndexInInorder + 1);

    const leftPreorder = preorder.slice(1, leftInorder.length + 1);
    const rightPreorder = preorder.slice(leftInorder.length + 1);

    root.left = buildTree(leftPreorder, leftInorder);
    root.right = buildTree(rightPreorder, rightInorder);

    return root;
};