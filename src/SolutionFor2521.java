import java.util.HashSet;
import java.util.Set;

/**
 * 2521. 数组乘积中的不同质因数数目
 * 思路：set记录
 */

public class SolutionFor2521 {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num:nums){
            for (int i=1;i<=num;i++){
                // set包含这个质因数 跳过
                if (set.contains(i))
                    continue;
                // 该数不能整除  跳过
                if (num % i != 0)
                    continue;
                // 该数不是素数 跳过
                if (!isPrime(i))
                    continue;
                // 除掉若干个i直到无法整除
                set.add(i);
                while (num%i != 0){
                    num /= i;
                }
            }
        }
        return set.size();
    }

    boolean isPrime(int x){
        if (x==1)
            return false;

        for (int i=2;i<=Math.sqrt(x);i++){
            if (x % i == 0){
                return false;
            }
        }

        return true;
    }
}
