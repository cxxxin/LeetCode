#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

/*
最常见的单词

给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。
题目保证至少有一个词不在禁用列表中，而且答案唯一。
禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
*/

/*
思路：
    为了快速查找每个单词是否在禁用词范围，需要用哈希表存储禁用词
    遍历paragraph计数，为了快速，也使用map记录<word,times>
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> record;
        unordered_set<string> ban;
        int maxTimes = 0;

        for(string word:banned){ // 创建ban集合
            ban.emplace(word);
        }
        paragraph.push_back('.'); // 防止以字母结尾，数漏最后一个词
        
        string currWord;
        string ans;
        for(char c:paragraph){
            if(isalpha(c)){   // isalpha() 函数检查给定字符是否为字母表。它在cctype 头文件中定义。
                currWord.push_back(tolower(c)); // tolower函数可以将字母转换为小写
            }
            else if(currWord.size()>0){ // 计数+重新开始记录currWord
                if(!ban.count(currWord)){ // 是否为违禁词
                    record[currWord]++;
                    if(record[currWord]>maxTimes){
                        maxTimes = record[currWord];
                        ans = currWord;
                    }
                }
                currWord = "";
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}