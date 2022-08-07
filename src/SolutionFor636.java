/**
 * 636. 函数的独占时间
 *
 * 思路：
 * 用栈模拟
 */

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

public class SolutionFor636 {
    public int[] exclusiveTime(int n, List<String> logs) {
        Deque<int[]> stack = new ArrayDeque<int[]>(); // [idx, startTime]
        int[] ans = new int[n];
        for (String log:logs){
            int idx = Integer.parseInt(log.substring(0, log.indexOf(':')));
            String type = log.substring(log.indexOf(':')+1, log.lastIndexOf(':'));
            int timeStamp = Integer.parseInt(log.substring(log.lastIndexOf(':')+1));
            if ("start".equals(type)){
                if (!stack.isEmpty()){ // 本来有其他线程在执行
                    ans[stack.peek()[0]] += timeStamp-stack.peek()[1];
                    stack.peek()[1] = timeStamp; // 这个步骤不能省略，因为可能是递归调用
                }
                stack.push(new int[]{idx, timeStamp});
            }
            else {
                int[] curr = stack.pop(); // 结束后弹出
                ans[curr[0]] += timeStamp-curr[1]+1;
                if (!stack.isEmpty()){ // 本来还有其他线程在执行，被当前的线程阻塞
                    stack.peek()[1] = timeStamp+1;
                }
            }
        }
        return ans;
    }
}
