#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
找到处理最多请求的服务器

你有 k 个服务器，编号为 0 到 k-1 ，它们可以同时处理多个请求组。
每个服务器有无穷的计算能力但是不能同时处理超过一个请求 。请求分配到服务器的规则如下：

第 i （序号从 0 开始）个请求到达。
如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。
如果第 (i % k) 个服务器空闲，那么对应服务器会处理该请求。
否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。
比方说，如果第 i 个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2) 个服务器等等。

给你一个 严格递增 的正整数数组 arrival ，表示第 i 个任务的到达时间，和另一个数组 load ，
其中 load[i] 表示第 i 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到最繁忙的服务器 。
最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。

请你返回包含所有 最繁忙服务器 序号的列表，你可以以任意顺序返回这个列表。
*/

/*
思路：
    维护一个服务器状态列表，记录服务器还有多久进入空闲状态
    维护一个任务数量列表，记录每个服务器完成过的任务数量
*/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> ans;
        vector<int> state(k);
        vector<int> count(k);

        for (int i = 0; i < k; i++) // init
        {
           state[i] = 0;
           count[i] = 0;
        }
        
        for (int i = 0; i < arrival.size(); i++)
        {
            // 更新服务器的状态
            for (int j = 0; j < k; j++)
            {
                if (i==0) // 首轮不需要初始化
                {
                    break;
                }

                if (state[j] == 0)
                {
                    continue;
                }
                
                if (state[j] > arrival[i]-arrival[i-1] ){
                    state[j] -= arrival[i]-arrival[i-1];
                    continue;
                }
                state[j] = 0;
            }
            
            //  有任务 需要找空闲的服务器
            int j = i;
            while (state[j%k] != 0 && j<i+k) 
            {
                j++;
            }
            if (j >= i+k) // 没有空闲的服务器
            {
                continue;
            }
            
            j %= k;
            state[j] = load[i];
            count[j]++;
        }

        // 找最大
        int maxRequest = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; i++)
        {
            if (count[i] == maxRequest)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}