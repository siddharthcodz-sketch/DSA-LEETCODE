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
    int totalSum(TreeNode* root,int& maxs){
        if(root == nullptr) return 0;
    
        int ls = totalSum(root->left,maxs);
            ls = max(ls,0);

        int rs = totalSum(root->right,maxs);
            rs = max(rs,0);
        maxs = max(maxs,root->val+ls+rs);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int maxs = root->val;
        int ans = totalSum(root,maxs);
        return maxs;
    }
};