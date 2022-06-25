#include <iostream>
#include <vector>
using namespace std;

/*
粉刷房子

假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，
你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。
每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。
请计算出粉刷完所有房子最少的花费成本。
*/

/*
思路：
    动规+滚动数组
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3);

        // init
        for(int j=0;j<3;j++){
            dp[j] = costs[0][j];
        }

        for(int i=1;i<n;i++){
            vector<int> dpNew(3);
            for(int j=0;j<3;j++){ // 刷三种颜色
                dpNew[j] = min(dp[(j+1)%3], dp[(j+2)%3])+costs[i][j];
            }
            dp = dpNew;
        }

        return *min_element(dp.begin(),dp.end());
    }
};

int main(){
    return 0;
}