#include <iostream>
#include <vector>
using namespace std;

/*
爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

/*
思路：
    动态规划
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }

        int prepre = 1; // 一个台阶
        int pre = 2; // 两个台阶
        int ans = 0;

        for(int i=2;i<n;i++){
            ans = pre + prepre;
            prepre = pre;
            pre = ans;
        }

        return ans;
    }
};

int main(){
    return 0;
}