#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
强密码检验器

如果一个密码满足下述所有条件，则认为这个密码是强密码：
由至少 6 个，至多 20 个字符组成。
至少包含 一个小写字母，一个大写字母，和一个数字 。
同一字符 不能 连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 如果满足其他条件也可以算是强密码)。
给你一个字符串 password ，返回 将 password 修改到满足强密码条件需要的最少修改步数。如果 password 已经是强密码，则返回 0 。

在一步修改操作中，你可以：
- 插入一个字符到 password ，
- 从 password 中删除一个字符，或
- 用另一个字符来替换 password 中的某个字符。

*/

/*
思路：
    分类讨论
    长度不足6
    长度符合要求
    长度超了20
*/

class Solution {
public:
    int strongPasswordChecker(string password) {
        int ans = 0;
        bool lowercase = 0; // 状态位
        bool capital = 0;
        bool digit = 0;

        for (char ch: password){
            if (ch>='a' && ch<='z')
            {
                lowercase = true;
            }
            else if (ch>='A' && ch<='Z') // 替换即可，无需增删
            {
                capital = true;
            }
            else if (ch>='0' && ch<='9') // 超出了20位，需要删除or替换
            {
                digit = true;
            }
        }

        if (password.size()<6) // 不足6位，缺什么补什么
        {
            return max(6-password.size(),3-lowercase-capital-digit);
        }

        if (password.size()<=20) // 在6-20位以内
        {
            int replace = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch: password) {
                if (ch == cur) {
                    ++cnt;
                }
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3;

            return max(replace, 3-lowercase-capital-digit);
        }

        // 位数超出20，不需要添加操作
        int replace = 0, remove = n - 20; // 替换次数和删除次数
        // k mod 3 = 1 的组数，即删除 2 个字符可以减少 1 次替换操作
        int rm2 = 0;
        int cnt = 0;
        char cur = '#';

        for (char ch: password) {
            if (ch == cur) {
                ++cnt;
            }
            else {
                if (remove > 0 && cnt >= 3) {
                    if (cnt % 3 == 0) {
                        // 如果是 k % 3 = 0 的组，那么优先删除 1 个字符，减少 1 次替换操作
                        --remove;
                        --replace;
                    }
                    else if (cnt % 3 == 1) {
                        // 如果是 k % 3 = 1 的组，那么存下来备用
                        ++rm2;
                    }
                    // k % 3 = 2 的组无需显式考虑
                }
                replace += cnt / 3;
                cnt = 1;
                cur = ch;
            }
        }
        if (remove > 0 && cnt >= 3) {
            if (cnt % 3 == 0) {
                --remove;
                --replace;
            }
            else if (cnt % 3 == 1) {
                ++rm2;
            }
        }
        replace += cnt / 3;

        // 使用 k % 3 = 1 的组的数量，由剩余的替换次数、组数和剩余的删除次数共同决定
        int use2 = min({replace, rm2, remove / 2});
        replace -= use2;
        remove -= use2 * 2;
        // 由于每有一次替换次数就一定有 3 个连续相同的字符（k / 3 决定），因此这里可以直接计算出使用 k % 3 = 2 的组的数量
        int use3 = min({replace, remove / 3});
        replace -= use3;
        remove -= use3 * 3;
        return (n - 20) + max(replace, 3 - categories);         
    }
};

int main(){
    return 0;
}