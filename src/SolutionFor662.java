import java.util.HashMap;
import java.util.Map;

/**
 * 662. 二叉树最大宽度
 * 思路：DFS
 */

public class SolutionFor662 {
    class Solution {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int res;

        public int widthOfBinaryTree(TreeNode root) {
            dfs(root, 1, 0);
            return res;
        }

        void dfs(TreeNode node, int u, int depth){
            if (node == null) return;

            if (!mp.containsKey(depth))
                mp.put(depth, u); // 每层出现的第一个节点的编号
            res = Math.max(res, u-mp.get(depth)+1);
            u = u - mp.get(depth) + 1; // 对同层内的节点进行重新编号，使得该层最左的节点为1
            dfs(node.left, u<<1, depth+1); // 下一层
            dfs(node.right, u<<1|1, depth+1);
        }
    }
}
