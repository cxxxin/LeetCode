/**
 * 1282. 用户分组
 * 思路：贪心即可
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SolutionFor1282 {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer,List<Integer>> groups = new HashMap<Integer, List<Integer>>();
        int n = groupSizes.length;
        for (int i=0;i<n;i++){
            int size = groupSizes[i];
            groups.putIfAbsent(size, new ArrayList<Integer>());
            groups.get(size).add(i); // size相同的数会被放到一个arraylist
        }

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for (Map.Entry<Integer,List<Integer>> entry: groups.entrySet()){ // 通过Map.entrySet使用iterator遍历key和value
            int size = entry.getKey();
            List<Integer> people = entry.getValue();
            int groupCount = people.size()/size; // 一共需要分为几组大小为size的数组
            for (int i=0;i<groupCount;i++){
                List<Integer> group = new ArrayList<Integer>();
                int start = i*size;
                for (int j = 0;j<size;j++){
                    group.add(people.get(start+j));
                }
                ans.add(group);
            }
        }

        return ans;
    }
}
