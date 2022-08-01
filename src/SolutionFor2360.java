/**
 * 2360. 图中的最长环
 *
 * 思路：
 * 基环内向树找最大环，其实可以用拓扑排序剪掉树枝解决
 * 但是也可以使用方法2：利用时间戳来实现找环的逻辑。
 */

public class SolutionFor2360 {
    public int longestCycle(int[] edges) {
        int n = edges.length, ans = -1;
        int[] time = new int[n];
        for (int i=0, clock=1; i<n; i++){ // 起点
            if (time[i]>0) continue; // 已经访问过这个点
            for (int x=i, startTime=clock; x>=0; x=edges[x]){ // 以x从节点i开始游走，直到没有下一个节点为止
                if (time[x] > 0){ // 访问过了
                    if (time[x] >= startTime){ // 以i为起点开始算，再次访问到了当前点x
                        ans = Math.max(ans, clock-time[x]); // 新的环长是两次访问x的时间差
                    }
                    break; // 是一个访问过的点，但不是当前轮次访问过的，后面再走也是一样的肯定都走过一次了
                }
                time[x] = clock++; // 继续游走，对于当前节点更新一次最新访问时间
            }
        }
        return ans;
    }
}
