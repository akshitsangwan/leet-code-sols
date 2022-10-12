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
    TreeNode* findPred(TreeNode* root)
    {
        TreeNode* pred = root;
        while (pred->right!=NULL)
        {
            pred=pred->right;
        }
        return pred;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;

    if(root->val==key)
    {
        // 0 child waala case
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child waala case
        if(root->left!=NULL && root->right==NULL)
        {
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        // 2 child waala case
        if(root->left!=NULL && root->right!=NULL)
        {
            // Pehle inorder predecessor nikala
            int pred=findPred(root->left)->val;
            // fir target node par copy krwadiya
            root->val=pred;
            //fir pred ko delete kra diya
            root->left=deleteNode(root->left,pred);
            return root;
        }
    }
    else if(key>root->val)
        root->right=deleteNode(root->right,key);
    else
        root->left=deleteNode(root->left,key);
        
    return root;
    }
};