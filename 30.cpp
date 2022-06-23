#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
串联所有单词的子串

给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
注意 word是有可能重复的

*/

/*
思路：
    滑动窗口
    每轮次的words需要用哈希set存储，才能每次都快速查找当前词汇的使用情况
    额外用一个哈希set用来每次查询是否属于列表
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> record; // 记录使用的单词和对应的个数
        unordered_map<string,int> wordsSet; // 记录每个单词的个数
        for(string word:words){ // 初始化
            wordsSet[word]++;
        }
        int wordSize = words[0].size();//每个词的长度
        if(s.size()<wordSize){
            return ans;
        }

        string curr;
        int pos = 0;
        for(int i=0;i<=s.size()-wordSize;i++){
            for (int j=i;j<i+wordSize;j++){ // 组成单词
                curr.push_back(s[j]);
            }

            if(wordsSet.count(curr)){ // 该词属于字典
                if(record.empty()) // 记录一下起始位置
                    pos = i;

                record[curr]++;
                if(record[curr]>wordsSet[curr]){ // 多余了，失败
                    i = pos;
                    record.clear();
                    curr = "";
                    continue;
                }
                else{// 不重复 可以加入record
                    curr = "";
                    i += wordSize-1;
                }

                if(record == wordsSet){ // 找到了一组完整的包含了字典的string
                    ans.push_back(pos);
                    i = pos; // 重新开始
                    record.clear();
                    curr = "";
                }
            }
            else{ // 不属于字典
                if(!record.empty()){
                    i = pos;
                    record.clear();
                }    
                curr = "";
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> example = {"a"};
    s.findSubstring("bbbaaa",example);
    system("pause");
    return 0;
}