#include <iostream>
#include <vector>
using namespace std;

/*
对角线遍历
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
*/

/*
思路：
    直接模拟
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool direction = 0; // 0-upright 1-downleft
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(m*n);

        int i = 0, j = 0;
        ans[0] = mat[0][0];
        int cnt = 1;
        while(cnt<m*n){
            if(direction){
                if(i+1<m && j-1>=0){
                    i++;
                    j--;
                    ans[cnt] = mat[i][j];
                    cnt++;
                }
                else if(i+1<m){
                    i++;
                    ans[cnt] = mat[i][j];
                    cnt++;
                    direction = 0;
                }
                else{
                    j++;
                    ans[cnt] = mat[i][j];
                    cnt++;
                    direction = 0;
                }
            }
            else{
                if(i-1>=0 && j+1<n){
                    i--;
                    j++;
                    ans[cnt] = mat[i][j];
                    cnt++;
                }
                else if(j+1<n){
                    j++;
                    ans[cnt] = mat[i][j];
                    cnt++;
                    direction = 1;
                }
                else{
                    i++;
                    ans[cnt] = mat[i][j];
                    cnt++;
                    direction = 1;
                }
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}