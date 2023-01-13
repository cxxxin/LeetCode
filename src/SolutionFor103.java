import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * 103. 二叉树的锯齿形层序遍历
 * 思路：队列
 */

public class SolutionFor103 {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null)
            return new ArrayList<>();

        Deque<TreeNode>[] deque = new Deque[2];
        deque[0] = new ArrayDeque<>();
        deque[1] = new ArrayDeque<>();

        List<List<Integer>> res = new ArrayList<>();
        int direction = 0; // 从左到右还是从右到左
        deque[0].addLast(root);

        while (!(deque[0].isEmpty() && deque[1].isEmpty())) {
            int len = deque[direction].size();
            List<Integer> currLayer = new ArrayList<>();
            for (int i=0;i<len;i++){
                TreeNode node = deque[direction].pollFirst();
                currLayer.add(node.val);
                if (direction ==  0) {
                    if (node.left != null)
                        deque[1-direction].addFirst(node.left);
                    if (node.right != null)
                        deque[1-direction].addFirst(node.right);
                }
                else {
                    if (node.right != null)
                        deque[1-direction].addFirst(node.right);
                    if (node.left != null)
                        deque[1-direction].addFirst(node.left);
                }
            }
            direction = 1- direction;
            res.add(currLayer);
        }

        return res;
    }
}
