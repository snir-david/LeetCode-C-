#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class RecoverBST {

    void swap(TreeNode* x, TreeNode* y){
        int tmpVal = x->val;
        x->val = y->val;
        y->val = tmpVal;
    }

    void recursive(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if(root == nullptr)
            return;
        if (root->val <= minNode->val){
            swap(root, minNode);
            return;
        }
        if (root->val >= maxNode->val){
            swap(root, maxNode);
            return;
        }
        recursive (root->left, minNode, root);
        recursive (root->right, root, maxNode);
    }

public:
    void recoverTree(TreeNode* root) {
        recursive(root, new TreeNode(pow(-2,31)), new TreeNode(pow(2,31)));
    }
};