import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * 3. 无重复字符的最长子串
 * 思路：hash记录上次出现的位置+滑动窗口
 */

public class SolutionFor3 {
    public int lengthOfLongestSubstring(String s) {
        if (s.length()==0)
            return 0;

        Map<Character, Integer> rcd = new HashMap<>();
        int res = 0, len = s.length(), left = 0; // left记录滑动窗口的左端

        for (int i=0;i<len;i++){
            char curr = s.charAt(i);
            if (rcd.containsKey(curr)){
                left = Math.max(left, rcd.get(curr)+1);
            }
            rcd.put(curr, i); // 更新最新的位置
            res = Math.max(res, i-left+1);
        }
        return res;
    }
}
