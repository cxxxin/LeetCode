#include <iostream>
#include <vector>

using namespace std;

/*
连续的子数组和

给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数。
*/

/*
思路：
    肯定需要遍历一次，从0-i，从1-i，...i-1到i，这其中将会有很多被重复使用的信息。
    同余定理
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        if (m < 2) {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}