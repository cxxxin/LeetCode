import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 15. 三数之和
 */

public class SolutionFor15 {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums); // 排序，防止重复
        int n = nums.length;

        // 枚举第一个元素
        for (int first=0;first<n;first++){
            // 防止重复
            if (first>0 && nums[first]==nums[first-1])
                continue;

            // 枚举第二、三个元素
            int third = n-1;
            int target = -nums[first];
            for (int second = first+1;second<n;second++){
                // 去重
                if (second>first+1 && nums[second]==nums[second-1])
                    continue;

                // 从大到小枚举third直到和second相遇
                while (second<third && nums[second]+nums[third]>target)
                    third--;

                // second和third已经相遇了，已经完成了第二重循环的遍历，可以重新选第一个元素了
                if (second == third)
                    break;

                // 找到符合条件的，加入res
                if (nums[second] + nums[third] == target){
                    List<Integer> curr = new ArrayList<>();
                    curr.add(nums[first]);
                    curr.add(nums[second]);
                    curr.add(nums[third]);
                    res.add(curr);
                }
            }
        }

        return res;
    }
}
