#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
数组中重复的数据

给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
请你找出所有出现 两次 的整数，并以数组形式返回。
你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
*/

/*
思路：
    用一个set记录
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        unordered_set<int> record;
        for(int num:nums){
            if(record.count(num)){
                ans.emplace_back(num);
            }
            else record.emplace(num);
        }
        return ans;
    }
};

int main(){
    return 0;
}