import java.util.HashSet;

/**
 * 6177. 子字符串的最优划分
 */

public class SolutionFor6177 {
    class Solution {
        public int partitionString(String s) {
            int n = s.length();
            int res = 1;
            HashSet<Character> set = new HashSet<Character>();
            for (int i=0;i<n;i++){
                char ch = s.charAt(i);
                if (set.contains(ch)){ // 出现过，重新分割
                    res++;
                    set.clear();
                    set.add(ch);
                }
                else
                    set.add(ch);
            }
            return res;
        }
    }
}
