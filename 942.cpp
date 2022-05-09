#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
942. 增减字符串匹配

由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
*/

/*
思路：
    D从大到小放
    I从小到大放
*/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> seq(n+1);
        int l = 0;
        int r = n;
        for(int i=0;i<n;i++){
            if(s[i] == 'I'){
                seq[i] = l;
                l++;
            }
            else{
                seq[i] = r;
                r--;
            }
        }
        seq[n] = l;

        return seq;
    }
};

int main(){
    return 0;
}