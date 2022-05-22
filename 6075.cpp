#include <iostream>
#include <vector>
using namespace std;

/*
6075. 装满石头的背包的最大数量

现有编号从 0 到 n - 1 的 n 个背包。给你两个下标从 0 开始的整数数组 capacity 和 rocks 。
第 i 个背包最大可以装 capacity[i] 块石头，当前已经装了 rocks[i] 块石头。
另给你一个整数 additionalRocks ，表示你可以放置的额外石头数量，石头可以往 任意 背包中放置。
请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 最大 数量。
*/

/*
思路：
    计算每个背包差的石头数量，然后排序
    贪心
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(),diff.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(additionalRocks>=diff[i]){ // 还能放
                ans++;
                additionalRocks -= diff[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}