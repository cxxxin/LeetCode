#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
寻找右区间

给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。
返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。
如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。
*/

/*
思路：
    用map来存储区间 <start,下标>
*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return {-1};

        map<int,int> mp;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=i;
        }
        for(int i=0;i<n;i++){
            auto it = mp.lower_bound(intervals[i][1]);
            if(it == mp.end()) continue;
            ans[i] = it->second;
        }
        return ans;
    }
};

int main(){
    return 0;
}