import java.util.Arrays;

/**
 * 2358. 分组的最大数量
 *
 * 思路：
 * 贪心，最小分组长度从1开始，依次+1
 */

public class SolutionFor2358 {
    public int maximumGroups(int[] grades) {
        int ans = 0;
        int num = 1, n = grades.length;

        while(n>0){
            if (n < num){ // 剩得不多
                return ans;
            }
            else {
                n -= num;
                num++;
                ans++;
            }
        }
        return ans;
    }
}
