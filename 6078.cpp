#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
重排字符形成目标字符串

给你两个下标从 0 开始的字符串 s 和 target 。你可以从 s 取出一些字符并将其重排，得到若干新的字符串。
从 s 中取出字符并重新排列，返回可以形成 target 的 最大 副本数。
*/

/*
思路：
    记录
*/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> forS(26);
        vector<int> forTarget(26);

        for(char c:s){
            forS[c-'a']++;
        }
        for(char c:target){
            forTarget[c-'a']++;
        }

        int ans = s.size();
        for(int i=0;i<26;i++){
            if(forTarget[i]>0){ // need
                ans = min(ans,forS[i]/forTarget[i]);
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}