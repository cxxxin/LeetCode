#include <iostream>
#include <string>

using namespace std;

/*
移动片段得到字符串
*/

/*
思路：
    1. 先去掉空格看看一不一样
    2. 双指针看看能不能移过去
*/

class Solution {
public:
    bool canChange(string start, string target) {
        string s = start, t = target;
        s.erase(remove(s.begin(),s.end(),'_'),s.end());
        t.erase(remove(t.begin(),t.end(),'_'), t.end());
        if(s != t) return false;

        int n = start.size();
        for(int i=0,j=0;i<n;i++){
            if(start[i]=='_'){ // 下一个L/R
                continue;
            }
            while(target[j]=='_'){ // 下一个L/R
                j++;
            }
            if(i!=j && (start[i]=='L') != (i>j)){
                return false;
            }
            j++;
        }
        return true;
    }
};

int main(){
    return 0;
}