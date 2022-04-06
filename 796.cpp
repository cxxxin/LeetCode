#include <iostream>
#include <string>

using namespace std;

/*
旋转字符串

给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 
例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
*/

/*
思路：
    从每个点开始遍历一次
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
        {
            return false;
        }
        
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            bool ans = true;
            int curr = i;
            int r = 0;
            while (r < n)
            {
                if (s[curr%n]!=goal[r])
                {
                    ans = false;
                    break;
                }
                r++;
                curr++;
            }

            if (ans)
            {
                return true;
            }
        }
    
        return false;
    }
};

int main(){
    Solution s;
    bool result = s.rotateString("abcde","cdeab");
    cout<<result<<endl;
    system("pause");
    return 0;
}