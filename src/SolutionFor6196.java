/**
 * 6196. 将字符串分割成值不超过 K 的子字符串
 * 思路：贪心
 */

public class SolutionFor6196 {
    public int minimumPartition(String s, int k) {
        int res = 0;
        char[] arr = s.toCharArray();
        int n = s.length(), index = 0;
        long preCount = 0; // 记录当前累计的子串值
        while (index<n){
            // k小于当前位数 直接返回-1
            if (arr[index]-'0' > k)
                return -1;

            // 超出k 结算
            if (arr[index]-'0' + preCount*10 > k){
                res++;
                preCount = arr[index]-'0';
            }

            // 不超出k  继续加入preCount
            else {
                preCount *= 10;
                preCount += arr[index]-'0';
            }

            index++;
        }

        // 最后一个未阶段的preCount
        if (preCount>k)
            return -1;

        return ++res;
    }
}
