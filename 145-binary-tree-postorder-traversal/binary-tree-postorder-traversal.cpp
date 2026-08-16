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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        vector<int> ans;
        if(node == nullptr) return ans;
        stack<TreeNode*> st1;
        stack<int> st2;
        

        st1.push(node);
        while (!st1.empty()){
            TreeNode* temp = st1.top();
            st2.push(temp->val);
            st1.pop();

            if(temp->left  != nullptr ) st1.push(temp->left);
            if(temp->right  != nullptr ) st1.push(temp->right);
        }
        while (!st2.empty()){
            // cout<<st2.top()<<" ";
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};

/*
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

class Solution {
public:
    void postorder(TreeNode* root,vector<int>& ans){
        TreeNode* temp = root;
        if(temp == nullptr) return;
        // cout<<temp->data<<" ";
        postorder(temp->left,ans);
        postorder(temp->right,ans);
        ans.push_back(temp->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

*/