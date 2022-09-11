import java.util.HashSet;

/**
 * 217. 存在重复元素
 */

public class SolutionFor217 {
    class Solution {
        public boolean containsDuplicate(int[] nums) {
            HashSet<Integer> set = new HashSet<Integer>();
            int n = nums.length;
            for (int i=0;i<n;i++){
                if (set.contains(nums[i])){
                    return true;
                }
                set.add(nums[i]);
            }
            return false;
        }
    }
}
