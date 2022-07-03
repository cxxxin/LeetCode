#include <iostream>
#include <map>
using namespace std;

/*
下一个更大元素 III

给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。
如果不存在这样的正整数，则返回 -1 。
注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
*/

/*
思路：
    从末位往前，找出现的第一个降序子序列，并调换顺序
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        long ans = 0;
        string nums = to_string(n);
        int i = nums.size();
        i = i-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--; // 找到第一个比后面的数小的位置
        }
        if(i<0){
            return -1;
        }

        int j = nums.size()-1;
        while(j>=0 && nums[i]>=nums[j]){
            j--; // 找到第一个可以和i交换的位置
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        ans = stol(nums);

        return ans<=INT32_MAX ? (int)ans : -1;
    }
};

int main(){
    return 0;
}