#include <iostream>
#include <vector>

using namespace std;


/*
移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

/*
思路：
    划重点，顺序可以改变，所以直接和后面的元素交换即可
    双指针
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size()-1;
        if (left == right)
        {
            return nums[0]==val?0:1;
        }
        

        while (left<right){
            // left找到第一个值是val的位置
            while (nums[left]!=val && left<right){
                left++;
            }
            // right找到最后一个不是val的位置
            while (nums[right]==val && left<right){
                right--;
            }
            
            // 交换left right位置的元素
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        if (right == 0)
            return 0;
        if (left == nums.size()-1 && nums[left] != val)
            return nums.size();

        return left;
    }
};

int main(){
    return 0;
}