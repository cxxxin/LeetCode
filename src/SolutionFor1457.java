/**
 * 1475. 商品折扣后的最终价格
 * 思路：遍历 or 单调栈
 */

public class SolutionFor1457 {
    class Solution {
        public int[] finalPrices(int[] prices) {
            int n = prices.length;
            int[] res = new int[n];
            for (int i=0;i<n;i++){
                int discount = 0;
                for (int j=i+1;j<n;j++){
                    if (prices[j]<=prices[i]){
                        discount = prices[j];
                        break;
                    }
                }
                res[i] = prices[i] - discount;
            }
            return res;
        }
    }
}
