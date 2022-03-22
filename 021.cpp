#include <iostream>
using namespace std;

/*
合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

/*
滑动窗口问题
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};


int main(){
    Solution s;
    ListNode* list1 = new ListNode(1);
    ListNode* list2 = new ListNode(2);
    ListNode* result = s.mergeTwoLists(list1,list2);
    //cout<<result<<endl;
    system("pause");
    return 0;
}