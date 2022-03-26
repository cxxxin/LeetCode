#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;


/*
棒球比赛

比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。

请你返回记录中所有得分的总和。
*/

/*
思路：
用vector记录着每一步的分数
*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        int pos = -1;
        vector<int> score;
        for(auto &op : ops){
            pos = score.size()-1;
            switch (op[0])
            {
            case '+':
                score.push_back(score[pos] +score[pos-1]);
                ans += score[pos] +score[pos-1];
                break;
            case 'D':
                score.push_back(score[pos]*2);
                ans += score[pos]*2;
                break;
            case 'C':
                ans -= score[pos];
                score.pop_back();
                break;
            default:
                score.push_back(stoi(op)); // 分数记录
                ans += stoi(op);
                break;
            }
        }

        // 分数加和
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> example = {"5","-2","4","C","D","9","+","+"};
    int result = s.calPoints(example);
    cout<<result<<endl;
    system("pause");
    return 0;
}