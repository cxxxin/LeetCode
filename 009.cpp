#include <iostream>
#include <string>
#include<climits>

using namespace std;

/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        bool result = true;

        string temp = to_string(x);
        int l = 0;
        int r = temp.size()-1;
        while(l<=r){
            if(temp[l]!=temp[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return result;
    }
};

int main(){
    Solution s;
    bool result = s.isPalindrome(123221);
    cout<<result<<endl;
    system("pause");
    return 0;
}