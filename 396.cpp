#include <iostream>
#include <vector>

using namespace std;

/*
旋转函数
*/

/*
思路：
    滑动窗口
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int count = 0; // sum
        for(int i=0;i<n;i++){
            ans += nums[i]*i;
            count += nums[i];
        }

        // 旋转
        int curr = ans;
        for(int i=n-1;i>0;i--){
            curr -= nums[i]*(n-1);
            curr += count-nums[i];
            ans = max(ans,curr);
        }

        return ans;
    }
};

int main(){
    return 0;
}