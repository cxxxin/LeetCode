#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
1252. 奇数值单元格的数目

给你一个 m x n 的矩阵，最开始的时候，每个单元格中的值都是 0。

另有一个二维索引数组 indices，indices[i] = [ri, ci] 指向矩阵中的某个位置，其中 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

对 indices[i] 所指向的每个位置，应同时执行下述增量操作：

ri 行上的所有单元格，加 1 。
ci 列上的所有单元格，加 1 。
给你 m、n 和 indices 。请你在执行完所有 indices 指定的增量操作后，返回矩阵中 奇数值单元格 的数目。
*/

/*
思路：
    模拟
*/

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> record(m, vector<int>(n,0));
        for(auto idx:indices){
            int r = idx[0], c = idx[1];
            for(int i=0;i<n;i++){
                record[r][i] = 1 - record[r][i];
            }
            for(int i=0;i<m;i++){
                record[i][c] = 1 - record[i][c];
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            ans += accumulate(record[i].begin(),record[i].end(),0);
        }
        return ans;
    }
};

int main(){
    return 0;
}