#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
删除最外层的括号
*/

/*
思路：
    栈从空到下一次空的过程，则是扫描了一个原语的过程
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        for(char c:s){
            if(c==')'){
                st.pop();
            }
            if(!st.empty()){ // 不是最外层
                ans.push_back(c);
            }
            if(c=='('){
                st.emplace(c);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}