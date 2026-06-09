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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, 0, inorder.size()-1, preIdx);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& preIdx) {
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int mid = left;
        while(inorder[mid] != preorder[preIdx]) {
            mid++;
        }
        preIdx++;
        root->left = helper(preorder, inorder, left, mid-1, preIdx);
        root->right = helper(preorder, inorder, mid + 1, right, preIdx);
        return root;
    }
};
