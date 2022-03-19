#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

/*
最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e7;
        
        // 排序+双指针
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int k = n-1;
            int j = i+1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                    return target;
                }
                if(abs(target-sum)<abs(target-ans)){
                    ans = sum;// update
                }
                if(sum > target){
                    int temp = k;
                    while (j<k && nums[k]==nums[temp]) // 移动到下一个不重复值的元素上
                    {
                        k--;
                    }
                }
                else{
                    int temp = j;
                    while(j<k && nums[j]==nums[temp]){
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example = {-1,2,1,-4};
    int result = s.threeSumClosest(example,1);
    cout<<result<<endl;
    system("pause");
    return 0;
}