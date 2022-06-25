#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
统计不同回文子序列

给定一个字符串 s，返回 s 中不同的非空「回文子序列」个数 。
通过从 s 中删除 0 个或多个字符来获得子序列。
如果一个字符序列与它反转后的字符序列一致，那么它是「回文字符序列」。
如果有某个 i , 满足 ai != bi ，则两个序列 a1, a2, ... 和 b1, b2, ... 不同。
注意：
结果可能很大，你需要对 109 + 7 取模 。
*/

/*
思路：

*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> next(n, vector<int>(4));
        vector<vector<int>> pre(n, vector<int>(4));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        vector<int> pos(4, -1);

        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 4; c++) {
                pre[i][c] = pos[c];
            }
            pos[s[i] - 'a'] = i;
        }

        pos[0] = pos[1] = pos[2] = pos[3] = n;

        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 4; c++) {
                next[i][c] = pos[c];
            }
            pos[s[i] - 'a'] = i;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int low = next[i][s[i] - 'a'];
                    int high = pre[j][s[i] - 'a'];
                    if (low > high) {
                        dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD;
                    } else if (low == high) {
                        dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD;
                    } else {
                        dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }

        return dp[0][n - 1];
    }
};


int main(){
    return 0;
}