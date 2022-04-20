#include <iostream>
#include <vector>
using namespace std;

/*
搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。
*/

/*
思路：
    二分查找
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)
            return 0;

        if(n==1){
            return target<=nums[0]?0:1;
        }

        int l = 0;
        int r = n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target){ // 查找成功
                return mid;
            }
            if(target>nums[r]){ // 查找失败
                return r+1;
            }
            if(target<nums[l]){
                return l;
            }
            if(nums[l]<=target && target<nums[mid]){
                r = mid - 1;
            }
            else if(nums[mid]<target && target<=nums[r]){ 
                l = mid + 1;
            }
        }   

        return -1;
    }
};

int main(){
    Solution s;
    vector<int> example = {1,3,5,6};
    int result = s.searchInsert(example,7);
    cout<<result<<endl;
    system("pause");
    return 0;
}