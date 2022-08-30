/**
 * 998. 最大二叉树 II
 * 思路：只找右边
 */

public class SolutionFor998 {
    class Solution {
        public TreeNode insertIntoMaxTree(TreeNode root, int val) {
            TreeNode node = new TreeNode(val);
            TreeNode prev = null, curr = root;
            while (curr != null && curr.val > val) { // 不断往下找
                prev = curr;
                curr = curr.right;
            }
            if (prev == null) { // 就是放在最顶端
                node.left = curr;
                return node;
            }
            else{
                prev.right = node;
                node.left = curr;
                return root;
            }
        }
    }
}
