#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

/*
实现一个魔法字典
*/

/*
思路：
    字典树+dfs
*/

struct Trie {
    bool is_finished;
    Trie* child[26];

    Trie(){
        is_finished = false;
        fill(begin(child), end(child), nullptr);
    }
};

class MagicDictionary {
private:
    Trie* root;

public:
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) { // 构造字典树
        for(string word:dictionary){
            Trie* curr = root;
            for(char ch:word){ // 遍历每个字母
                int idx = ch -'a';
                if(!curr->child[idx]){ // 没有该节点则创一个
                    curr->child[idx] = new Trie();
                }
                curr = curr->child[idx];
            }
            curr->is_finished = true; // 是结尾
        }
    }
    
    bool search(string searchWord) {
        function<bool(Trie*, int, bool)> dfs = [&](Trie* node, int pos, bool modified) {
            if (pos == searchWord.size()) {
                return modified && node->is_finished; // 是结尾且进行了一次修改
            }
            int idx = searchWord[pos] - 'a';
            if (node->child[idx]) { // 有一个值为searchWord[pos] 的子节点，可以继续递归
                if (dfs(node->child[idx], pos + 1, modified)) {
                    return true;
                }
            }
            if (!modified) { // 替换成任意一个字母
                for (int i = 0; i < 26; ++i) {
                    if (i != idx && node->child[i]) {
                        if (dfs(node->child[i], pos + 1, true)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };

        return dfs(root, 0 , false);
    }
};


int main(){
    return 0;
}