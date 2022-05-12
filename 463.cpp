#include <iostream>
#include <vector>

using namespace std;

/*
岛屿的周长

给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
*/

/*
思路：
    其实周长所包含的边是啥呢，是格子0和格子1的交界，所以遍历一边然后找0-1的交界就ok
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int C = 0; // 周长

        // 按行看
        for(int i=0;i<m;i++){
            if(grid[i][0]) C++;
            for(int j=1;j<n;j++){
                if(grid[i][j]!=grid[i][j-1]){ 
                    C++;
                }
            }
            if(grid[i][n-1]) C++;
        }

        // 按列看
        for(int j=0;j<n;j++){
            if(grid[0][j]) C++;
            for(int i=1;i<m;i++){
                if(grid[i][j]!=grid[i-1][j]){
                    C++;
                }
            }
            if(grid[m-1][j]) C++;
        }

        return C;
    }
};

int main(){
    return 0;
}