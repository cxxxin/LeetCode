#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

/*
最小基因变化

基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。
如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
*/

/*
思路：
    找出start和end所有不一样的地方，然后深搜/广搜先变换哪个
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();

        int ans = INT32_MAX;
        vector<int>vis(n); // 记录是哪位被变换过
        // 要内部递归调用自身必须指定类型，不能用auto
        function<void(string, int)> dfs = [&](const string& s, int cnt) {
            if (check(s, end) == 0) { // 字符串相同，递归出口
                ans = min(ans, cnt);
                return ;
            }
            for (int i = 0; i < n; i++) { // 遍历bank
                if (!vis[i] && check(s, bank[i]) == 1) { // 和bank[i]刚好只差一位
                    vis[i] = true; // mark
                    dfs(bank[i], cnt+1);
                    vis[i] = false; // 回溯  标记回false，不改这个先
                }
            }
        };

        dfs(start, 0);

        return ans == INT32_MAX ? -1 : ans;
    }

protected:
    inline int check(const string& s1, const string& s2) { // 判断两个字符串是否相同
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            cnt += (s1[i] != s2[i]);
        }
        return cnt;
    }

};

int main(){
    return 0;
}