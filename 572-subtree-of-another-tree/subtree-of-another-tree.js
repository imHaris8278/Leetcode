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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) 
{
    function isIdentical(tree1, tree2) 
    {
        if (!tree1 && !tree2)
        {
            return true;
        }

        if (!tree1 || !tree2)
        {
            return false;
        }

        if (tree1.val !== tree2.val)
        {
            return false;
        }

        return isIdentical(tree1.left, tree2.left) && isIdentical(tree1.right, tree2.right);
    }

    function traverse(tree, subTree) 
    {
        if (!tree)
        {
            return false;
        }

        if (isIdentical(tree, subTree))
        {
            return true;
        }

        return traverse(tree.left, subTree) || traverse(tree.right, subTree);
    }

    if (!subRoot)
    {
        return true;
    }

    if (!root)
    {
        return false;
    }

    return traverse(root, subRoot);
};