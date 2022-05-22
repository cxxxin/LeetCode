#include <iostream>
#include <unordered_map>
using namespace std;

/*
我能赢吗
*/

/*
思路：
    记忆化dfs
*/

class Solution {
public:
    unordered_map<int,bool> mp; // record <number,used>
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal){ // 全加上都超不过
            return false;
        }
        return dfs(maxChoosableInteger,desiredTotal,0,0); // usernumbers记录用过的数字
    }

    bool dfs(int maxChoosableInteger, int desiredTotal, int usedNumbers, int currentTotal){
        if(!mp.count(usedNumbers)){ // 这个局面出现过
            bool res = false;
            for(int i=0;i<maxChoosableInteger;i++){
                // 是否用过这个数
                if(((usedNumbers>>i)&1)==0){
                    // 能赢
                    if(i+1+currentTotal >= desiredTotal){
                        res = true;
                        break;
                    }
                    // 不能在这次赢
                    if(!dfs(maxChoosableInteger, desiredTotal, usedNumbers | (1 << i), currentTotal + i + 1)){ //对方无法获胜
                        res = true;
                        break;
                    }
                }
            }
            mp[usedNumbers] = res;
        }
        return mp[usedNumbers];
    }
};

int main()[
    return 0;
]