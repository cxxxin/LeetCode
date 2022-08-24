import java.util.HashMap;
import java.util.Objects;

/**
 * 2384. 最大回文数字
 * 思路：先统计每个数字出现的个数，并从9开始往回遍历，寻找是否还有出现2次以上的数，没有了就挑个最大的出现了一次的数
 */

public class SolutionFor2384 {
    class Solution {
        public String largestPalindromic(String num) {
            HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
            StringBuilder res = new StringBuilder();
            int n = num.length();
            // 统计个数
            for (int i=0;i<n;i++){
                int currNum = num.charAt(i) - '0';
                int currCnt = mp.getOrDefault(currNum, 0);
                if (currCnt>0){
                    mp.replace(currNum, currCnt+1);
                }
                else {
                    mp.put(currNum, 1);
                }
            }

            //放置两端
            int start = 9;
            while (start>=0){
                int cnt = mp.getOrDefault(start, 0);
                if (cnt>1){ // 超过1个
                    res.append(start);
                    mp.replace(start, cnt-2);
                }
                else {
                    start--;
                }
            }

            // 放置最中间
            StringBuilder mid = new StringBuilder();
            for (start=9;start>=0;start--){
                if (mp.getOrDefault(start, 0)>0){
                    mid.append(start);
                    break;
                }
            }

            // 为0开头则置空
            if (res.length()>0 && Objects.equals(res.substring(0, 1), "0")){
                if (mid.length()==0){
                    return "0";
                }
                res = new StringBuilder();
            }
            StringBuilder res2 = new StringBuilder(res);
            res2.reverse();

            return res.append(mid).append(res2).toString();
        }
    }
}

