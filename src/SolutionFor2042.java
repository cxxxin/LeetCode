/**
 * 2042. 检查句子中的数字是否递增
 * 思路：遍历
 */

public class SolutionFor2042 {
    public boolean areNumbersAscending(String s) {
        int pre = -1;
        for (String x:s.replaceAll("[a-z]", "").split(" ")){
            if (x.length() <= 0)
                continue;
            if (Integer.parseInt(x) <= pre) return false;
            pre = Integer.parseInt(x);
        }
        return true;
    }
}
