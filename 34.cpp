#include <iostream>
#include <vector>
using namespace std;

/*
在排序数组中查找元素的第一个和最后一个位置

给定一个按照[升序排列]的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
*/

/*
思路：
    二分查找+往左右延伸
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n = nums.size();
        if(!n){
            return ans;
        }

        // 找左边界
        int l = 0;
        int r = n - 1;
        while (l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target && (mid == 0 || nums[mid-1] < target)){
                ans[0] = mid;
                break;
            }
            else{
                if(nums[l]<=target && target<=nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        
        // 找右边界
        l = 0;
        r = n - 1;
        while (l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target && (mid == n-1 || target < nums[mid+1])){
                ans[1] = mid;
                break;
            }
            else{
                if(nums[mid]<=target && target<=nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> example = {5,7,7,8,8,10};
    s.searchRange(example,8);
    system("pause");
    return 0;
}