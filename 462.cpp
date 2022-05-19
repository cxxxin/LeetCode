#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
最少移动次数使数组元素相等 II

给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。
在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。
*/

/*
思路：
    选择中位数？
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        if(n % 2 == 1){
            n = n>>1;
        }
        else{
            n = n>>1;
            n--;
        }
        int target = nums[n];
        for(int i=0;i<n;i++){
            ans += target-nums[i];
        }
        for(int i=n+1;i<nums.size();i++){
            ans += nums[i]-target;
        }
        return ans;
    }
};

int main(){
    vector<int> example = {1,10,2,9};
    Solution s;
    cout<<s.minMoves2(example)<<endl;
    system("pause");
    return 0;
}