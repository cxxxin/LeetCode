#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
在长度 2N 的数组中找出重复 N 次的元素

给你一个整数数组 nums ，该数组具有以下属性：

nums.length == 2 * n.
nums 包含 n + 1 个 不同的 元素
nums 中恰有一个元素重复 n 次
找出并返回重复了 n 次的那个元素。
*/

/*
思路：
    用set记录
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(st.count(nums[i])) return nums[i];
            st.emplace(nums[i]);
        }
        return -1;
    }
};

int main(){
    return 0;
}