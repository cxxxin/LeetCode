#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

/*
电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        return ans;
    }
};


int main(){
    Solution s;
    string example = "test";
    vector<string> result = s.letterCombinations(example);
    cout<<result<<endl;
    system("pause");
    return 0;
}