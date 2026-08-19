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
    int maxHeight(TreeNode* root,int & maxd){
        if(root == NULL) return 0;
        int lh = maxHeight(root->left,maxd);

        int rh = maxHeight(root->right,maxd);
        maxd = max(maxd, lh + rh);
        return 1+max(lh,rh);
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxd= 0;
        maxHeight(root,maxd);
        return maxd;        
    }
};