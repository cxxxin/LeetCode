#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
最长特殊序列 II
*/

/*
思路：
    这是因为如果 sub 如果没有在除了str[i] 之外的字符串中以子序列的形式出现过，
    那么给 sub 不断地添加字符，它也不会出现。而 str[i] 就是 sub 添加若干个（可以为零个）字符得到的结果。

    枚举

    判断 str[i] 是否为 str[j] 的子序列的方法：贪心+双指针
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
       auto is_subseq = [](const string& s1, const string& s2)->bool{ // 判断s1是否为s2的子序列
           int l = 0, r = 0;
           while(l<s1.size() && r<s2.size()){
               if(s1[l] == s2[r]){
                   l++;
               }
               r++;
           }
           return l == s1.size();
       };

       int n = strs.size();
       int ans = -1;
       for(int i=0;i<n;i++){
           bool check = true;
           for(int j=0;j<n;j++){
               if(i!=j && is_subseq(strs[i],strs[j])){ // 有一个碰撞就不是特殊子序列
                   check = false;
                   break;
               }
           }
           if(check){
               ans = max(ans, static_cast<int>(strs[i].size()));
           }
       }
       return ans;
    }
};

int main(){
    return 0;
}