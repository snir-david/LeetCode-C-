
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ValidateBST {
    bool recursive(TreeNode *root, int minVal, int maxVal) {
        if(root == nullptr)
            return true;
        if (root->val <= minVal || root->val >= maxVal)
            return false;
        return recursive (root->left, minVal, root->val)  && recursive (root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode *root) {
        return recursive(root, pow(-2, 31), pow(2, 31));
    }


};