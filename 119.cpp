#include <iostream>
#include <vector>

using namespace std;

/*
杨辉三角 II

给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

/*
思路：
    动态规划，永远只需用到上一行
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for(int i=1;i<=rowIndex;i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j=0;j<ans.size()-1;j++){
                curr.push_back(ans[j]+ans[j+1]);
            }
            curr.push_back(1);
            ans.clear();
            ans.swap(curr);
        }
        return ans;
    }
};

int main(){
    return 0;
}