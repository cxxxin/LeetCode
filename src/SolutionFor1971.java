import java.util.*;

/**
 * 1971. 寻找图中是否存在路径
 * 思路：两点连通性问题=>dfs/bfs/并查集
 */

public class SolutionFor1971 {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        // record neighbours
        List<Integer>[] adj = new List[n];
        for (int i=0;i<n;i++){
            adj[i] = new ArrayList<Integer>();
        }

        for (int[] edge:edges){
            int x = edge[0], y = edge[1];
            adj[x].add(y);
            adj[y].add(x);
        }

        // bfs
        Deque<Integer> que = new ArrayDeque<>();
        que.addLast(source);
        boolean[] visited = new boolean[n];
        visited[source] = true;

        while (!que.isEmpty()){
            // 出队第一个节点
            int curr =  que.pollFirst();
            // reach
            if (curr == destination)
                break;

            // 遍历邻居节点
            for (int next:adj[curr]){
                if (!visited[next]){
                    visited[next] = true;
                    que.addLast(next);
                }
            }
        }

        return visited[destination];
    }
}
