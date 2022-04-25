#include <iostream>
#include <vector>
using namespace std;

/*
一维数组的动态和

给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
请返回 nums 的动态和。
*/

/*
思路：
    动态规划
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};

int main(){
    return 0;
}