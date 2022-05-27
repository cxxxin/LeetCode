#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
单词距离

有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。
如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?
*/

/*
思路：
    双指针模拟
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int ans = n;
        int l = -1;
        int r = -1;
        for(int i=0;i<n;i++){
            if(words[i]==word1){
                l = i;
            }
            else if(words[i]==word2){
                r = i;
            }
            if (l >= 0 && r >= 0) {
                ans = min(ans, abs(r-l));
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}