#include <iostream>
#include <vector>
using namespace std;

/*
火柴拼正方形

你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。
你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须使用一次 。

如果你能使这个正方形，则返回 true ，否则返回 false 。
*/

/*
思路：
    由于每根火柴棒都得用，所以我们可以算算总长度
    1. 算总长度
    2. /4  看看能否被4整除，不能的话就return false
    3. 能的话就，回溯
*/

class Solution {
public:
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sticksSum = 0;
        for(int len:matchsticks){
            sticksSum += len;
        }
        if(sticksSum % 4) return false;
        int a = sticksSum/4; // a of the square
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, a);
    }
};

int main(){
    return 0;
}