/**
 * 33. 搜索旋转排序数组
 * 思路：复制数组找到递增区间然后进行二分
 */

public class SolutionFor33 {
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 1){
            return nums[0]==target ? 0 : -1;
        }

        int[] dnums = new int[n*2];
        for (int i=0;i<n;i++){
            dnums[i] = nums[i];
            dnums[i+n] = nums[i];
        }

        int left = 1;
        while (dnums[left]>dnums[left-1]){
            left++;
        }
        int right = left+n-1;

        // 二分
        while (left<right){
            int mid = (left+right) >> 1;
            if (dnums[mid] == target)
                return mid % n;
            if (dnums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return dnums[left] == target ? left%n : -1;
    }
}
