#include <iostream>
#include <vector>
using namespace std;

/*
二维区域和检索 - 矩阵不可变

给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、
右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
*/

/*
思路：
    前缀和问题 303的2D版本
    preSum[i][j]=preSum[i−1][j]+preSum[i][j−1]−preSum[i−1][j−1]+matrix[i][j]
*/

class NumMatrix {
private:
    vector<vector<int>> region;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        region.resize(m+1,vector<int>(n+1)); // +1是为了不用对0行特殊处理

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                region[i][j] = region[i-1][j] + region[i][j-1] - region[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return region[row2+1][col2+1] - region[row1][col2+1] - region[row2+1][col1] + region[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    return 0;
}