#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
环绕字符串中唯一的子字符串

把字符串 s 看作是 “abcdefghijklmnopqrstuvwxyz” 的无限环绕字符串，所以 s 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...." . 
现在给定另一个字符串 p 。返回 s 中 唯一 的 p 的 非空子串 的数量 。 
*/

/*
思路：
    前缀和
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int k = 0;
        for(int i=0;i<p.length();i++){
            // 字符之差为1或-25，则说明是连续的
            if(i&&(p[i]-p[i-1]+26)%26 == 1){
                k++;
            }
            // 不连续
            else{
                k = 1;
            }
            dp[p[i]-'a'] = max(dp[p[i]-'a'],k);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};

int main(){
    return 0;
}