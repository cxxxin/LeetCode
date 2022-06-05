#include <iostream>
#include <vector>
using namespace std;

/*
划分数组使最大差为 K
*/

/*
思路
    排序后分组
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int head = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>head+k){
                head = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main(){
    return 0;
}