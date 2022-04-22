#include <iostream>
using namespace std;

/*
重排链表
*/

/*
思路：
    递归：每次都只把tail替换到currHead之后
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // 递归出口
        if(!head || !head->next || !head->next->next)
            return;

        ListNode* tail = head;
        while(tail->next->next){
            tail = tail->next;
        }
        tail->next->next = head->next;
        head->next = tail->next;
        reorderList(tail->next->next);
    }
};

int main(){
    return 0;
}