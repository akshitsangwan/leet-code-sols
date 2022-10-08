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
    int countNodes(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return (countNodes(root->left)+countNodes(root->right)+1);
    }
    
    
    bool solve(TreeNode* root,int index,int totalNodes)
    {
        if(root==NULL)
            return true;
        
        if(index>=totalNodes)
            return false;
        
        return solve(root->left,2*index+1,totalNodes) && solve(root->right,2*index+2,totalNodes);
    }
    
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return false;
        int totalNodes=countNodes(root);
        int index=0;
        return solve(root,index,totalNodes);
    }
};