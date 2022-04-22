#include <iostream>
using namespace std;

/*
Pow(x, n)

实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn ）。
*/

/*
思路：
    迭代or递归
    快速幂，不用真的一次一次乘
*/

class Solution {
public:
    double quickMi(double x, long long n){
        if(n==0)
            return 1.0;

        double y = quickMi(x,n/2);
        return n%2 == 0 ? y*y : y*y*x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N>=0?quickMi(x,N):1.0/quickMi(x,-N);
    }
};

int main(){
    return 0;
}