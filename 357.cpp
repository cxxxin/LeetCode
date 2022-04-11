#include <iostream>
#include <cmath>

using namespace std;

/*
统计各位数字都不同的数字个数
*/

/*
思路：
    分类讨论+阶乘
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int count = 9;
            for (int j = 1; j < i; j++)
            {
                count *= (10-j);
            }
            ans += count;
        }
        
        return ans+1; // 加的是“0”
    }
};

int main(){
    return 0;
}