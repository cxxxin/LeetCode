/**
 * 121. 买卖股票的最佳时机
 * 思路：dp
 */

public class SolutionFor121 {
    public int maxProfit(int[] prices) {
        int prev0 = 0, prev1 = -prices[0];
        int n = prices.length;
        for (int i=1;i<n;i++){
            int dp0 = prev0, dp1 = prev1;
            prev0 = Math.max(dp0, dp1 + prices[i]);
            prev1 = Math.max(dp1, - prices[i]);
        }

        return prev0;
    }
}
