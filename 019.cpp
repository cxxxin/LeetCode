#include <iostream>
using namespace std;

/*
删除链表的倒数第n个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

/*
思路，设置双指针，间隔n个节点，然后后面的那个指针到尾的时候，前面的指针就可以删除它的下一个节点啦
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = left;

        for(int i=0;i<n;i++){
            right = right->next;
        }

        if(right == nullptr){ // 头节点要删掉
            head = left->next;
            return head;
        }

        while (right->next!=nullptr)
        {
            left = left->next;
            right = right->next;
        }

        right = left->next;
        left->next = right->next;
        right->next = nullptr;

        return head;
    }
};


int main(){
    Solution s;
    ListNode* result = s.removeNthFromEnd();
    //cout<<result<<endl;
    system("pause");
    return 0;
}