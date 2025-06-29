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
private:
void inOrder(TreeNode* root, vector<int> &t) {
  if (root == nullptr) return;
  
  inOrder(root->left, t);
  t.push_back(root->val);
  inOrder(root->right, t);

}
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int>t;
      inOrder(root, t);
      return t;
    }
};