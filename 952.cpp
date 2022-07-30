#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
952. 按公因数计算最大组件大小

给定一个由不同正整数的组成的非空数组 nums ，考虑下面的图：

有 nums.length 个节点，按从 nums[0] 到 nums[nums.length - 1] 标记；
只有当 nums[i] 和 nums[j] 共用一个大于 1 的公因数时，nums[i] 和 nums[j]之间才有一条边。
返回 图中最大连通组件的大小 。
*/

/*
思路：
    并查集
*/

// 并查集
class UnioFind{
private:
    vector<int> parent; // idx对应的父节点
    vector<int> rank; // join优先级

public:
    UnioFind(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i; // 初始时是n个独立的节点
        }
    }

    void join(int x, int y){
        int rootx = find(x); // 找根
        int rooty = find(y);
        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty]){
                parent[rooty] = rootx;
            }
            else if(rank[rootx]<rank[rooty]){
                parent[rootx] = rooty;
            }
            else{
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x){ // find root
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        UnioFind uf(m+1);
        for(int num:nums){
            for(int i=2;i*i<=num;i++){ // 找公因数并合并到公因数的树上
                if(num%i==0){
                    uf.join(num, i);
                    uf.join(num, num/i);
                }
            }
        }

        // 统计
        vector<int> counts(m+1);
        int ans = 0;
        for(int num:nums){
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }

        return ans;
    }
};

int main(){
    return 0;
}