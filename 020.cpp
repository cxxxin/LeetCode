#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/

/*
思路：用堆栈
*/

class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        stack<char> matchRecord;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(' | s[i]=='{' | s[i]=='['){
                matchRecord.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(!matchRecord.empty() && matchRecord.top()=='('){
                        matchRecord.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i]=='}'){
                    if(!matchRecord.empty() && matchRecord.top()=='{'){
                        matchRecord.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(!matchRecord.empty() && matchRecord.top()=='['){
                        matchRecord.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        if(!matchRecord.empty()){
            ans = false;
        }
        return ans;
    }
};

int main(){
    Solution s;
    bool result = s.isValid("[{(}]");
    cout<<result<<endl;
    system("pause");
    return 0;
}