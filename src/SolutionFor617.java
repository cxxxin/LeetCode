/**
 * 617. 合并二叉树
 * 思路：dfs
 */

public class SolutionFor617 {
    class Solution {
        public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
            return dfs(root1,root2);
        }

        TreeNode dfs(TreeNode node1, TreeNode node2){
            if (node1==null && node2==null){ // 两个节点都为空，合并也为空
                return null;
            }

            if (node1!=null && node2!=null){ // 都不为空，需要合并
                TreeNode curr = new TreeNode();
                curr.val = node1.val+node2.val;
                curr.left = dfs(node1.left, node2.left);
                curr.right = dfs(node1.right, node2.right);
                return curr;
            }

            if (node1==null)
                return node2;
            else return node1;
        }
    }
}
