#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans = [];

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(example);
    cout<<result<<endl;
    system("pause");
    return 0;
}