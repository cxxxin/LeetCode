/**
 * 1464. 数组中两元素的最大乘积
 * 直接遍历
 */

public class SolutionFor1464 {
    class Solution {
        public int maxProduct(int[] nums) {
            int num1 = 0, num2 = -1; // 保证num1>=num2
            for (int num:nums) {
                if (num > num1 && num > num2){
                    num2 = num1;
                    num1 = num;
                }
                else if (num > num2){
                    num2 = num;
                }
            }

            return (num1-1)*(num2-1);
        }
    }
}
