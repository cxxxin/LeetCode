/**
 * 1408. 数组中的字符串匹配
 *
 * 思路：
 * 枚举
 */

import java.util.ArrayList;
import java.util.List;

public class SolutionFor1408 {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<String>();
        int n = words.length;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i!=j && words[j].contains(words[i])){
                    ans.add(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
}
