#include <iostream>
#include <set>
using namespace std;

/*
729. 我的日程安排表 I
重复则返回false
否则添加事项并返回true
*/

/*
思路：
    二分查找
    / 线段树
*/

class MyCalendar {
public:
    set<pair<int,int>> booked;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if(it == booked.begin() || (--it)->second <= start){ // non-overlapped
            booked.emplace(start,end);
            return true;
        }
        return false;
    }
};

// 节点维护信息：ls rs表示区间端点，左闭右开；add为懒标记；val为当前区间的所包含的点的数量
class MyCalendar1 {
private:
    struct Node {
        int add, val;
        Node* ls;
        Node* rs;
    };
    int N = 1e9;
    Node* root = new Node();
public:
    MyCalendar1(){}

    bool query(Node* node, int l, int r, int ls, int rs){
        if(l<=ls && r>= rs){
            return node->val;
        }
        pushdown(node, rs-ls);
        int mid = (ls + rs) >> 1;
        bool ans = false;
        if(l<=mid)
            ans = ans || query(node->ls, l, r, ls, mid);
        if(r>mid)
            ans = ans || query(node->rs, l, r, mid, rs);
        return ans;
    }

    void update(Node* node, int l, int r, int ls, int rs, int add){
        if(l<=ls && r>=rs){ // 完全覆盖
            node->add = add;
            node->val = rs-ls;
            return;
        }

        pushdown(node, rs-ls);
        int mid = (ls + rs) >> 1;
        if(l<=mid)
            update(node->ls, l, r, ls, mid, add);
        if(r>mid)
            update(node->rs, l, r, mid, rs, add);
        pushup(node);
    }

    void pushdown(Node* node, int len){
        if(node->ls==nullptr)
            node->ls = new Node();

        if(node->rs==nullptr)
            node->rs = new Node();

        if(node->add==0){
            return;
        }
        // push down
        node->ls->add = 1;
        node->rs->add = 1;
        node->ls->val = len/2;
        node->rs->val = len - len/2;
    }

    void pushup(Node* node){
        node->val = node->ls->val + node->rs->val;
    }

    bool book(int start, int end){
        if(query(root, start, end, 0, N)){
            return false;
        }
        update(root, start, end, 0, N, 1);
        return true;
    }
};

int main(){
    return 0;
}