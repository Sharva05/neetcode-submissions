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
    int goodNodes(TreeNode* root) {
        return goodPath(root, INT_MIN);
    }

    int goodPath(TreeNode* root, int maxi){
        if(!root) return 0;

        int cur_good=0;

        if(root->val>=maxi){
            cur_good=1;
            maxi=root->val;
        }

        return cur_good +goodPath(root->left, maxi) + goodPath(root->right, maxi);
    }
};
