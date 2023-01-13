import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * 3. 无重复字符的最长子串
 * 思路：hash记录上次出现的位置+滑动窗口
 */

public class SolutionFor3 {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if (n == 0)
            return 0;

        Map<Character, Integer> map = new HashMap<>();
        int left = 0, right = 0, start = 0, maxLen = 1;

        while (right < n){
            if (map.getOrDefault(s.charAt(right), -1) >= left){ // 冲突 移动左边
                left = map.get(s.charAt(right))+1;
            }
            map.put(s.charAt(right), right);

            maxLen = Math.max(right-left+1, maxLen);
            right++;
        }

        return maxLen;
    }
}
