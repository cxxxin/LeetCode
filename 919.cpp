#include <iostream>
#include <queue>
using namespace std;

/*
919. 完全二叉树插入器
*/

/*
思路：
    bfs，看谁缺子节点
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> que;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            bool full = true;
            if(node->left){
                que.push(node->left);
                if(node->right){
                    que.push(node->right);
                }
                else full = false;
            }
            else full = false;

            if(full) // 该节点已经有两个子节点了，可以寻找下一个候选节点
                que.pop();
            else
                break;
        }
    }
    
    int insert(int val) {
        TreeNode* node = que.front();
        if(node->left!=nullptr){
            node->right = new TreeNode(val);
            que.push(node->right);
            que.pop();
        }
        else{
            node->left = new TreeNode(val);
            que.push(node->left);
        }
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

int main(){
    return 0;
}