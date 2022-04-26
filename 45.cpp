#include <iostream>
#include <vector>
using namespace std;

/*
跳跃游戏 II

给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用[最少]的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
*/

/*
思路：
    贪心，可以贪心的原因：一定可以到达终点
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        if(n==1){
            return 0;
        }

        int maxPos = 0;
        int end = 0;
        while(i<n-1){
            if(i<=maxPos){
                maxPos = max(maxPos,nums[i]+i);
                if(i==end){
                    end = maxPos;
                    ans++;
                }
            }
            i++;
        }
        return ans;
    }

    // 也可以动规做一做
    int jump2(vector<int>& nums){
        int ans = 0;


        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example {2,1};
    cout<<s.jump(example)<<endl;
    system("pause");
    return 0;
}