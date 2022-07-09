#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
最长的斐波那契子序列的长度

如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：

n >= 3
对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列 arr ，找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。

（回想一下，子序列是从原序列 arr 中派生出来的，它从 arr 中删掉任意数量的元素（也可以不删），
而不改变其余元素的顺序。例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）
*/

/*
思路：
    动态规划
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> indices; // record <value, index>
        int n = arr.size();
        // initial
        for(int i=0;i<n;i++){
            indices[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j = i-1;j>=0 && arr[j]*2>arr[i];j--){ // 固定住arr[j] arr[i]为序列的末尾
                int k = -1;
                if(indices.count(arr[i]-arr[j])){
                    k = indices[arr[i]-arr[j]];
                }
                if(k>=0){ // 能找到arr[k]满足arr[k] + arr[j] = arr[i]
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}