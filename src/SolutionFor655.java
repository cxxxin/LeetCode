/**
 * 655. 输出二叉树
 * 思路：DFS2次，一次获取高度height，一次放数据
 */

import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.List;

public class SolutionFor655 {
    int height = 0;
    int m, n;
    List<List<String>> res;

    public List<List<String>> printTree(TreeNode root) {
        dfsForHeight(root, 0);
        m = height+1;
        n = (1<<(height+1))-1;
        res = new ArrayList<>();
        for (int i=0;i<m;i++){
            List<String> cur = new ArrayList<>();
            for (int j=0;j<n;j++){
                cur.add("");
            }
            res.add(cur);
        }
        dfsForMatrix(root, 0, (n-1)/2);

        return res;
    }

    // get height
    void dfsForHeight(TreeNode node, int depth){
        if (node == null){
            return;
        }

        height = Math.max(height, depth);
        dfsForHeight(node.left, depth+1);
        dfsForHeight(node.right, depth+1);
    }

    // put num into matrix
    void dfsForMatrix(TreeNode node, int x, int y){
        if (node == null)
            return;

        res.get(x).set(y, String.valueOf(node.val));
        dfsForMatrix(node.left, x+1, y - (1 << (height - x - 1)));
        dfsForMatrix(node.right, x+1, y + (1 << (height - x - 1)));
    }
}
