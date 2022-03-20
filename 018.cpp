#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

- 0 <= a, b, c, d < n
- a、b、c 和 d 互不相同
- nums[a] + nums[b] + nums[c] + nums[d] == target

*/

/*
解题思路：
像之前那题一样，通过排序+双指针寻找组合
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        // 去重
        sort(nums.begin(),nums.end());

        // 双指针
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                int k = j+1;
                int l = nums.size()-1; // 双指针

                while(k<l){
                    long long int result = nums[i]+nums[j];
                    result += nums[k];
                    result += nums[l];// 防止溢出
                    if(result==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});

                        // 跳过重复的元素
                        int k0 = k;
                        while(k<l && nums[k]==nums[k0]){
                            k++;
                        }
                        int l0 = l;
                        while (k<l && nums[l]==nums[l0])
                        {
                            l--;
                        }
                    }
                    else if(result>target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }


        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> result = s.fourSum(example,0);
    //cout<<result<<endl;
    system("pause");
    return 0;
}