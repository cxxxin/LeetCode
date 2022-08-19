import java.util.HashMap;
import java.util.Map;

/**
 * 1224. 最大相等频率
 * 思路：使用哈希表记录每个数的出现次数、出现次数为f的数的数目
 */

public class SolutionFor1224 {
    public int maxEqualFreq(int[] nums) {
        Map<Integer,Integer> freq = new HashMap<Integer,Integer>();
        Map<Integer,Integer> count = new HashMap<Integer,Integer>();
        int res = 0, maxFreq = 0;
        int n = nums.length;
        for (int i=0;i<n;i++){
            if (count.getOrDefault(nums[i],0)>0){ //获取指定 key 对应对 value，如果找不到 key ，则返回设置的默认值0
                freq.put(count.get(nums[i]), freq.get(count.get(nums[i]))-1); // 之前的f对应的数量少了1，更新freq
            }
            count.put(nums[i], count.getOrDefault(nums[i],0)+1); // update count
            maxFreq = Math.max(maxFreq, count.get(nums[i]));
            freq.put(count.get(nums[i]), freq.getOrDefault(count.get(nums[i]),0)+1); // update freq
            boolean ok = maxFreq==1 || // 最大出现次数是1，则所有数的出现次数都是1
                    freq.get(maxFreq)*maxFreq + freq.get(maxFreq-1)*(maxFreq-1) == i+1 && freq.get(maxFreq)==1 || // 所有数的出现次数都是max or max-1，且max只有一个
                    freq.get(maxFreq) * maxFreq + 1 == i+1 && freq.get(1) == 1; // 有一个数的出现频率为1，其他所有数的出现频率都为max
            if (ok){
                res = Math.max(res, i+1);
            }
        }
        return res;
    }
}
