#include <iostream>
#include <string>
#include<climits>

using namespace std;

/*
读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
*/

class Solution {
public:
    int myAtoi(string s) {
        long long int result = 0;
        int sign = 1;
        int begin = 0;
        while (!s.empty())
        {
            if(s[0]==' '&&begin==0){
                s = s.substr(1);
                continue;
            }
            if(s[0]=='-'&&begin==0){
                begin = 1;
                sign = -1;
                s = s.substr(1);
                continue;
            }
            if(s[0]=='+'&&begin==0){
                begin = 1;
                sign = 1;
                s = s.substr(1);
                continue;
            }
            if(s[0]<= '9' && s[0] >= '0'){
                begin = 1;
                int pre = result;
                result = result*10+sign*this->convert(s[0]);
                if(result>INT_MAX){
                    return INT_MAX;
                }
                if(result<INT_MIN){
                    return INT_MIN;
                }
                s = s.substr(1);
            }
            else{
                break;
            }
        }

        return int(result);
    }

    int convert(char s){
        switch (s)
        {
        case '0':
            return 0;
        
        case '1':
            return 1;

        case '2':
            return 2;

        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;

        case '6':
            return 6;

        case '7':
            return 7;

        case '8':
            return 8;

        case '9':
            return 9;
        default:
            return 0;
        }
    }
};

int main(){
    Solution s;
    int result = s.myAtoi("2147483648");
    cout<<result<<endl;
    system("pause");
    return 0;
}