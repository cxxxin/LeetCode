#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
三维形体投影面积

在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。
投影 就像影子，将 三维 形体映射到一个 二维 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。
返回 所有三个投影的总面积 。
*/

/*
思路：
    模拟
*/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int xy = 0;
        int yz = 0;
        int zx = 0;
        int n = grid.size();
        unordered_map<int,int> maxY;
        for(int i=0;i<n;i++){
            int maxHeight = 0;
            int maxY = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j])
                    xy++;

                maxHeight = max(maxHeight,grid[i][j]);
                maxY = max(maxY,grid[j][i]);
            }
            zx += maxY;
            yz += maxHeight;
        }

        // sum
        return xy+yz+zx;
    }
};

int main(){
    return 0;
}