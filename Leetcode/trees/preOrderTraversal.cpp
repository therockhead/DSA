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

// pre order recursive dfs
private:
void pre(TreeNode* root, vector<int> &t) {
        if (root == nullptr) {
            return;
        }
        // root, left, right
        t.push_back(root->val);
        pre(root->left, t);
        pre(root->right, t);
}
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> t;
        pre(root, t);
        return t;
    }
};