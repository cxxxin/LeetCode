#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
6124. 第一个出现两次的字母

给你一个由小写英文字母组成的字符串 s ，请你找出并返回第一个出现 两次 的字母。
注意：
如果 a 的 第二次 出现比 b 的 第二次 出现在字符串中的位置更靠前，则认为字母 a 在字母 b 之前出现两次。
s 包含至少一个出现两次的字母。
*/

/*
思路：
    集合记录
*/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> rcd(26);
        for(char ch:s){
            if(rcd[ch-'a']==0){
                rcd[ch-'a'] = 1;
            }
            else{
                return ch;
            }
        }
        return 'e';
    }
};

int main(){
    return 0;
}