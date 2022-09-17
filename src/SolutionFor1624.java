import java.util.Arrays;

/**
 * 1624. 两个相同字符之间的最长子字符串
 * 思路：存储上一次遇到的地方即可
 */

public class SolutionFor1624 {
    class Solution {
        public int maxLengthBetweenEqualCharacters(String s) {
            int[] idxs = new int[26];
            Arrays.fill(idxs, Integer.MAX_VALUE);
            int n = s.length();
            int ans = -1;
            for (int i=0;i<n;i++){
                int u = s.charAt(i) - 'a';
                idxs[u] = Math.min(idxs[u], i);
                ans = Math.max(ans, i - idxs[u] - 1);
            }

            return ans;
        }
    }
}
