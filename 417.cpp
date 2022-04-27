#include <iostream>
#include <vector>
using namespace std;

/*
太平洋大西洋水流问题

有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，
而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， 
heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。
水可以从海洋附近的任何单元格流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。
*/

/*
思路：
    深搜+遍历，从每个边界开始搜索，看能到达哪些点
*/

class Solution {
public:
    vector<vector<int>> heights;

    void dfs(vector<vector<bool>>& ocean, int i, int j){
        if(ocean[i][j]){ // 这个点已经是1了（遍历过了且可达）
            return;
        }

        int r = ocean.size();
        int c = ocean[0].size();
        ocean[i][j] = true;

        // 四个方向都try一次
        for(int m=-1;m<=1;m+=2){
            int newi = i+m, newj = j;
            if(newi>=0 && newi<r && newj>=0 && newj<c && heights[i][j]<=heights[newi][newj])
                dfs(ocean,newi,newj);
        }
        for(int m=-1;m<=1;m+=2){
            int newi = i, newj = j+m;
            if(newi>=0 && newi<r && newj>=0 && newj<c && heights[i][j]<=heights[newi][newj])
                dfs(ocean,newi,newj);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));

        // dfs for pacific
        for(int i=0;i<r;i++){
            // 搜索[i][0]能到达的点
            dfs(pacific,i,0);
        }

        for(int j=1;j<c;j++){
            // 搜索[0][j]能到达的点
            dfs(pacific,0,j);
        }

        // dfs for atlantic
        for(int i=0;i<r;i++){
            // 搜索[i][0]能到达的点
            dfs(atlantic,i,c-1);
        }

        for(int j=0;j<c-1;j++){
            // 搜索[0][j]能到达的点
            dfs(atlantic,r-1,j);
        }

        // &&
        vector<vector<int>> ans;
        vector<int> point(2);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    
                    point[0] = i;
                    point[1] = j;
                    ans.emplace_back(point);
                }
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}