import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

/**
 * 1422. 分割字符串的最大得分
 * 思路：前缀和
 */

public class SolutionFor1422 {
    public int maxScore(String s) {
        int n = s.length();
        int[] scoreZero = new int[n+1];
        int[] scoreOne = new int[n+1];

        for (int i=0;i<n;i++){
            if (s.charAt(i)=='0'){ // 0
                scoreZero[i+1] = scoreZero[i] + 1;
            }
            else {
                scoreZero[i+1] = scoreZero[i];
            }
            if (s.charAt(n-1-i)=='1'){
                scoreOne[i+1] = scoreOne[i] + 1;
            }
            else {
                scoreOne[i+1] = scoreOne[i];
            }
        }

        int res = 0;
        for (int i=1;i<=n-1;i++){
            res = Math.max(res, scoreZero[i] + scoreOne[n-i]);
        }
        return res;
    }
}

