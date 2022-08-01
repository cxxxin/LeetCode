import java.util.Arrays;

/**
 * 6132 使数组中所有元素都等于零
 *
 * 给你一个非负整数数组 nums 。在一步操作中，你必须：
 * 选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
 * nums 中的每个正整数都减去 x。
 * 返回使 nums 中所有元素都等于 0 需要的 最少 操作数。
 *
 * 思路：
 * 贪心,每次选择减去的最大值，为最小非零元素
 * 本质：找有多少个不同大小的正整数
 */

public class SolutionFor6132 {
    public int minimumOperations(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int cnt = 0, preVal = 0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                if(nums[i]!=preVal){
                    preVal = nums[i];
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
