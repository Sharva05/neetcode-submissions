/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxHeight(TreeNode* root, bool& balance){
        if(!root) return 0;
        int left=maxHeight(root->left, balance);
        int right=maxHeight(root->right, balance);
        if(abs(left-right)>1) balance=false;
        return 1+max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balance=true;
        maxHeight(root, balance);
        return balance;
    }
};
