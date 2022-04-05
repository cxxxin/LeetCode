#include <iostream>
#include <cmath>

using namespace std;

/*
二进制表示中质数个计算置位

给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。
计算置位位数 就是二进制表示中 1 的个数。
例如， 21 的二进制表示 10101 有 3 个计算置位。
*/

/*
思路：
    转换为二进制后统计1的个数，然后判断是否为素数
    难点：如何统计1的个数
    方法：n&n-1总是会去掉n的最后一个1
*/

class Solution {
public:
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
            
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int count = 0;
            int curr = i;
            while (curr)
            {
                count++;
                curr &= curr-1;
            }

            if (this->isPrime(count))
            {
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}