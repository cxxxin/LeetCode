#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
删列造序
*/

/*
思路：
    没啥好说的  遍历
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int row = strs.size();
        int column = strs[0].size();
        for(int c=0;c<column;c++){
            for(int r=1;r<row;r++){
                if(strs[r][c]<strs[r-1][c]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}