/**
 * 2027. 转换字符串的最少操作次数
 * 思路：贪心
 */

public class SolutionFor2027 {
    public int minimumMoves(String s) {
        int covered = -1, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'X' && i > covered) {
                res++;
                covered = i + 2;
            }
        }
        return res;
    }
}

