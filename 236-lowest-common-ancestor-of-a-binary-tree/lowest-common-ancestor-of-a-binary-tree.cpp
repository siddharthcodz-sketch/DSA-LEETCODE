/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
        if(!root) return NULL;

        if(root == x || root == y){
            return root;
        }

        TreeNode* leftN = lowestCommonAncestor (root->left,x,y);
        TreeNode* rightN = lowestCommonAncestor (root->right,x,y);

        if(leftN != nullptr && rightN != nullptr){
            return root;
        }
        if(leftN != nullptr) return leftN;
        return rightN;
        
    }
};