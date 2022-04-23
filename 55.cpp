#include <iostream>
#include <vector>

using namespace std;

/*
跳跃游戏

给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
*/

/*
思路：
    倒着走
    动态规划：相当于再计算过末位能否到达后，不再重复计算后面
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i=n-1;i>=0;i--){
            if(n-i<=nums[i]){ // 两个下标内能到
                n = i; // 能到就可以把终点提前，否则继续找起点
            }
        }

        return n==0;
    }
};

int main(){
    vector<int> example {2,0,0};
    Solution s;
    cout<<s.canJump(example)<<endl;
    system("pause");
    return 0;
}