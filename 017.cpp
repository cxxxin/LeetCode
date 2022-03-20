#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

/*
电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

/*
思路：
首先用map保存每个数字到字母组合的映射
根据数字找到相应的字母组合，然后通过深搜遍历
*/

class Solution {
private:
    unordered_map<char,string> digit2Chacr = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        
        int n = digits.size();
        stack<string> record;
        for(int i=0;i<digit2Chacr[digits[0]].size();i++){
            string temp(1, digit2Chacr[digits[0]][i]);
            record.push(temp); // 根节点
        }
        while(!record.empty()){
            string temp = record.top();
            record.pop();
            if(temp.size()==n){ // 到底了
                ans.push_back(temp);
            }
            else{ // 还能再续
                int pos = temp.size();
                for(int j=0;j<digit2Chacr[digits[pos]].size();j++){
                    string cur(1,digit2Chacr[digits[pos]][j]);
                    string new_cur = temp;
                    new_cur.append(cur);
                    record.push(new_cur);
                }
            }
        }

        return ans;
    }
};


int main(){
    Solution s;
    string example = "23";
    vector<string> result = s.letterCombinations(example);
    //cout<<result<<endl;
    system("pause");
    return 0;
}