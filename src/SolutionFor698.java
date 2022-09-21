import java.util.Arrays;

/**
 * 698. 划分为k个相等的子集
 * 思路：dp
 * 我们用一个整数 S 来表示当前可用的数字集合：从低位到高位
 */

public class SolutionFor698 {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int all = Arrays.stream(nums).sum(); // 先求和
        if (all % k != 0) { // 和无法被k整除，则完全不可能划分k个子集
            return false;
        }
        int per = all / k; // 每个子集的目标和
        Arrays.sort(nums); // 先排序，升序
        int n = nums.length;
        if (nums[n - 1] > per) { // 如果有哪个值超过目标和，也将无法划分
            return false;
        }
        boolean[] dp = new boolean[1 << n]; // 2^n个元素, 表示在可用的数字状态为S的情况下是否可能可行
        int[] curSum = new int[1 << n];
        dp[0] = true; // 使用了0个数字的状态，当前状态为可行状态（还能继续加数字）
        for (int i = 0; i < 1 << n; i++) { // 从1开始往使用了越来越多数字的情况 遍历所有状态
            if (!dp[i]) { // 不可行的状态，无需继续往后考虑，剪枝
                continue;
            }
            for (int j = 0; j < n; j++) { // 遍历所有可用的数字
                if (curSum[i] + nums[j] > per) { // 已经放不下当前的数字了，更不用说后面更大的数字了
                    break;
                }
                if (((i >> j) & 1) == 0) { // 当前数字可用
                    int next = i | (1 << j); // 更新数字使用的状态
                    if (!dp[next]) {
                        curSum[next] = (curSum[i] + nums[j]) % per;
                        dp[next] = true;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
}
