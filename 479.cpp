#include <iostream>
#include <cmath>
using namespace std;


/*
最大回文数乘积
*/

/*
思路：
    遍历+判断是否回文数
*/

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        int upper = pow(10,n)-1;
        for(int left = upper;;left--){ // 枚举左半边
            long p = left;
            for(int x = left;x>0;x/=10){ // 翻转左半边得到回文数p
                p = p*10+x%10;
            }
            for(long x = upper;x*x>=p;x--){
                if(p%x == 0)
                    return p%1337;
            }
        }
        
    }
};

int main(){
    return 0;
}