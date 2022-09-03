/**
 * 646. 最长数对链
 * 思路：
 */

import java.util.Arrays;

public class SolutionFor646 {
    class Solution {
        public int findLongestChain(int[][] pairs) {
            int curr = Integer.MIN_VALUE, res = 0;
            Arrays.sort(pairs, (a, b) -> a[1] - b[1]); // 按照第二个数的值进行排序
            for (int[] pair:pairs){
                if (curr < pair[0]){
                    curr = pair[1];
                    res++;
                }
            }
            return res;
        }
    }
}
