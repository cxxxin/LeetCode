/**
 * 1413. 逐步求和得到正数的最小值
 * 思路： 贪心模拟,保证累加和的最小值 accSumMin >= 1
 */

 class SolutionFor1413 {
    public int minStartValue(int[] nums) {
        int accSum = 0, accSumMin = 0;
        for (int num:nums){
            accSum += num;
            accSumMin = Math.min(accSum, accSumMin);
        }
        return 1-accSumMin;
    }
}
