#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
6112. 装满杯子需要的最短总时长
*/

/*
分类讨论
*/

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if(amount[0]+amount[1] <= amount[2]){
            return amount[2];
        }

        int t = amount[0] + amount[1] - amount[2];
        return (t + 1) / 2 + amount[2];
    }
};

int main(){
    return 0;
}