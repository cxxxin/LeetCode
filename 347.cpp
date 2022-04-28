#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
前 K 个高频元素

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/

/*
思路：
    用一个map记录
    +
    箱排序
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // num-count
        for(int num:nums){
            mp[num]++;
        }

        // 放桶里
        vector<vector<int>> buckets(nums.size()+1);
        for(auto it:mp){
            int num = it.first;
            int count = it.second;
            buckets[count].emplace_back(num);
        }

        // 取出前k个
        vector<int> ans(k);
        int j = 0;
        for(int i=nums.size();i>=0;i--){
            if(!buckets[i].empty()){
                for(int m=0;m<buckets[i].size() && j<k;m++){
                    ans[j] = buckets[i][m];
                    j++;
                }
            }
            if(j==k){
                return ans;
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}