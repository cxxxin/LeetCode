#include <iostream>
#include <vector>
using namespace std;

/*
按位与结果大于零的最长组合

对数组 nums 执行 按位与 相当于对数组 nums 中的所有整数执行 按位与 。

例如，对 nums = [1, 5, 3] 来说，按位与等于 1 & 5 & 3 = 1 。
同样，对 nums = [7] 而言，按位与等于 7 。
给你一个正整数数组 candidates 。计算 candidates 中的数字每种组合下 按位与 的结果。
 candidates 中的每个数字在每种组合中只能使用 一次 。

返回按位与结果大于 0 的 最长 组合的长度。
*/

/*
思路：
    全部数都不断右移
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int n = candidates.size();
        for(int i=0;i<24;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(candidates[j]%2) count++;
                candidates[j] = candidates[j]>>1;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};

int main(){
    return 0;
}