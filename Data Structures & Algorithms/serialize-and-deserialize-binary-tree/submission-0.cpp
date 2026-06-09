/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs(data, i);
    }
private:
    TreeNode* dfs(string& data, int& i) {
            string temp = "";
            while(i < data.size() && data[i] != ',') {
                temp += data[i++];
            }
            i++;
            if(temp == "N") return nullptr;

            TreeNode* root = new TreeNode(stoi(temp));
            root->left = dfs(data, i);
            root->right = dfs(data, i);
            return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));