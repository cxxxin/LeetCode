#include <iostream>
#include <vector>
using namespace std;

/*
长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。
*/

/*
思路：
    滑动窗口+前缀和
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT32_MAX;
        int start = 0;
        int currSum = 0;
        for(int i=0;i<nums.size()i++){
            // 够了就减  少了就加
            currSum += nums[i];
            while(currSum>=target){
                ans = min(ans,i-start+1);
                currSum -= nums[start];
                start++;
            }
        }
        if(ans==INT32_MAX)
            return 0;
        return ans;
    }
};

int main(){
    return 0;
}