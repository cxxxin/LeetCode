/**
 * 1403. 非递增顺序的最小子序列
 *
 * 思路：
 * 计算和
 * 排序后找最大的元素，直到和超过总和的一半
 */


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SolutionFor1403 {
    public List<Integer> minSubsequence(int[] nums) {
        int total = Arrays.stream(nums).sum();
        Arrays.sort(nums);

        int cnt = 0;
        List<Integer> ans = new ArrayList<Integer>();
        for (int i=nums.length-1;i>=0;i++){
            cnt += nums[i];
            ans.add(nums[i]);
            if (total < cnt + cnt){
                break;
            }
        }
        return ans;
    }
}
