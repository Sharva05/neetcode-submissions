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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(checkSame(root, subRoot) == true) return true;
        return isSubtree( root->left,  subRoot) || isSubtree( root->right,  subRoot);
    }

    bool checkSame(TreeNode* original, TreeNode* subRoot) {
        if(!original && !subRoot) return true;
        if(!original || !subRoot || original->val != subRoot->val) return false;
        return checkSame(original->left, subRoot->left) && checkSame(original->right, subRoot->right);
    }
};