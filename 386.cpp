#include <iostream>
#include <vector>

using namespace std;

/*
字典序排数

给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
*/

/*
思路：
    深搜，主动构造，前缀
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int curr = 1;
        for(int i = 0; i<n;i++){
            ans[i] = curr;
            if(curr*10<=n){
                curr *= 10 ;
            }
            else{
                while (curr % 10 == 9 || curr + 1 > n){
                    curr /= 10;
                }
                curr++;
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}