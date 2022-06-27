#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
拼接数组的最大分数
*/

/*
思路：
    差分数组的最大子数组
*/

class Solution {
public:
    long long  solve(vector<int>& nums1, vector<int>& nums2)
    {
        long long  res = 0;
        int n = nums1.size();
        long long  mx = 0;
        for (int i = 0; i < n; ++i) {
            long long diff = nums2[i] - nums1[i];
            mx = max(diff, mx + diff);
            res = max(res, mx);
        }
        return res;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        long long tot1 = accumulate(nums1.begin(), nums1.end(), 0);
        long long tot2 = accumulate(nums2.begin(), nums2.end(), 0);
        return max(tot1 + solve(nums1, nums2), tot2 + solve(nums2, nums1));
    }
};

int main(){
    return 0;
}