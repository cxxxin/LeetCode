import java.util.ArrayList;

/**
 * 1470. 重新排列数组
 * 思路：直接模拟
 */

public class SolutionFor1470 {
    class Solution {
        public int[] shuffle(int[] nums, int n) {
            int l = 0, r = n;
            int[] res = new int[2*n];
            int index = -1;
            while (l<n){
                res[++index] = nums[l++];
                res[++index] = nums[r++];
            }
            return res;
        }
    }
}
