import java.util.Arrays;

public class SolutionFor1608 {
    class Solution {
        public int specialArray(int[] nums) {
            Arrays.sort(nums);
            for (int x=0;x<101;x++){ // 枚举每个可能的x
                int l = 0, r = nums.length-1;
                while (l<r){
                    int mid = (l+r) >> 1;
                    if (nums[mid] >= x)
                        r = mid;
                    else
                        l = mid+1;
                }
                if (nums[r]>=x && x == nums.length-r)
                    return x;
            }
            return -1;
        }
    }
}
