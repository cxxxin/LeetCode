#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
连续数组

给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
*/

/*
思路：
    0和1的数量相同 = 1的数量-0的数量=0
    我们可以维持一个变量来记录当前的0和1的数量       
    出现相同的diff的时候意味着中间这段加起来是0 
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp; //哈希表存储的是j的每个取值第一次出现的下标
        
        int j = 0;
        mp[j] = -1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num){
                j++;
            }
            else{
                j--;
            }
            if(mp.count(j)){
                int pre = mp[j];
                ans = max(ans,i-pre);
            }
            else{
                mp[j] = i;
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}