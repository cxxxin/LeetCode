import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 1. 两数之和
 * 思路：排序后双指针  使用map来记录下标
 */

public class SolutionFor1 {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        List<Integer>[] component = new List[n];
        for (int i=0;i<n;i++){
            component[i] = new ArrayList<>();
            component[i].add(nums[i]);
            component[i].add(i);
        }
        Arrays.sort(component, (a,b)->a.get(0)-b.get(0));
        Arrays.sort(nums);


        int[] res = new int[2];
        int j = n-1;
        for (int i=0;i<n;i++){
            if (i>0 && nums[i]==nums[i-1])
                continue;
            while (i<j && nums[i]+nums[j]>target){
                j--;
            }
            if (nums[i]+nums[j] == target){
                res[0] = component[i].get(1);
                res[1] = component[j].get(1);
                break;
            }
        }

        return res;
    }
}