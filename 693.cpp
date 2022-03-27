#include <iostream>

using namespace std;

/*
交替位二进制数

给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
*/

/*
思路：
    十进制转二进制就是一直模2
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = true;
        bool prev = n % 2;
        n /= 2;
        while (n!=0)
        {
            if(prev ==  n%2){
                return false;
            }
            prev = n % 2;
            n /= 2;
        }
        
        return ans;
    }
};

int main(){
    return 0;
}