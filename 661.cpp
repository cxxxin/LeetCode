#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
图片平滑器

图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。
每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。
（即，需要计算蓝色平滑器中 9 个单元格的平均值）。
如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。

*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans = img;
        int row = img.size();
        int col = img[0].size();

        for (int r = 0; r < row; r++)
        {
            for(int c = 0; c < col; c++){
                int count = 0;
                int grey = 0;
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(r+i>=0 && c+j>=0 && r+i<row && c+j<col){
                            grey += img[r+i][c+j];
                            count++;
                        }
                    }
                }
                ans[r][c] = floor(double(grey)/count);
            }
        }
        

        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> example = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> result = s.imageSmoother(example);
    system("pause");
    return 0;
}