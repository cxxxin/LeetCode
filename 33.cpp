#include <iostream>
#include <vector>
using namespace std;

/*
搜索旋转排序数组

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
*/

/*
思路：
    二分查找
    旋转数组的二分查找其实是一样的，每次二分完，肯定至少是有一边是完全有序的，那只要数的范围不在那边，就可能是在另一边咯
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)
            return -1;
        
        if(n==1)
            return nums[0]==target?0:-1; 

        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[0]<=nums[mid]){ // nums[0]与nums[mid]比较,说明左边这段是完全有序的
                if(nums[0]<=target&&nums[mid]>target)
                    r = mid - 1;
                else{
                    l = mid + 1;
                }
            }
            else{ // 不完全有序，说明旋转点出现在这段序列，比如5671234中的567 1 234，
                if(nums[mid]<target && nums[n-1]>=target){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

int main(){
    return 0;
}