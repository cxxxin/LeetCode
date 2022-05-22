#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
巫师的总力量和

作为国王的统治者，你有一支巫师军队听你指挥。

给你一个下标从 0 开始的整数数组 strength ，其中 strength[i] 表示第 i 位巫师的力量值。
对于连续的一组巫师（也就是这些巫师的力量值是 strength 的 子数组），总力量 定义为以下两个值的 乘积 ：

巫师中 最弱 的能力值。
组中所有巫师的个人力量值 之和 。
请你返回 所有 巫师组的 总 力量之和。由于答案可能很大，请将答案对 109 + 7 取余 后返回。
子数组 是一个数组里 非空 连续子序列。
*/

/*
思路：
    计算过的东西是可以继续利用的
    前缀和
*/

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long ans = 0;

        // dp
        int sum = 0;
        int minimal = INT32_MAX;
        for(int i=0;i<n;i++){ // row
            sum = 0;
            minimal = INT32_MAX;
            for(int j=i;j<n;j++){
                minimal = min(minimal,strength[j]);
                sum += strength[j];
                ans += ((long long)sum%(long long)(pow(10,9)+7)) * ((long long)minimal%(long long)(pow(10,9)+7));
                ans %= (long long)(pow(10,9)+7);
            } 
        }

        return ans % (long long)(pow(10,9)+7);
    }
};

int main(){
    return 0;
}