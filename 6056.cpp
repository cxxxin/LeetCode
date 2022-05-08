#include <iostream>
#include <string>
using namespace std;

/*
字符串中最大的 3 位相同数字
*/

/*
思路：
    滑动窗口
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        ans.reserve(3);
        int count = 0; // 用于计数
        char curr; // 记录当前最大
        for(char n:num){
            if(!count){ // 重新计数了
                count++;
                curr = n;
            }
            else{
                if(curr == n){ // 出现重复
                    count++;// 计数
                }
                else{ // 重新开始
                    count = 1;
                    curr = n;
                }
                if(count==3){ // 找最大的
                    if(ans.empty()){
                        ans.push_back(n);
                        ans.push_back(n);
                        ans.push_back(n);
                    }
                    else{
                        if(n>ans[0]){
                            ans[0] = n;
                            ans[1] = n;
                            ans[2] = n;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}