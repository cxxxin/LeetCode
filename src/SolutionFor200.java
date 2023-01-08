/**
 * 200. 岛屿数量
 * 思路：并查集
 */

public class SolutionFor200 {
    class UnionTree{
        private int[] parent;
        private int[] rank;
        private int count;
        public UnionTree(int n, char[][] grid){
            parent = new int[n];
            rank = new int[n];
            count = 0;

            for (int i=0;i<grid.length;i++){
                for (int j=0;j<grid[0].length;j++){
                    if (grid[i][j] == '1'){
                        parent[grid[0].length*i+j] = grid[0].length*i+j;
                        count++;
                    }
                }
            }
        }

        public void union(int x, int y){
            int rootx = find(x), rooty = find(y);
            if (rootx == rooty)
                return;

            if (rank[rootx] > rank[rooty])
                parent[rooty] = rootx;
            else if (rank[rooty] > rank[rootx])
                parent[rootx] = rooty;
            else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
            --count;
        }

        public int find(int x){
            if (parent[x] == x)
                return x;

            parent[x] = find(parent[x]);
            return parent[x];
        }

        public boolean check(int x, int y){
            return find(x) == find(y);
        }

        public int count(){
            return count;
        }
    }

    public int numIslands(char[][] grid) {
        // 遍历grid建立并查集
        int m = grid.length, n = grid[0].length;
        UnionTree unionTree = new UnionTree(m*n, grid);
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == '1'){ // 是陆地，和周围进行合并
                    grid[i][j] = '0';
                    int idx = n*i+j;
                    // 上
                    if (i>=1 && grid[i-1][j]=='1'){
                        unionTree.union(idx, idx-n);
                    }
                    // 下
                    if (i<m-1 && grid[i+1][j]=='1'){
                        unionTree.union(idx, idx+n);
                    }
                    // 左
                    if (j>=1 && grid[i][j-1]=='1'){
                        unionTree.union(idx, idx-1);
                    }
                    // 右
                    if (j<n-1 && grid[i][j+1]=='1'){
                        unionTree.union(idx, idx+1);
                    }
                }
            }
        }

        // 统计树的棵树
        return unionTree.count();
    }
}
