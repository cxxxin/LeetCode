#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
替换数组中的元素

给你一个下标从 0 开始的数组 nums ，它包含 n 个 互不相同 的正整数。
请你对这个数组执行 m 个操作，在第 i 个操作中，你需要将数字 operations[i][0] 替换成 operations[i][1] 。

题目保证在第 i 个操作中：

operations[i][0] 在 nums 中存在。
operations[i][1] 在 nums 中不存在。
请你返回执行完所有操作后的数组。
*/

/*
思路：
    用一个map记录每个数对应的坐标，这样就不用每次都重新找
*/

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){ // <num, pos>
            mp[nums[i]] = i;
        }

        for(vector<int> op:operations){
            int pos = mp[op[0]];
            nums[pos] = op[1];
            mp[op[1]] = pos;
        }

        return nums;
    }
};

int main(){
    return 0;
}