/*
class TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};


*/

/*

void pre(TreeNode* root, vector<int> &t) {
        if (root == nullptr) {
            return;
        }
        // root, left, right
        t.push_back(root->val);
        pre(root->left, t);
        pre(root->right, t);
}

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> t;
        pre(root, t);
        return t;
}
        
*/