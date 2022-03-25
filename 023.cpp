#include <iostream>

using namespace std;

/*
合并k个升序链表
*/

/*
类似于merge sort
分而治之？
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // 子任务
        ListNode* head;
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }

        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        ListNode* curr = head;

        // 滑动窗口
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }

        // list1遍历完了
        if(list1 == nullptr){
            curr->next = list2;
            return head;
        }

        // list2先遍历完了
        if(list2 == nullptr){
            curr->next = list1;
            return head;
        }
        return head;
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r){
        // 递归任务，两两合并，出口：只剩两个链表的时候
        if(l == r){
            return lists[l];
        }
        if(l>r){
            return nullptr;
        }
        int mid = (l+r)>>1;  // 右移一个操作位，即除以2
        return  mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};

int main(){
    return 0;
}