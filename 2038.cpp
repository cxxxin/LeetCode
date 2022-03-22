#include <iostream>
using namespace std;

/*
如果相邻两个颜色均相同则删除当前颜色

总共有 n 个颜色片段排成一列，每个颜色片段要么是 'A' 要么是 'B' 。
给你一个长度为 n 的字符串 colors ，其中 colors[i] 表示第 i 个颜色片段的颜色。
*/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0;
        int countB = 0;

        for(int i=0;i<colors.size()-1;i++){
            if(i==0){ // 谁都不能删
                continue;
            }
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A'){
                countA++;
                continue;
            }
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B'){
                countB++;
                continue;
            }
        }

        if(countA > countB){
            return true;
        }
        else{ // Alice 先手，所以可操作数相同还是Bob赢
            return false;
        }
    }
};

int main(){
    Solution s;
    bool result = s.winnerOfGame("AAABBB");
    cout<< result <<endl;
    system("pause");
    return 0;
}