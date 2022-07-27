#include <iostream>
#include <string>
using namespace std;

/*
592. 分数加减运算

给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。
所以在上述例子中, 2 应该被转换为 2/1。
*/

/*
思路：
    模拟，需要一个frac1记录分子，frac2记录分母
*/

class Solution {
public:
    string fractionAddition(string expression) {
        long long denominator = 0, numerator = 1; // 分子分母
        int index = 0, n = expression.size();
        while(index < n){
            // 分子
            long long denominator1 = 0, sign = 1;
            if(expression[index]=='-' || expression[index]=='+'){ // sign
                sign = expression[index]=='-'?-1:1;
                index++;
            }
            while(index<n && isdigit(expression[index])){
                denominator1 = denominator1*10 + expression[index]-'0';
                index++;
            }
            denominator1 *= sign;
            index++; // 过掉'/'
            
            // 分母
            long long numerator1 = 0;
            while(index<n && isdigit(expression[index])){
                numerator1 = numerator1*10 +expression[index]-'0';
                index++;
            }

            denominator = denominator * numerator1 + denominator1 * numerator; // 通分
            numerator *= numerator1;
        }

        if(denominator==0){
            return "0/1";
        }
        long long g = gcd(abs(denominator), numerator); // 约分
        return to_string(denominator/g) + "/" + to_string(numerator/g);
    }
};

int main(){
    return 0;
}