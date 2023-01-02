import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * 1801. 积压订单中的订单总数
 * 思路：优先队列模拟
 */

public class SolutionFor1801 {
    public int getNumberOfBacklogOrders(int[][] orders) {
        final int MOD = 1000000007;
        PriorityQueue<int[]> buyOrders = new PriorityQueue<int[]>((a,b)->b[0]-a[0]); // 从大到小排列
        PriorityQueue<int[]> sellOrders = new PriorityQueue<int[]>((a,b)->a[0]-b[0]); // 从小到大排列
        for (int[] order:orders){
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0){ // 采购订单
                // 循环找最低的销售订单
                while (amount > 0 && !sellOrders.isEmpty() && sellOrders.peek()[0] <= price){
                    int[] sellOrder = sellOrders.poll();
                    int sellAmount = Math.min(amount, sellOrder[1]);
                    amount -= sellAmount;
                    sellOrder[1] -= sellAmount;
                    if (sellOrder[1] > 0){ // 还有剩，放回队列
                        sellOrders.offer(sellOrder);
                    }
                }
                // 是否还有剩余订单
                if (amount > 0){
                    buyOrders.offer(new int[]{price, amount});
                }
            }
            else { // 销售订单
                // 循环寻找最高的购买订单
                while (amount > 0 && !buyOrders.isEmpty() && buyOrders.peek()[0] >= price){
                    int[] buyOrder = buyOrders.poll();
                    int buyAmount = Math.min(amount, buyOrder[1]);
                    amount -= buyAmount;
                    buyOrder[1] -= buyAmount;
                    if (buyOrder[1] > 0){
                        buyOrders.offer(buyOrder);
                    }
                }
                // 是否还有剩余订单
                if (amount > 0){
                    sellOrders.offer(new int[]{price, amount});
                }
            }
        }

        // 整合两个队列的剩余订单
        int res = 0;
        for (PriorityQueue<int[]> pq: Arrays.asList(buyOrders, sellOrders)){
            while (!pq.isEmpty()){
                int[] order = pq.poll();
                res = (res + order[1]) % MOD;
            }
        }
        return res;
    }
}
