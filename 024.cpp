#include <iostream>

using namespace std;

/*
两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，
并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/

/*
思路：
    节点的交换需要三个指针，迭代即可（会比递归快的）
    其实也可以看作递归问题，每次都只处理开头的两个节点
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
    ListNode* swapFirstTwo(ListNode* head){
        // 出口
        if(!head->next || !head->next->next){
            return head;
        }

        ListNode* first = head->next;
        ListNode* second = first->next;

        // swap
        head->next = second;
        first->next = second->next;
        second->next = first;
        first = swapFirstTwo(first);
        return head;
    }

    // ListNode* swapPairs(ListNode* head) {
    //     ListNode* newHead = new ListNode(0,head);
    //     newHead = swapFirstTwo(newHead);
    //     return newHead->next;
    // }

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

int main(){
    ListNode* example = new ListNode(1);
    example->next = new ListNode(2);
    Solution s;
    ListNode* result = s.swapPairs(example);
    system("pause");
    return 0;
}