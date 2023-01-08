/**
 * 200. 岛屿数量
 * 思路：dfs
 */

public class Solution2For200 {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int res = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j); // 一次性把连在一起的陆地都改成0
                }
            }
        }
        return res;
    }

    void dfs(char[][] grid, int i, int j){
        int m = grid.length;
        int n = grid[0].length;

        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0'){  // 不是陆地 不继续搜
            return;
        }

        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
}
