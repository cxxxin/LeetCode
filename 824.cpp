#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/*
 山羊拉丁文
*/

/*
思路：
    直接遍历
*/

class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> yuanyin {'a','A','e','E','i','I','o','O','u','U'};
        bool begin = true; // 标记是否为开头
        string ans;
        int count = 0;
        string suffix;
        for(char c:sentence){
            if(c==' '){// 是空格
                count++; // 是第几个单词
                ans.append(suffix);
                for(int i=0;i<count;i++){
                    ans.push_back('a');
                }
                ans.push_back(c);
                suffix = "";
                begin = true;
            }
            else if(begin){ // 是否第一个字母
                if(yuanyin.count(c)){// 是否元音
                    ans.push_back(c);
                    suffix = "ma";
                }
                else{
                    suffix.push_back(c);
                    suffix.append("ma");
                }
                begin = false;
            }
            else{//中间字母
                ans.push_back(c);
            }
        }
        //最后一个单词是没有空格结尾的，所以少加了一次
        count++;
        ans.append(suffix);
        for(int i=0;i<count;i++){
            ans.push_back('a');
        }

        return ans;
    }
};

int main(){
    return 0;
}