#include <iostream>
#include <vector>
using namespace std;

/*
除自身以外数组的乘积

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/

/*
思路：
    利用索引左侧所有数字的乘积和右侧所有数字的乘积（即前缀与后缀）相乘得到答案。
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        vector<int> ans(n);

        l[0] = 1;
        r[n-1] = 1;

        for(int i=1;i<n;i++){
            l[i] = l[i-1] * nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            r[i] = r[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i] = l[i]*r[i];
        }
        return ans;
    }
};

int main(){
    return 0;
}