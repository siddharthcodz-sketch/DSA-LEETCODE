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
//SO ITS A COMPLETE BINARY TREE ALL LEVELS ARE COMPLETY FILLED EXCEPT LAST AND 2.LEFT ASSOCIATIVE
    int countLeftHeight(TreeNode* root){
        TreeNode* temp = root;
        int lh = 0;
        while (temp)
        {
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int countRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int rh = 0;
        while (temp){
            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = countLeftHeight(root);
        int rh = countRightHeight(root);

        if(lh == rh ) return pow(2,lh)-1;

        return countNodes(root->left) + countNodes(root->right) +1;
    }
};