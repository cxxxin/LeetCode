#include <iostream>
#include <string>

using namespace std;

/*
最长有效括号

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

/*
思路：
    动态规划
    or
    滑动窗口+计数器 left始终不小于right即可
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        for(char c:s){
            if(c=='('){
                left++;
            }
            else{
                right++;
            }
            if (left == right) { // left = right 可以结算了
                ans = max(ans, 2 * right);
            } 
            else if (right > left) {
                left = right = 0;
            }
        }
        
        reverse(s.begin(),s.end());
        left = 0;
        right = 0;
        for(char c:s){
            if(c==')'){
                left++;
            }
            else{
                right++;             }
            if (left == right) { // left = right 可以结算了
                ans = max(ans, 2 * right);
            } 
            else if (right > left) {
                left = right = 0;
            }
        }

        return ans;        
    }
};

int main(){
    return 0;
}