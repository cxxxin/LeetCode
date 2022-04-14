#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

/*
最富有客户的资产总量

给你个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。
返回最富有客户所拥有的 资产总量 。
客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        for(vector<int> acnt:accounts){
            ans = max(ans, accumulate(acnt.begin(),acnt.end(),0)); //前两个参数指定累加的范围，第三个参数为累加的初值，第四个参数为进行的操作，默认为累加
        }
        return ans;
    }
};

int main(){
    return 0;
}