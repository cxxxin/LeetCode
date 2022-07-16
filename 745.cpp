#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
前缀和后缀搜索

设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。

实现 WordFilter 类：

WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
f(string pref, string suff) 返回词典中具有前缀 prefix 和后缀 suff 的单词的下标。
如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。

*/

/*
思路：
    暴力
*/

class WordFilter {
private:
    unordered_map<string, int> dict;
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            int m = words[i].size();
            string word = words[i];
            for (int prefixLength = 1; prefixLength <= m; prefixLength++) {
                for (int suffixLength = 1; suffixLength <= m; suffixLength++) {
                    string key = word.substr(0, prefixLength) + '#' + word.substr(m - suffixLength);
                    dict[key] = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string target = pref + '#' + suff;
        return dict.count(target) ? dict[target] : -1;
    }
};


int main(){
    return 0;
}