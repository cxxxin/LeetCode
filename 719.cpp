#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
找出第 K 小的数对距离

数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。
返回 所有数对距离中 第 k 小的数对距离。
*/

/*
思路：
    先排序，然后二分查找
    算count的时候可以固定一端
*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0, right = nums.back()-nums.front(); // ans 不会比left小，不会比right大
        while(left<=right){
            int mid = (left+right)/2;
            int count = 0;
            // 计算所有距离小于等于 mid 的数对数目 count
            for(int i = 0;i<n;i++){ //枚举所有数对的右端点i
                int j = lower_bound(nums.begin(),nums.begin()+i,nums[i]-mid)-nums.begin(); // 比nums[i]-mid小的数的个数
                count += i-j;
            }
            if(count >= k){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};

int main(){
    return 0;
}