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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == nullptr) return ans;

        q.push(root);
        int cntlevel =1;

        while (!q.empty()){
            int size = q.size();
            vector<int> level;
            if(cntlevel%2 !=0){
                for(int i =0; i<size; i++){
                TreeNode* node = q.front();     //use of queues
                q.pop();
                if(node->left  != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->val);
                }
            }
            else{
                for(int i =0; i<size; i++){
                TreeNode* node = q.front();     //use of queues
                q.pop();
                
                if(node->left  != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->val);
                }
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            cntlevel++;
        }
        return ans;
    }
};