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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            
            int len = queue.size();
            vector<int>heightValues;
            while(len--) {
               
               TreeNode* node = queue.front();
               queue.pop();
               heightValues.push_back(node->val);
               if(node->left) queue.push(node->left);
               if(node->right) queue.push(node->right);
            }
           
           ans.push_back(heightValues);
        }
        return ans;
    }
};
