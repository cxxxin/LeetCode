import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 828. 统计子串中的唯一字符
 */

public class SolutionFor828 {
    class Solution {
        public int uniqueLetterString(String s) {
            Map<Character, List<Integer>> index = new HashMap<Character, List<Integer>>();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (!index.containsKey(c)) { // index中还未出现过这个字母
                    index.put(c, new ArrayList<Integer>()); // 加入记录
                    index.get(c).add(-1); // 之前没出现过
                }
                index.get(c).add(i); // 记录这一次出现的位置
            }
            int res = 0;
            for (Map.Entry<Character, List<Integer>> entry : index.entrySet()) {
                List<Integer> arr = entry.getValue();
                arr.add(s.length());
                for (int i = 1; i < arr.size() - 1; i++) {
                    res += (arr.get(i) - arr.get(i - 1)) * (arr.get(i + 1) - arr.get(i));
                }
            }
            return res;
        }
    }
}
