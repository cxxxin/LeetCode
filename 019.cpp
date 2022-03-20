#include <iostream>
using namespace std;

/*
删除链表的倒数第n个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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

    }
};


int main(){
    Solution s;
    ListNode* result = s.removeNthFromEnd();
    //cout<<result<<endl;
    system("pause");
    return 0;
}