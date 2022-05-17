#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
验证外星语词典
*/

/*
思路：
    自定义排序
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26); // init
        for(int i=0;i<26;i++){
            index[order[i]-'a'] = i;
        }

        // iteration
        for(int i=1;i<words.size();i++){
            // compare with pre
            int l = 0, r = 0;
            bool valid = false;
            while(l<words[i-1].size() && r<words[i].size()){
                int pre = index[words[i-1][l]-'a'];
                int curr = index[words[i][r]-'a'];
                if(pre>curr) return false;
                if(pre<curr){
                    valid = true;
                    break;
                }
                l++;
                r++;
            }
            // compare length
            if(!valid){
                if(l<words[i-1].size()) return false;
            }
        }

        return true;
    }
};

int main(){
    return 0;
}