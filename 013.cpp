#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
罗马数字转整数
输出包含I， V， X， L，C，D 和 M
*/

/*
思路：像上一道题一样，做一个键值对词典，遇到能匹配上的就匹配
*/

class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();

        for(int l=0;l<len;l++){
            // 出现左边的字母更大就减去，更大就照常加上
            int value = symbolValues[s[l]];
            if(value < symbolValues[s[l+1]] && l<len-1){
                ans -= value;
            }
            else{
                ans += value;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    int result = s.romanToInt("VI");
    cout<<result<<endl;
    system("pause");
    return 0;
}