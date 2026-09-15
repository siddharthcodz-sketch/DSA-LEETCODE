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
    // void inorder(TreeNode* root,vector<int>& ans){
    //     TreeNode* temp = root;
    //     if(temp == nullptr) return;
    //     // cout<<temp->data<<" ";
    //     inorder(temp->left,ans);
    //     ans.push_back(temp->val);
    //     inorder(temp->right,ans);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root,ans);
    //     return ans;
    // }

    vector<int> inorderTraversal(TreeNode*  root){
        vector<int> result;

    TreeNode* curr = root;
    while (curr != nullptr){

        if(curr->left == NULL){
            result.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* leftChild = curr->left;
            
            while (leftChild->right != NULL){
                leftChild = leftChild->right;
            }
            leftChild->right = curr;

            TreeNode* temp = curr;
            curr = curr->left;
            temp->left = NULL;//ye back node ko delete
        }
    }
    return result;
    }
};