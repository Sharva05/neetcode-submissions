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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        checkRight(root, rightNodes, 0);
        return rightNodes;
    }

    void checkRight(TreeNode* root, vector<int>& rightNodes, int depth){
        if(!root) return;

        if(depth==rightNodes.size()){
            rightNodes.push_back(root->val);
        }

        checkRight(root->right, rightNodes, depth+1);
        checkRight(root->left, rightNodes, depth+1);
    }
};
