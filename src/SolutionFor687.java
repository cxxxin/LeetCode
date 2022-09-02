/**
 * 687. 最长同值路径
 */

public class SolutionFor687 {
    class Solution {
        int res;
        public int longestUnivaluePath(TreeNode root) {
            res = 0;
            dfs(root);
            return res;
        }

        public int dfs(TreeNode node){
            if (node == null)
                return 0;

            int left = dfs(node.left), right = dfs(node.right); // left表示左边的边长  right表示右边的最长边长
            int left1 = 0, right1 = 0;
            if (node.left != null && node.left.val == node.val){ // 左边
                left1 = left+1;
            }
            if (node.right != null && node.right.val == node.val){
                right1 = right+1;
            }
            res = Math.max(res, left1 + right1);
            return Math.max(left1, right1); // 子路径中比较长的那条
        }
    }
}
