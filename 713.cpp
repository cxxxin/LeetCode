#include <iostream>
#include <vector>

using namespace std;

/*
乘积小于 K 的子数组

给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
*/

/*
思路：
    滑动窗口
    前缀和
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int product = 1, j = 0; // product记录乘积，j记录起始位置
        for(int i=0;i<n;i++){ // i记录结束位置
            product *= nums[i];
            while(j<=i && product >= k){
                product /= nums[j];
                j++;
            }
            ans += i-j+1; // 一旦某个j符合要求，那么j与i之间的距离再缩小也是符合要求的
        }

        return ans;
    }
};

int main(){
    return 0;
}