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
    int maxFreq =0;
    int currFreq =0;
    int prev  =0;
    vector<int> ans;
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
            inOrder(root->left);

            if(prev == root->val){
                currFreq++;
            }
            else{
                prev = root->val;
                currFreq =1;
            }
            if(currFreq > maxFreq){
                maxFreq = currFreq;
                ans ={};
                ans.push_back(root->val);
            }
            else if(currFreq == maxFreq){
                ans.push_back(root->val);
            }
        
        
        inOrder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};