#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
多个数组求交集

给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，
数组中的每个元素在 nums 所有数组 中都出现过。
*/

/*
*/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_set<int> record;
        unordered_set<int> record1;
        for(int x:nums[0]){
            record.emplace(x);
        }

        for(int i=1;i<nums.size();i++){
            for(int x:nums[i]){
                if(record.count(x)){
                    record1.emplace(x);
                }
            }
            record.clear();
            record.swap(record1);
        }

        for(auto it = record.begin();it!=record.end();it++){
            ans.push_back(*it);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};

int main(){
    return 0;
}