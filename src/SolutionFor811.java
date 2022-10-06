import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 811. 子域名访问计数
 * 思路：用哈希记录次数
 */

public class SolutionFor811 {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String cpdomain:cpdomains){
            int n = cpdomain.length();
            int idx = 0;
            while (idx<n && cpdomain.charAt(idx)!=' ') // 找到访问数字部分
                idx++;
            int cnt = Integer.parseInt(cpdomain.substring(0, idx));
            int start = idx+1;
            idx = n-1; // 移动idx
            while (idx >= start){
                while (idx>=start && cpdomain.charAt(idx)!='.')
                    idx--;
                String curr = cpdomain.substring(idx+1);
                map.put(curr, map.getOrDefault(curr, 0)+cnt);
                idx--;
            }
        }

        List<String> res = new ArrayList<>();
        for (Map.Entry<String, Integer> entry: map.entrySet()){
            res.add(entry.getValue()+" "+entry.getKey());
        }
        return res;
    }
}
