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
    // void preorder(TreeNode* root,vector<int>& ans){
    //     TreeNode* temp = root;
    //     if(temp == nullptr) return;
    //     // cout<<temp->data<<" ";
    //     ans.push_back(temp->val);
    //     preorder(temp->left,ans);
    //     preorder(temp->right,ans);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     preorder(root,ans);
    //     return ans;         
    // }

    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else {
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {        // first visit
                ans.push_back(curr->val);
                pred->right = curr;
                curr = curr->left;
            }
            else {                            // second visit — thread exists
                pred->right = NULL;           // restore
                curr = curr->right;
            }
        }
    }
    return ans;
}

};