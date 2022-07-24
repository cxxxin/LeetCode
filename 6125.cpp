#include <iostream>
#include <vector>
using namespace std;

/*
6125. 相等行列对

给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。
如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
*/

/*
思路：
    暴力模拟
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        for(int i=0;i<n;i++){ // row
            for(int j=0;j<n;j++){ // column
                bool temp = true;
                for(int k=0;k<n;k++){
                    if(grid[i][k]!=grid[k][j]){
                        temp = false;
                        break;
                    }
                }
                if(temp)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    return 0;
}