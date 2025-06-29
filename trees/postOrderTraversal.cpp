// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//   void postOrder(TreeNode* root, vector<int> &t) {
//     if (root == nullptr)
//       return;
    
//     postOrder(root->left, t);
//     postOrder(root->right,t);
//     t.push_back(root->val);
//   }
// public:
//   vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> t;
//     postOrder(root, t);
//     return t;
//   }
// };