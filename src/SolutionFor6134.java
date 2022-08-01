import java.util.Arrays;

/**
 * 6134. 找到离给定两个节点最近的节点
 *
 * 思路：
 * 用一个简单的循环来求出距离数组
 */

public class SolutionFor6134 {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] d1 = getDis(edges, node1), d2 = getDis(edges, node2); // node到所有节点的距离
        int ans = -1, n = edges.length;
        for (int i=0, minDis = n; i<n; i++){
            int d = Math.max(d1[i], d2[i]);
            if (d<minDis){
                minDis = d;
                ans = i;
            }
        }
        return ans;
    }

    int[] getDis(int[] edges, int node){
        int n = edges.length;
        int[] dis = new int[n];
        Arrays.fill(dis, n);
        for (int d = 0; node >=0 && dis[node] == n; node = edges[node]){ // node是个未到达过的节点
            dis[node] = d++; // 走了一步
        }
        return dis;
    }
}
