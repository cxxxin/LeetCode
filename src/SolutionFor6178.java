import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * 6178. 将区间分为最少组数
 */

public class SolutionFor6178 {
    class Solution {
        public int minGroups(int[][] intervals) {
            Arrays.sort(intervals,(a, b)->a[0]==b[0]?a[1]-b[1]:a[0]-b[0]); // 升序排列，先考虑left再考虑right
            PriorityQueue<Integer> queue = new PriorityQueue<>((a, b)->a-b); // 升序排列，用于存储right
            for(int[]interval:intervals){
                if(!queue.isEmpty() && queue.peek()<interval[0]){
                    queue.poll();
                }
                queue.offer(interval[1]);
            }
            return queue.size();
        }
    }
}
