import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * 102. 二叉树的层序遍历
 * 思路：层序遍历用队列广搜
 */

public class SolutionFor102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)
            return res;
        Deque<TreeNode> que = new ArrayDeque<>();
        que.addLast(root);
        while (!que.isEmpty()){
            int cnt = que.size();
            List<Integer> currLayer = new ArrayList<>();
            for (int i=0;i<cnt;i++){
                TreeNode node = que.pollFirst();
                TreeNode left = node.left;
                TreeNode right = node.right;
                if (left != null)
                    que.addLast(left);
                if (right != null)
                    que.addLast(right);
                currLayer.add(node.val);
            }
            res.add(currLayer);
        }
        return res;
    }
}
