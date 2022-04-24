#include <iostream>
using namespace std;

/*
二进制间距

给定一个正整数 n，找到并返回 n 的二进制表示中两个 相邻 1 之间的 最长距离 。如果不存在两个相邻的 1，返回 0 。
如果只有 0 将两个 1 分隔开（可能不存在 0 ），则认为这两个 1 彼此 相邻 。
两个 1 之间的距离是它们的二进制表示中位置的绝对差。例如，"1001" 中的两个 1 的距离为 3 。
*/

/*
思路：
    位运算
*/

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int curr = 0;
        while(n){
            if(n%2){ // 末位是1
                ans = max(curr,ans);
                curr = 1;
            }
            else{
                if(curr)
                    curr++;
            }
            n = n>>1;
        }

        return ans;
    }
};

int main(){
    Solution s;
    int result = s.binaryGap(22);
    cout<<result<<endl;
    system("pause");
    return 0;
}