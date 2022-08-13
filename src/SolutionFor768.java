import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 768. 最多能完成排序的块 II
 * 思路：前面的数字比后面的数字大的时候，这一整个区间就必须是在同一个块，所以就是在不断找比head小的最后一个数的位置在哪
 *      单调栈！
 */

public class SolutionFor768 {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        for (int num:arr){
            if (stack.isEmpty() || num>=stack.peek()){ // 后面的数比前面的都大，可以开个新的组
                stack.push(num);
            }
            else { // 需要加入到之前的组
                int mx = stack.pop();
                while (!stack.isEmpty() && stack.peek()>num){
                    stack.pop(); // 前面的数还是比num大，需要拿出来成为一组
                }
                stack.push(mx);
            }
        }
        return stack.size();
    }
}
