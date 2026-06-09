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
        int preorderIdx = 0;
        return helper(preorder, inorder, 0, inorder.size()-1, preorderIdx);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& preorderIdx) {
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preorderIdx]);

        int mid = left;
        while(inorder[mid] != preorder[preorderIdx]) {
            mid++;
        }
        preorderIdx++;
        root->left = helper(preorder, inorder, left, mid-1, preorderIdx);
        root->right = helper(preorder, inorder, mid + 1, right, preorderIdx);
        return root;
    }
};
