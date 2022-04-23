#include <iostream>
#include <vector>
using namespace std;

/*
最大子数组和

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个[连续]部分。
*/

/*
思路：
    动态规划
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}