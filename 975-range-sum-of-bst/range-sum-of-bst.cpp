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
// TRING TO TRAVERSE EVEVRY NODE AS IF EXCLUDING RANGE (VERY SIMPLE)
    
    int sum =0;
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     if(root == nullptr) return 0;
    //     rangeSumBST(root->left, low, high);
    //     if(root->val >=low && root->val <= high){
    //         sum+= root->val;
    //     }
    //     rangeSumBST(root->right, low, high);
    //     return sum;
    // }


    //TAKING Benifts of BINARY-SEARCH-TREE
    int rangeSumBST(TreeNode* root, int low, int high){
        if(root == nullptr) return 0;
        if(root->val >=low && root->val <= high){
            return root->val + rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high); 
        }
        else if(root->val < low){
            return rangeSumBST(root->right,low,high);
        }
        return rangeSumBST(root->left,low,high);
    }
};