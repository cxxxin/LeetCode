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
        vector<vector<int>> ans;

        // 排序+双指针
        sort(nums.begin(),nums.end());

        int num = nums.size();
        for(int i=0;i<num;i++){
            // 不和上一次重复值
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int k = num-1;//遍历元素c
            //遍历元素b
            for(int j=i+1;j<num;j++){
                //不和上一次重复值
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                // 找元素c
                while(j<k && nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                //是和等于0了（找到）还是jk大小关系出现变化（对于当前的ij和更大的j都不会有符合的k了）？
                if(j==k){
                    break;
                }
                else if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s.threeSum(example);
    system("pause");
    return 0;
}