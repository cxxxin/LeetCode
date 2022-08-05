import com.sun.source.tree.Tree;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 623. 在二叉树中增加一行
 *
 * 思路：
 * 层序遍历
 */


public class SolutionFor623 {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth==1){
            return new TreeNode(val,root,null);
        }
        Deque<TreeNode> que = new ArrayDeque<TreeNode>();
        que.addLast(root);
        int level = 1;
        while (!que.isEmpty()){
            int num = que.size();
            for (int i=0; i<num; i++){
                TreeNode curr = que.removeFirst();
                if (level==depth-1){ // 父层
                    TreeNode lc = curr.left;
                    TreeNode rc = curr.right;
                    curr.left = new TreeNode(val,lc,null);
                    curr.right = new TreeNode(val,null,rc);
                }
                if (curr.left!=null){
                    que.addLast(curr.left);

                }
                if (curr.right!=null){
                    que.addLast(curr.right);
                }
            }
            if (level == depth-1){
                return root;
            }
            level++;
        }
        return root;
    }
}
