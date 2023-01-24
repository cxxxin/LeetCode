/**
 * 42. 接雨水
 * 思路：动规，记录每个格子的两边的最高高度
 */

public class SolutionFor42 {
    public int trap(int[] height) {
        int n = height.length;
        if (n == 0)
            return 0;

        int[] leftMax = new int[n];
        int[] rightMax = new int[n];

        // initial
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // dp
        for (int i=1;i<n;i++){
            leftMax[i] = Math.max(leftMax[i-1], height[i]);
        }
        for (int i=n-2;i>=0;i--){
            rightMax[i] = Math.max(rightMax[i+1], height[i]);
        }

        int res = 0;
        for (int i=0;i<n;i++){
            res += Math.min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
}
