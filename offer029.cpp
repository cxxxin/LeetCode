#include <iostream>
using namespace std;

/*
排序的循环链表
*/

/*
思路：
    模拟
*/

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(head==nullptr){ // empty
            node->next = node;
            return node;
        }

        if(head->next==head){ // only one
            head->next = node;
            node->next = head;
            return head;
        }

        // 需要比大小
        Node *curr = head, *next = head->next;
        while(next!=head){
            if(insertVal >= curr->val && insertVal <= next->val){
                break; // has found
            }
            if(curr->val > next->val){
                if(insertVal > curr->val || insertVal < next->val){
                    break; // 该放在两端
                }
            }
            curr = curr->next;
            next = next->next;
        }

        curr->next = node;
        node->next = next;

        return head;
    }
};

int main(){
    return 0;
}