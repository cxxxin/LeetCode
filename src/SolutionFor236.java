import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * 236. 二叉树的最近公共祖先
 * 思路：遍历+记录父节点
 */

public class SolutionFor236 {
    Map<TreeNode, TreeNode> map = new HashMap<>();

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Set<TreeNode> visited = new HashSet<>();

        dfs(root);
        // 找p的父节点
        while (p != root){
            visited.add(p);
            p = map.get(p);
        }

        // 找q的父节点
        while (q!=root){
            if (visited.contains(q))
                return q;
            q = map.get(q);
        }

        return root;
    }

    private void dfs(TreeNode node){
        if (node.left != null){
            map.put(node.left, node);
            dfs(node.left);
        }
        if (node.right != null){
            map.put(node.right, node);
            dfs(node.right);
        }
    }
}
