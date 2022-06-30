#include <iostream>
using namespace std;

/*
质数排列

请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；
你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。
由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
*/

/*
思路：
    乘法原理，算出质数的个数即可
*/

class Solution {
    const int MOD = 1e9 + 7;

public:
    int numPrimeArrangements(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(isPrime(i)){
                cnt++;
            }
        }
        return (int) (jiecheng(cnt)*jiecheng(n-cnt)%MOD);
    }

    bool isPrime(int num){
        if(num==1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }

    long jiecheng(int n){
        long ans = 1;
        for(int i=1;i<=n;i++){
            ans *= i;
            ans %= MOD;
        }
        return ans;
    }
};

int main(){
    return 0;
}