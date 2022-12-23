/**
 * 2011. 执行操作后的变量值
 */

public class SolutionFor2011 {
    public int finalValueAfterOperations(String[] operations) {
        int res = 0;
        for (String op:operations){
            if (op.contains("+"))
                res++;
            else
                res--;
        }
        return res;
    }
}
