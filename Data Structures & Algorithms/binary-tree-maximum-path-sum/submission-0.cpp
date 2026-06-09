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
    int maxPathSum(TreeNode* root) {
        int high = root->val;
        int sum = highestSubroot(root, high);
        return high;
    }
private:
    int highestSubroot(TreeNode* node, int& high) {
        if(node == nullptr) return 0;
        int sum = node->val + highestSubroot(node->left, high) + highestSubroot(node->right, high);
        if(sum > high){
            high = sum;
        }
        if(sum < 0) return 0;
        return sum;
    }
};
