/**
 * 1161. 最大层内元素和
 * 给你一个二叉树的根节点root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
 * 请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中最小 的那个。
 *
 * 思路：
 * 层序遍历
 */

import java.util.ArrayDeque;
import java.util.Deque;

public class SolutionFor1161 {
    public int maxLevelSum(TreeNode root) {
        Deque<TreeNode> que = new ArrayDeque<>();
        que.addLast(root);
        int maxSum = Integer.MIN_VALUE;
        int ans = -1;
        int level = 1;
        while(!que.isEmpty()){
            int n = que.size();
            int cnt = 0;
            for(int i=0;i<n;i++){
                TreeNode node = que.getFirst();
                cnt += node.val;
                que.removeFirst();
                if(node.left!=null){
                    que.addLast(node.left);
                }
                if(node.right!=null){
                    que.addLast(node.right);
                }
            }
            if(cnt > maxSum){
                maxSum = cnt;
                ans = level;
            }
            level++;
        }
        return ans;
    }
}
