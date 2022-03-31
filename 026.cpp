#include <iostream>
#include <vector>

using namespace std;

/*
删除有序数组中的重复项

给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
将最终结果插入 nums 的前 k 个位置后返回 k 。
不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

/*
思路：
    首先，这是个升序数组，如果重复元素的话一定是相邻的！所以我们只要按顺序从左到右遍历，比较和左边一个元素是否相同。
    出现重复的话我们就让它等于右边第一个不重复的元素就好啦~~
    双指针
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
        {
            return 0;
        }
        
        int left = 1;
        int right = 1;
        while (right < nums.size())
        {
            if (nums[right] != nums[right-1]) // 不重复
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;
    }
};

int main(){
    system("pause");
    return 0;
}