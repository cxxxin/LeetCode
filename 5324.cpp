#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
移除字母异位词后的结果数组

给你一个下标从 0 开始的字符串 words ，其中 words[i] 由小写英文字符组成。
在一步操作中，需要选出任一下标 i ，从 words 中 删除 words[i] 。其中下标 i 需要同时满足下述两个条件：

0 < i < words.length
words[i - 1] 和 words[i] 是 字母异位词 。
只要可以选出满足条件的下标，就一直执行这个操作。

在执行所有操作后，返回 words 。可以证明，按任意顺序为每步操作选择下标都会得到相同的结果。

字母异位词 是由重新排列源单词的字母得到的一个新单词，
所有源单词中的字母通常恰好只用一次。例如，"dacb" 是 "abdc" 的一个字母异位词。
*/

/*
思路：
    遍历
    判断是否是异位词的方法：看字数、unordered_map记录
*/

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        unordered_map<char,int> mp; // <char,count>
        unordered_map<char,int> tempMap;
        int n = words.size();
        ans.emplace_back(words[0]); // init
        for(int i=0;i<words[0].size();i++){
            mp[words[0][i]]++;
        }

        for(int i=1;i<n;i++){
            if(words[i].size()!=words[i-1].size()){ // new one
                ans.emplace_back(words[i]);
                mp.clear();
                for(int j=0;j<words[i].size();j++){
                    mp[words[i][j]]++;
                }
            }
            else{
                // compare
                tempMap.clear();
                bool update = 0;
                for(int j=0;j<words[i].size();j++){
                    tempMap[words[i][j]]++;
                    if(!mp.count(words[i][j]) || tempMap[words[i][j]]>mp[words[i][j]]){ // new one
                        update = true;
                    }
                }
                if(update) ans.emplace_back(words[i]);
                mp.swap(tempMap);
            }
        }
        words.swap(ans);
        return words;
    }
};

int main()[
    return 0;
]