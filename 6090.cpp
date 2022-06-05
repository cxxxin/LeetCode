#include <iostream>
#include <vector>
using namespace std;

/*
极大极小游戏
*/

/*
思路
    递归
*/

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; // output

        vector<int> newNums(n/2);
        for(int i=0;i<n;i+=2){
            if(i%4==0){ // min
                newNums[i/2] = min(nums[i],nums[i+1]);
            }
            else{ // max
                newNums[i/2] = max(nums[i],nums[i+1]);
            }
        }
        return minMaxGame(newNums);
    }
};

int main(){
    return 0;
}