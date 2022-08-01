import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 2127. 参加会议的最多员工数
 *
 * 思路：
 * 本质是找出内向基环树上最大的环
 * 拓扑排序+分类讨论
 */
public class SolutionFor2127 {
    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        int[] inDeg = new int[n]; // 记录每个节点的入度
        for (int w:favorite) ++inDeg[w];

        int[] maxDepth = new int[n];
        Deque que = new ArrayDeque<Integer>();
        for (int i=0; i<n; i++){
            if (inDeg[i] == 0)
                que.addFirst(i); // 所有入度为0的节点加入队列
        }
        while (!que.isEmpty()){ // 拓扑排序，剪掉树枝，即所有树枝上的点都会最终退化为入度为0，基环上的点入度为1
            int curr = (Integer) que.removeFirst();
            ++maxDepth[curr]; // 加上当前节点
            int w = favorite[curr]; // 下一个节点
            maxDepth[w] = Math.max(maxDepth[w], maxDepth[curr]); // dp，取最长的树枝
            if (--inDeg[w] == 0)
                que.addFirst(w);
        }

        int maxRingSize = 0, sumChainSize = 0;
        for (int i=0;i<n;i++){
            if (inDeg[i]<=0)
                continue; // 树枝

            inDeg[i] = -1;
            int ringSize = 1;
            for (int curr = favorite[i]; curr!=i; curr = favorite[curr]){ // 计算当前环的大小
                inDeg[curr] = -1;
                ringSize++;
            }
            if (ringSize==2){
                sumChainSize += maxDepth[i] + maxDepth[favorite[i]] + 2; // 基环大小为 2，累加两条最长链的长度
            }
            else maxRingSize = Math.max(maxRingSize, ringSize);
        }

        return Math.max(maxRingSize, sumChainSize);
    }
}
