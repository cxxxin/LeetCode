#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
871. 最低加油次数

汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。
假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。
当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。
*/

/*
思路：
    贪心
    为了得到最少加油次数，应该在确保每个位置都能到达的前提下，选择最大加油量的加油站加油。
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq; // 记录所有已经到达过的加油站的加油量
        int ans = 0, prev = 0, fuel = startFuel; // initial
        int n = stations.size();

        for(int i=0;i<=n;i++){
            int curr = i<n ? stations[i][0] : target;
            fuel -= curr-prev; // 用掉油
            while(fuel<0 && !pq.empty()){ // 需要加油了，选择一个最优的加油站
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            if(fuel < 0){
                return -1;
            }
            if(i<n){ // 还是加油站
                pq.emplace(stations[i][1]); // 记录新经过的加油站的油量
                prev = curr;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}