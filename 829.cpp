#include <iostream>
using namespace std;

/*
连续整数求和

给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。 
*/

/*
思路：
    枚举
*/

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt = 1;
        for (long k = 2; ; ++k) {
            long a = (2 * n / k + 1 - k) / 2;
            if (a < 1) break; // k不能更大
            long s = (2 * a + k - 1) * k / 2;
            if (s == n) ++cnt;
        }
        return cnt;
    }
};


int main(){
    return 0;
}