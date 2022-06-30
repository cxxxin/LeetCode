#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
摆动排序 II

给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
你可以假设所有输入数组都可以得到满足题目要求的结果。
*/

/*
思路：
    排序然后把大的数都放在偶数位
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> copy(nums);
        int n = nums.size();
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = copy[j];
            if (i + 1 < n) { // 偶数位
                nums[i + 1] = copy[k];
            }
        }
    }
};

int main(){
    return 0;
}