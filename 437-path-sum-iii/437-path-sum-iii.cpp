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
    int count=0;
    
    void solve(TreeNode* root,int targetSum,long long int sum)
    {
        if(root==NULL)
            return;
        if(sum==targetSum)
            count++;
        
        if(root->left!=NULL)
            solve(root->left,targetSum,sum+root->left->val);
        if(root->right!=NULL)
            solve(root->right,targetSum,sum+root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        
        // jis node par khade ho usse starting point maan kar path nikal lo
        solve(root,targetSum,root->val);
        
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return count;
    }
};