#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
掉落的方块
*/

/*
思路：
    1. 记录区间，线段树
    2. 有序集合
    3. 暴力枚举【不推荐】
*/

// 暴力枚举
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1] - 1;
            heights[i] = positions[i][1];
            for (int j = 0; j < i; j++) {
                int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1] - 1;
                if (right1 >= left2 && right2 >= left1) {
                    heights[i] = max(heights[i], heights[j] + positions[i][1]);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            heights[i] = max(heights[i], heights[i - 1]);
        }
        return heights;
    }
};

// 有序集合
class Solution2 {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size(); // 方块的个数
        vector<int> ans(n);
        map<int,int> heightMap; // 用 heightMap 记录每一个相对于前一个点而言，堆叠高度发生变化的点
        heightMap[0] = 0;
        for(int i=0;i<n;i++){
            int size = positions[i][1]; // current size
            int left = positions[i][0]; // current edge
            int right = left + size - 1;
            auto lp = heightMap.upper_bound(left), rp = heightMap.upper_bound(right);
            int rHeight = prev(rp)->second; // right+1对应的堆叠高度

            // update
            int height = 0;
            for(auto p = prev(lp);p!=rp;p++){
                height = max(height, p->second+size);
            }

            // 清楚heightMap中位于(left,right]的点
            heightMap.erase(lp,rp);
            heightMap[left] = height;
            if(rp==heightMap.end() || rp->first != right+1){
                heightMap[right+1] = rHeight;
            }
            ans[i] = i>0 ? max(height,ans[i-1]) : height;
        }
        return ans;
    }
};

// 线段树
struct Node{
    Node *ls; 
    Node *rs;
    int val, add; // val 代表当前区间的最大高度， add是懒标记，0代表无懒标记，否则代表区间的最大高度
    Node(): val(0), ls(nullptr), rs(nullptr) {}
    Node(int x, Node *l, Node *r): val(x), ls(l), rs(r){}
};

class Solution3 {
private:
    int N = (int)1e9;
    Node* root = new Node();
public:
    void pushup(Node* node){
        node->val = max(node->ls->val,node->rs->val); // 因为子区间不重叠，所以其实是子区间的优胜者
    }

    void pushdown(Node* node){
        if(node->ls == nullptr){
            node->ls = new Node();
        }
        if(node->rs == nullptr){
            node->rs = new Node();
        }
        if(node->add == 0){ // 没有懒标记或当前高度为0，没什么好下传的
            return;
        }
        node->ls->add = node->add;
        node->rs->add = node->add; // 懒标记下传

        node->ls->val = node->add;
        node->rs->val = node->add; // 继承区间的最大高度
        node->add = 0; // 删除懒标记
    }

    void update(Node* node, int lc, int rc, int l, int r, int v){ // v 代表[l,r]区间的最大高度
        if(l <= lc && rc <= r){ // 要添加的区间正好完全覆盖当前节点对于的区间
            node->add = v;
            node->val = v; // 更新区间的最大高度
            return;
        }
        pushdown(node);
        int mid = (lc + rc) >> 1;
        if(l <= mid){
            update(node->ls,lc,mid,l,r,v);
        }
        if(r>mid){
            update(node->rs,mid+1,rc,l,r,v);
        }
        pushup(node);
    }
    int query(Node* node, int lc, int rc, int l, int r){
        if(l <= lc && rc <= r){
            return node->val;
        }
        pushdown(node); // 下传懒标记
        int mid = (lc + rc) >> 1;
        int ans = 0;
        if(l<=mid){
            ans = query(node->ls, lc, mid, l ,r);
        }
        if(r>mid){
            ans = max(ans, query(node->rs,mid+1,rc,l,r));
        }
        return ans;
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ans;
        ans.reserve(n);
        
        for(auto& pos:positions){
            int x = pos[0], height = pos[1];
            int currHeight = query(root,0,N,x,x+height-1); // 先查询当前的高度
            update(root,0,N,x,x+height-1,currHeight+height); // 再加上当前的树高
            ans.push_back(root->val);
        }
        return ans;
    }
};

int main(){
    return 0;
}