/**
 * 53. 最大子数组和
 * 思路：dp
 */

public class SolutionFor53 {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        int res = dp[0];
        for (int i=1;i<n;i++){
            dp[i] = Math.max(nums[i], dp[i-1]+nums[i]);
            res =  Math.max(res, dp[i]);
        }
        return res;
    }
}
