#include <iostream>
#include <string>

using namespace std;

/*
整数转罗马数字
输出包含I， V， X， L，C，D 和 M
*/

const pair<int,string> valueSymbols[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};

class Solution {
public:
    string intToRoman(int num) {
        string ans;

        for (const auto &[value, symbol]:valueSymbols){
            while (num >= value)
            {
                num -= value;
                ans.append(symbol);
            }
            if(num==0){
                break;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    string result = s.intToRoman(3);
    cout<<result<<endl;
    system("pause");
    return 0;
}