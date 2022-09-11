import java.util.HashMap;

/**
 * 6176. 出现最频繁的偶数元素
 */

public class SolutionFor6176 {
    class Solution {
        public int mostFrequentEven(int[] nums) {
            HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
            int n = nums.length;
            int res = -1, maxNum = 0;
            for (int i=0;i<n;i++){ // 统计
                if (nums[i]%2==0){
                    if (mp.getOrDefault(nums[i], 0)>0){
                        mp.replace(nums[i], mp.get(nums[i])+1);
                    }
                    else{
                        mp.put(nums[i], 1);
                    }
                    if (mp.get(nums[i]) > maxNum){
                        res = nums[i];
                        maxNum = mp.get(nums[i]);
                    }
                    else if (mp.get(nums[i]) == maxNum){
                        res = Math.min(res, nums[i]);
                    }
                }
            }

            return res;
        }
    }
}
