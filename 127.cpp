#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
单词接龙

字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 
beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
如果不存在这样的转换序列，返回 0 。
*/

/*
思路：
    1. BFS+优化建图
    我们可以把每个单词都当作图上的一个节点，可以相互转换视作两个节点是双向连通的。那么，我们就可以将问题转化为最短路径搜索问题。
    有点像那个Dis什么什么算法？
    2. 双向BFS
*/

class Solution {
public:
    unordered_map<string,int> wordId; // <word,ID>
    vector<vector<int>> edge; // record the edges of every words
    int count = 0; // allocate ID for new Node
    void addWord(string& word){
        if(!wordId.count(word)){
            wordId[word] = count;
            count++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word){
        addWord(word); // add the word to the hashtable
        int id = wordId[word];
        for(char& c:word){ // & for modify char in the word
            char temp = c;
            c = '*';
            addWord(word);
            int childId = wordId[word];
            edge[id].emplace_back(childId);
            edge[childId].emplace_back(id);
            c = temp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // construct the graph
        for(string word:wordList){
            addEdge(word);
        }
        addEdge(beginWord);

        // if endword is included in wordList
        if(!wordId.count(endWord)) return 0;

        // bfs
        vector<int> dis(count,INT32_MAX); // record the distance between beginWord to the ith word in wordId list
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0; // init
        queue<int> que;
        que.emplace(beginId);
        while(!que.empty()){
            int currNodeId = que.front();
            que.pop();
            if(currNodeId == endId){ // final
                return dis[endId]/2+1;
            }

            for(int& neighborId:edge[currNodeId]){
                if(dis[neighborId]==INT32_MAX){ // has not been visited
                    dis[neighborId] = dis[currNodeId] + 1;
                    que.push(neighborId);
                }
            }
        }
        return 0;
    }
};

int main(){
    int p = 0;
    const int *p1 = &p;
    p = 2;
    cout<<p<<endl;
    system("pause");
    return 0;
}