#include <iostream>
#include <cmath>
using namespace std;

/*
考试的最大困扰度
一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，
表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。
*/

/*
思路：
    就滑动窗口过去遍历吧，也没别的办法了
    分为T变F和F变T两种情况
*/

class Solution {
public:
    int maxConsecutiveChar(string& answerKey, int k, char ch){
        int ans = 0;
        int left = 0;
        int right = 0;

        int count = 0;
        while (right<answerKey.size())
        {
            count += answerKey[right]!=ch;
            while (count > k) // 替换超了，左端右移
            {
                count -= answerKey[left]!=ch;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        if(answerKey.size()<=1){
            return answerKey.size();
        }
            
        return max(maxConsecutiveChar(answerKey,k,'T'),maxConsecutiveChar(answerKey,k,'F'));
    }
};

int main(){
    return 0;
}