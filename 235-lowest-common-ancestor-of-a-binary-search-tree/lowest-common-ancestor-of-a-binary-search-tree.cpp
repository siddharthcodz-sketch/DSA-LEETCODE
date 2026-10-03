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
//BRUTE FORCE TCHINQUE BCZ OF CALL STACK IN RECURSION IT IS TAKING o(H) AS SPACE 
/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL ) return nullptr;

    if(p->val < root->val && q->val < root->val && root->left){
        return lowestCommonAncestor(root->left,p,q);
    }

    if(p->val > root->val && q->val > root->val && root->right){
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
    }
*/
// SO OPTIMAL WE DONT CALL RECURSION WE JUST MOVE THROUGH NODE AS ITTERATION AND WHEN WE FOUND WE JUST RETURN
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL){
            return root;
        }
        while(root) {
            if(root->left&& p->val < root->val && q->val<root->val){
                root = root->left;
            }
            else if(root->right && p->val > root->val && q->val >root->val){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }

};