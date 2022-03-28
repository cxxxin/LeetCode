#include <iostream>

using namespace std;

/*
翻转链表
*/

/*
思路：
    不断把头节点往后放
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){ // 空或单节点
            return head;
        }

        ListNode* fakeHead = new ListNode(0,head);
        // 找到尾节点
        ListNode* tail = fakeHead;
        while (tail->next)
        {
            tail = tail->next;
        }

        // reverse当前的前k个节点
        ListNode* afterTail = tail->next;
        ListNode* tailtail = tail->next;
        ListNode* left = head;
        while (tailtail!=tail) // 把头往尾部移，left 与 tail碰上表明移动完毕
        {
            ListNode* temp = left->next;
            left->next = tailtail; // 把头部接到尾部
            tailtail = left; //最尾部固定了，所以指针往前移
            left = temp; // left始终指向当前头部
        }

        // 把reverse后的链表接回原链表
        head->next = afterTail;
        fakeHead->next = tail;
        
        return fakeHead->next;
    }
};

int main(){
    return 0;
}