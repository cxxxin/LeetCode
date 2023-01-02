/**
 * 6278. 统计能整除数字的位数
 * 思路：直接遍历
 */

public class SolutionFor6278 {
    public int countDigits(int num) {
        int res = 0;
        int cp_num = num;
        while (num > 0){
            int curr = num%10;
            if (curr != 0 && cp_num % curr == 0)
                res++;
            num /= 10;
        }

        return res;
    }
}
