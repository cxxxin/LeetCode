#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 巫师的总力量和
*/

/*
思路：
    单调栈+前缀和的前缀和
    我们可以把这题分解为两部分，一个是求巫师组合里的最小值，一个是求和。
    1. 求区间最小值时可以看成是单调栈问题，每次都在找下一个更小的元素在哪
    2. 求区间和=>前缀和
*/

class Solution {
public:
    int totalStrength(vector<int> &strength) {
        const int mod = 1e9 + 7;

        int n = strength.size();
        vector<int> left(n, -1); // left[i] 为左侧严格小于 strength[i] 的最近元素位置（不存在时为 -1）
        vector<int> right(n, n); // right[i] 为右侧小于等于 strength[i] 的最近元素位置（不存在时为 n）
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && strength[st.top()] >= strength[i]) {
                right[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        } // 

        long s = 0L; // 前缀和
        vector<int> ss(n + 2); // 前缀和的前缀和
        for (int i = 1; i <= n; ++i) {
            s += strength[i - 1];
            ss[i + 1] = (ss[i] + s) % mod; // 注意取模后，下面计算两个 ss 相减，结果可能为负
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long l = left[i] + 1, r = right[i] - 1; // [l,r] 左闭右闭
            long tot = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % mod;
            ans = (ans + strength[i] * tot) % mod; // 累加贡献
        }
        return (ans + mod) % mod; // 防止算出负数
    }
};

int main(){
    return 0;
}
