import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 946. 验证栈序列
 * 思路：模拟，当pop不了的时候，就看看还能不能push，不能的话就寄了
 */

public class SolutionFor946 {
    class Solution {
        public boolean validateStackSequences(int[] pushed, int[] popped) {
            int n = pushed.length;
            int pu = 0, po = 0;
            Deque<Integer> stack = new ArrayDeque<Integer>();
            while (pu < n || po < n) { // push完为止
                if (stack.isEmpty()) {
                    stack.addLast(pushed[pu]);
                    pu++;
                }
                else if (stack.getLast() == popped[po]) { // 可以pop
                    stack.removeLast();
                    po++;
                }
                else { // pop不了
                    if (pu >= n)
                        return false;
                    stack.addLast(pushed[pu]);
                    pu++;
                }
            }
           return true;
        }
    }
}
