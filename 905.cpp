#include <iostream>
#include <vector>
using namespace std;

/*
按奇偶排序数组

给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。
返回满足此条件的 任一数组 作为答案。
*/

/*
思路：
    双指针交换
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n-1;
        while (l<=r)
        {
            if(nums[l]%2){ // 奇数
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                r--;
            }
            else{
                l++;
            }
        }
        
        return nums;
    }
};

int main(){
    return 0;
}