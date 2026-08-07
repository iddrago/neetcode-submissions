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
    void dfs(TreeNode* root, vector<int> &cont){
        if(root==NULL) return;
        cont.push_back(root->val);
        dfs(root->left,cont);
        dfs(root->right,cont);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> cont;
        dfs(root,cont);
        sort(cont.begin(),cont.end());
        return cont[k-1];
    }
};
