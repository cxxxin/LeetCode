#include <iostream>
#include <vector>
using namespace std;

/*
区域和检索 - 数组不可变
*/

/*
思路：
    初始化数组的时候，用一个大小为n的数组记录下从头到当前元素的和
*/

class NumArray {
private:
    vector<int> partSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        partSum.assign(n,0);

        partSum[0] = nums[0];
        for(int i=1;i<n;i++){
            partSum[i] = partSum[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left>0?partSum[right]-partSum[left-1]:partSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main(){
    return 0;
}