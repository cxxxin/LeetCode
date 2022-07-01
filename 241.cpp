#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
为运算表达式设计优先级

给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，
计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10^4 。
*/

/*
思路：
    动态规划/记忆化搜索
    dp[l][r]={v0,v1,…} 来表示对应表达式 ops[l:r] 在按不同优先级组合数字和运算符的操作下能产生的 全部可能结果。
*/

class Solution {
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;
public:
    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops){
        if(dp[l][r].empty()){ // first time
            if(l == r){ // only one possilble result
                dp[l][r].push_back(ops[l]);
            }
            else{
                for(int i=l;i<r;i+=2){
                    vector<int> left = dfs(dp, l, i, ops); // left seq [l,i]
                    vector<int> right = dfs(dp, i+2, r, ops); // right seq [i+2,r]
                    for(int lv:left){
                        for(int rv:right){
                            if(ops[i+1]==ADDITION){
                                dp[l][r].push_back(lv+rv);
                            }
                            else if(ops[i+1]==SUBTRACTION){
                                dp[l][r].push_back(lv-rv);
                            }
                            else if(ops[i+1]==MULTIPLICATION){
                                dp[l][r].push_back(lv*rv);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for(int i=0;i<expression.size();){
            // digit
            if(isdigit(expression[i])){
                int t = 0;
                while(i<expression.size() && isdigit(expression[i])){
                    t = t*10 + (expression[i]-'0');
                    i++;
                }
                ops.push_back(t);
            }
            // symbol
            else{
                // +
                if(expression[i]=='+'){
                    ops.push_back(ADDITION);
                }
                // -
                else if(expression[i]=='-'){
                    ops.push_back(SUBTRACTION);
                }
                // *
                else if(expression[i]=='*'){
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            }
        }

        int n = ops.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
            return dfs(dp, 0, n-1, ops);
    }
};

int main(){
    return 0;
}