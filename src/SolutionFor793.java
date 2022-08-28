/**
 * 793. 阶乘函数后 K 个零
 * 思路：有k个0=有k组2*5  又  5一定比2少，所以就是有几个5相乘=》二分
 */

public class SolutionFor793 {
    class Solution {
        public int preimageSizeFZF(int k) {
            if (k<=1) return 5;
            return find(k) - find(k-1);
        }

        // 小于等于k个0的数的个数
        int find(int k){
            long l = 0, r = (long)k*5;
            while (l<r) {
                long mid = (l+r+1)>>1;
                if (getCnt(mid) <= k)
                    l = mid;
                else r = mid-1;
            }

            return (int)r;
        }

        // 含5量
        long getCnt(long x){
            long res = 0;
            while (x!=0) {
                res += x/5;
                x/=5;
            }
            return res;
        }
    }
}
