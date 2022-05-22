#include <iostream>
#include <string>
using namespace std;

/*
6074. 字母在字符串中的百分比

给你一个字符串 s 和一个字符 letter ，返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。
*/

/*
思路：
    模拟
*/

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int ans = 0;
        int n = s.length();
        for(char c:s){
            if(c==letter)
                ans++;
        }
        return ans*100/n; 
    }
};

int main(){
    return 0;
}