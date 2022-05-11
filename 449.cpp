#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
序列化和反序列化二叉搜索树

序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，
以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 
您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。
*/

/*
思路：
    DFS
    二叉搜索树的特点：左边的节点比父节点小，右边的节点比父节点大
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        vector<int> arr;
        postOrder(root, arr); // 得到树的后序遍历vector
        if (arr.size() == 0) {
            return res;
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            res.append(to_string(arr[i]) + ","); // 用逗号隔开
        }
        res.append(to_string(arr.back()));
        return res;
    }

    vector<string> split(const string &str, char dec) { // 根据逗号分割str
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == dec) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec) {
                pos++;
            }
            if (start < str.size()) {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        vector<string> arr = split(data, ','); // 按逗号分割字符串
        stack<int> st;
        for (auto & str : arr) {
            st.emplace(stoi(str)); // 把分割出来的字符转换为int类型的数据并压入栈，为什么是栈呢，因为后序遍历后，父节点是在后面的
        }
        return construct(INT_MIN, INT_MAX, st);
    }

    void postOrder(TreeNode *root,vector<int> & arr) { // 后序遍历得到vector
        if (root == nullptr) {
            return;
        }
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    TreeNode * construct(int lower, int upper, stack<int> & st) {
        if (st.size() == 0 || st.top() < lower || st.top() > upper) {
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }
};

int main(){
    return 0;
}