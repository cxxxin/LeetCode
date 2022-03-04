#include <iostream>
#include "stdlib.h"
#include <string>

using namespace std;

/*最长回文子串*/

class Solution {
public:
    string longestPalindrome(string s) {
        string result="";
        int mark = 0;

        for(int i=0;i<s.size();i++){
            for(int j=s.size()-1;j>=i;j--){
                int left = i;
                int right = j;
                mark = 0;
                while(left!=right&&left!=right+1){
                    if(s[left]==s[right]){
                        left++;
                        right--;
                    }
                    else{
                        mark = -1;
                        break;//出现对不上的字符，跳出while循环
                    }
                }
                if(mark==0){//匹配成功
                    if(result.size()<j-i+1){//是最长的
                        result = s.substr(i,j-i+1);
                    }
                    break;//i开头的不会有更长的了
                }
            }
        }

        return result;
    }

    //动态规划法
    string longestPalindrome_2(string s){
        string result = "";
        int record;
        return result;
    }
};

int main(){
    Solution s;
    string result = s.longestPalindrome("babd");
    cout<<result<<endl;
    system("pause");
    return 0;
}