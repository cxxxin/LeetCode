/**
 * 606. 根据二叉树创建字符串
 * 思路：dfs
 */

public class SolutionFor606 {
    class Solution {
        public String tree2str(TreeNode root) {
            if (root==null)
                return "";

            if (root.left == null && root.right == null) {
                return Integer.toString(root.val);
            }

            if (root.right==null)
                return new StringBuilder().append(root.val).append('(').append(tree2str(root.left)).append(')').toString();

            return new StringBuilder().append(root.val).append('(').append(tree2str(root.left)).append(")(")
                    .append(tree2str(root.right)).append(')').toString();
        }
    }
}
