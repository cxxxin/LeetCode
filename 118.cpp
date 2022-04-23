#include <iostream>
#include <vector>

using namespace std;

/*
杨辉三角

给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

/*
思路：
    动态规划
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for(int i=1;i<numRows;i++){
            ans[i].push_back(1);//开头
            for(int j=0;j<ans[i-1].size()-1;j++){
                ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            ans[i].push_back(1);//结尾
        }

        return ans;
    }
};

int main(){
    return 0;
}