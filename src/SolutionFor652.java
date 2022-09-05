import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SolutionFor652 {
    class Solution {
        List<TreeNode> res = new ArrayList<TreeNode>();
        Map<String, Integer> mp = new HashMap<String, Integer>(); // 用于记录<子树, 出现次数>

        public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
            String str = dfs(root);
            return res;
        }

        String dfs(TreeNode node){
            if (node==null)
                return " "; // 不能为空，否则左儿子是a和右儿子是a打印出来是一样的

            StringBuilder sb = new StringBuilder();
            sb.append(node.val).append("_");
            sb.append(dfs(node.left)); // 左子树
            sb.append(dfs(node.right)); // 右子树
            String key = sb.toString(); // 存入mp里的key
            mp.put(key, mp.getOrDefault(key, 0)+1);
            if (mp.get(key)==2){ // 出现重复
                res.add(node);
            }
            return key;
        }
    }

}
