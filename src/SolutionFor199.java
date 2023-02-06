import java.util.*;

/**
 * 199. 二叉树的右视图
 * 思路：层序遍历只取最右
 */

public class SolutionFor199 {
    public List<Integer> rightSideView(TreeNode root) {
        Deque<TreeNode> que = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        que.addLast(root);
        while (!que.isEmpty()) {
            int n = que.size();
            int currLayer = -1;
            for (int i=0;i<n;i++){
                TreeNode node = que.pollFirst();
                if (node.left != null)
                    que.addLast(node.left);
                if (node.right != null)
                    que.addLast(node.right);
                currLayer = node.val;
            }
            res.add(currLayer);
        }
        return res;
    }
}
