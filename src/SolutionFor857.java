import java.util.Arrays;
import java.util.PriorityQueue;

import static java.util.Arrays.*;

/**
 * 857. 雇佣 K 名工人的最低成本
 */

public class SolutionFor857 {
    class Solution {
        public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
            int n = quality.length;
            double res = 1e9;
            Integer[] h = new Integer[n];
            for (int i=0;i<n;i++){
                h[i] = i;
            }
            sort(h, (a, b)->{ // 按照 wage/quality 升序排序后的索引
                return quality[b]*wage[a] - quality[a]*wage[b]; // 即a的权重比b大就会交换
            });

            double total_q = 0.0;
            PriorityQueue<Integer> priorityQueue = new PriorityQueue<Integer>((a, b)->b-a); // 降序排列
            for (int i=0;i<k-1;i++){ // wage/quality最低的k-1个工人
                total_q += quality[h[i]];
                priorityQueue.offer(quality[h[i]]); // insert
            }
            for (int i=k-1;i<n;i++){
                int idx = h[i];
                total_q += quality[idx];
                priorityQueue.offer(quality[h[i]]);
                double total_c = total_q * ((double)wage[idx]/quality[idx]);
                res = Math.min(res, total_c);
                total_q -= priorityQueue.poll(); // quality 最大的那个工人出队
            }
            return res;
        }
    }
}
