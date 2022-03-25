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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head;
        for(int i=0;i<lists.size();i++){
            
        }

        return head;
    }
};

int main(){
    return 0;
}