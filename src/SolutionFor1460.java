import java.util.HashMap;

/**
 * 1460. 通过翻转子数组使两个数组相等
 * 思路：只要元素相同 迟早可以翻转到的，所以本质是判断元素是否相同
 */

public class SolutionFor1460 {
    class Solution {
        public boolean canBeEqual(int[] target, int[] arr) {
            int n = arr.length, tot = 0;
            int[] cnt = new int[1010];
            for (int num:target){
                cnt[num]++;
            }

            for (int num:arr){
                cnt[num]--;
                if (cnt[num]<0)
                    return false;
            }

            return true;
        }
    }
}
