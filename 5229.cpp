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
    int solve(vector<int> &nums1, vector<int> &nums2) {
        int s1 = 0, maxSum = 0;
        for (int i = 0, s = 0; i < nums1.size(); ++i) {
            s1 += nums1[i];
            s = max(s + nums2[i] - nums1[i], 0);
            maxSum = max(maxSum, s);
        }
        return s1 + maxSum;
    }

public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }
};


int main(){
    return 0;
}