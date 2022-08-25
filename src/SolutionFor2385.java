/**
 * 2385. 感染二叉树需要的总时间
 * 思路：dfs  对于起始结点，若该结点是一棵树的根结点，那么该结点感染整棵树所需时间为树的高度
 */

public class SolutionFor2385 {
    class Solution {
        int maxTime = 0;
        int depth = -1;
        public int amountOfTime(TreeNode root, int start) {
            dfs(root, start, 0);
            return maxTime;
        }

        int dfs(TreeNode node, int start, int level){
            if (node==null)
                return 0;

            if (node.val == start) // 从这里开始
                depth = level;

            int l = dfs(node.left, start, level+1);
            boolean inLeft = depth!=-1;
            int r = dfs(node.right, start, level+1);
            if (node.val==start)
                maxTime = Math.max(maxTime, Math.max(l,r)); // 树高
            if (inLeft)
                maxTime = Math.max(maxTime, depth-level+r); // 右子树的树高+污染节点到当前节点的距离
            else
                maxTime = Math.max(maxTime, depth-level+l);

            return Math.max(l,r)+1; // 树高
        }
    }
}


