#include <iostream>
#include <vector>
using namespace std;

/*
买卖股票的最佳时机 II

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
*/

/*
可以根据开始跌的几个节点划分区间，分解为若干个股票I问题
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int minPrice = prices[0];

        int curr = 0;
        for(int i=1;i<n;i++){
            if(i==n-1 || prices[i]>=prices[i-1] && prices[i]>prices[i+1]){ // 是否拐点
                curr = max(curr,prices[i]-minPrice);
                ans += curr;
                minPrice = prices[i];
                curr = 0;
            }
            else{
                curr = max(curr,prices[i]-minPrice);
                minPrice = min(minPrice,prices[i]);
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}