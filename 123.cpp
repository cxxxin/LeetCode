#include <iostream>
#include <vector>
using namespace std;

/*
买卖股票的最佳时机 III

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

/*
思路：
    动态规划
    分成两段分别做最大一次交易利润
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<int> dp1(n); // 到第i天为止一次交易能赚到的钱最多是多少
        vector<int> dp2(n); // 第i天开始能赚到的钱

        int minPrice = prices[0];
        dp1[0] = -prices[0];
        for(int i=1;i<n;i++){
            dp1[i] = max(dp1[i-1],prices[i]-minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        
        int maxPrice = prices[n-1];
        dp2[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            dp2[i] = max(dp2[i+1],maxPrice-prices[i]);
            maxPrice = max(maxPrice,prices[i]);
        }

        for(int i=0;i<n;++i){
            ans = max(dp1[i]+dp2[i], ans);
        }

        return ans;
    }
};

int main(){
    return 0;
}