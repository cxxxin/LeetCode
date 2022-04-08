#include <iostream>

using namespace std;

/*
两数相除

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
*/

/*
思路：
    乘法是多个相加
    反过来除法可以是连续减法
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -2147483648)
        {
            return 1;
        }
        if (dividend == -2147483648 && divisor == -1)
        {
            return 2147483647;
        }
        if (dividend == -2147483648 && divisor == 1)
        {
            return -2147483648;
        }
        if (divisor == -2147483648)
        {
            return 0;
        }
        if (dividend == 0)
        {
            return 0;
        }
        
        // 一般情况，使用二分查找
        int sign = 1; // 符号位
        if (dividend >= 0 && divisor < 0 || dividend <= 0 && divisor > 0)
            sign = -1;
        long a = dividend;
        long b = divisor;
        a = a >= 0 ? a : -a;
        b = b >= 0 ? b : -b;
        long ans = div(a,b);
        if(sign == 1) 
            return ans>INT_MAX?INT_MAX:ans;                                                                                                                                       
        return -ans;
    }

    long div(long a,long b){
        if (a < b)   // 递归出口，当除数比被除数大的时候，为0
            return 0;

        long count = 1;
        long tb = b;
        while (tb + tb < a)
        {
            tb += tb;
            count += count; // 翻倍
        }
        return count + div(a-tb,b);
    }
};

int main(){
    Solution s;
    int result = s.divide(-2147483648,-1);
    cout<<result<<endl;
    system("pause");
    return 0;
}