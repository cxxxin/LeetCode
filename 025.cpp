#include <iostream>

using namespace std;

/*
K个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
*/

/*
思路：
    迭代（滑动窗口）
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
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) { // tail不变，p从前往后  prev从后往前
            ListNode* nex = p->next; //swap
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup2(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fakeHead = new ListNode(0,head);
        ListNode* pre = fakeHead; // 每次迭代时的头结点的上一个节点
        while (head) // 判断当前的head是否为空
        {
            // 是否还有k个节点
            ListNode* tail = pre;
            for (int count=0; count<k; count++)
            {
                tail = tail->next;
                if (!tail) // 节点为空了，一切都结束啦
                {
                    return fakeHead->next;
                }
            }

            // reverse当前的前k个节点
            ListNode* afterTail = tail->next;
            ListNode* tailtail = tail->next;
            ListNode* left = head;
            while (tailtail!=tail) // 把头往尾部移，tailtail 与 tail碰上表明移动完毕
            {
                ListNode* temp = left->next;
                left->next = tailtail; // 把头部接到尾部
                tailtail = left; //最尾部固定了，所以指针往前移
                left = temp; // left始终指向当前头部
            }

            // 把reverse后的链表接回原链表
            head->next = afterTail;
            pre->next = tail;

            // 迭代
            pre = head;
            head = head->next;
        }
        

        return fakeHead->next;
    }
};


int main(){
    system("pause");
    return 0;
}