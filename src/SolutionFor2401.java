public class SolutionFor2401 {
    class Solution {
        public int longestNiceSubarray(int[] nums) {
            int ans = 0;
            int l = 0, r = 0, or = 0;
            for (;r<nums.length;r++){
                while ( (or & nums[r]) > 0){ // or与nums[r]按位与不为0
                    or ^= nums[l]; // 把nums[l]去除
                    l++;
                }
                or |= nums[r]; // 把nums[r]加入
                ans = Math.max(ans, r-l+1);
            }
            return ans;
        }
    }
}
