/**
 * 31. 下一个排列
 * 思路：从后往前找第一个前小后大的相邻元素对
 */

public class SolutionFor31 {
    public void nextPermutation(int[] nums) {
        int idx = nums.length-2;
        while (idx >= 0 && nums[idx] >= nums[idx+1]){
            idx--;
        }

        if (idx >= 0){ // 不是最大的序列
            int j = nums.length-1;
            while (j>=0 && nums[idx]>=nums[j]){
                j--;
            }
            swap(nums, idx, j);
        }
        reverse(nums, idx+1, nums.length-1);
    }

    public void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void reverse(int[] nums, int a, int b){
        while (a < b){
            swap(nums, a, b);
            a++;
            b--;
        }
    }
}
