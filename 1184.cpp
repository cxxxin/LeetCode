#include <iostream>
#include <vector>
using namespace std;

/*
1184. 公交站间的距离

环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。
我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。
环线上的公交车都可以按顺时针和逆时针的方向行驶。
返回乘客从出发点 start 到目的地 destination 之间的最短距离。
*/

/*
思路：
    两条路都求，比较
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int dis1= 0, dis2 = 0, n = distance.size();
        int s = start;
        while(s!=destination){
            dis1 += distance[s];
            s = (s+1)%n;
        }

        while(s!=start){
            dis2 += distance[s];
            s = (s+1)%n;
        }
        return min(dis1, dis2);
    }
};

int main(){
    return 0;
}