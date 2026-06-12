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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode* > q;
        bool fromBack=false;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            int numOfNodes = q.size();
            vector<int>levelNodes;
            while(numOfNodes--) {
                TreeNode* cur=q.front();
                q.pop();
                levelNodes.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            if(fromBack) reverse(levelNodes.begin(), levelNodes.end());
            ans.push_back(levelNodes);
            fromBack=!fromBack;
        }
        return ans;
    }
};