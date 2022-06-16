#include <iostream>
#include <vector>

using namespace std;

/*
数组中的 k-diff 数对

给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
注意，|val| 表示 val 的绝对值。
*/

/*
思路：
    排序+双指针
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size(), y = 0;
        sort(nums.begin(),nums.end());
        for(int x=0;x<n;x++){
            if (x == 0 || nums[x] != nums[x - 1]) { // x不重复
                while (y < n && (nums[y] < nums[x] + k || y <= x)) {
                    y++;
                }
                if (y < n && nums[y] == nums[x] + k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}