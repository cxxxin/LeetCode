#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
存在重复元素 III

给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，
同时又满足 abs(i - j) <= k 。
如果存在则返回 true，不存在返回 false。
*/

/*
思路：
    1. 以k为滑动窗口的大小遍历
    2. 桶排序
*/

class Solution {
public:
    int getID(int x, long w) { // 桶编号
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int,int> mp; // 记录id->num
        int n = nums.size();

        for(int i=0;i<n;i++){
            long x = nums[i]; // 用long是因为怕两个int相减后溢出
            int id = getID(x,t+1ll);
            if(mp.count(id)){
                return true;
            }
            if(mp.count(id-1) && abs(x-mp[id-1])<=t){
                return true;
            }
            if(mp.count(id+1)) && abs(x-mp[id+1]<=t){
                return true;
            }
            mp[id] = x;
            if(i>=k){ // 维持窗口大小
                mp.erase(getID(nums[i-k],t+1ll));
            }
        }

        return false;
    }
};

int main(){
    return 0;
}