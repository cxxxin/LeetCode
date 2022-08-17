import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 1302. 层数最深叶子节点的和
 * 思路：层序遍历
 */

public class SolutionFor1302 {
    public int deepestLeavesSum(TreeNode root) {
        Deque<TreeNode> que = new ArrayDeque<TreeNode>();
        int res = 0;
        que.addLast(root);
        while (!que.isEmpty()){
            int n = que.size();
            res = 0;
            for (int i=0;i<n;i++){
                TreeNode curr = que.removeFirst();
                res += curr.val;
                if (curr.left!=null){
                    que.addLast(curr.left);
                }
                if (curr.right!=null){
                    que.addLast(curr.right);
                }
            }
        }

        return res;
    }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */