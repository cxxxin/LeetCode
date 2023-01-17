import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 *  46. 全排列
 *  思路：dfs
 */

public class SolutionFor46 {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        for (int num:nums){
            output.add(num);
        }
        int n = nums.length;
        dfs(n, output, res, 0);
        return res;
    }

    private void dfs(int n, List<Integer> output, List<List<Integer>> res, int first) {
        // 所有数都填完了
        if (first == n)
            res.add(new ArrayList<>(output));

        // 穷举每种选择
        for (int i=first;i<n;i++){
            Collections.swap(output, first, i);
            dfs(n, output, res, first+1);
            Collections.swap(output, first, i);
        }
    }
}
