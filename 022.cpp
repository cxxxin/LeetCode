#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合
*/

/*
思路：
回溯，其实每次都需要考虑的是：还需要加东西吗？可加左也可不加左？可加右也可不加右？
*/

class Solution {
private:
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n){
        if(cur.size()==n*2){  // 已经构成答案之一
            ans.push_back(cur);
            return;
        }

        if(open<n){ //左括号数量不大于 n，我们可以放一个左括号，也可以不放
            cur.push_back('(');
            backtrack(ans,cur,open+1,close,n);
            cur.pop_back();
        }

        if(close<open){ //右括号比较少，可以放一个右括号，也可以不放
            cur.push_back(')');
            backtrack(ans,cur,open,close+1,n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        backtrack(ans, current, 0, 0, n);
        return ans;
    }
};


/*
思路2：递归
*/


int main(){
    Solution s;
    vector<string> result = s.generateParenthesis(8);
    //cout<<result<<endl;
    system("pause");
    return 0;
}