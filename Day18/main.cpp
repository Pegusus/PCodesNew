#include <iostream>

using namespace std;
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
    int isSibling(TreeNode *root, TreeNode *a, TreeNode *b)
{
    // Base case
    if (root==NULL)  return 0;

    return ((root->left==a && root->right==b)||
            (root->left==b && root->right==a)||
            isSibling(root->left, a, b)||
            isSibling(root->right, a, b));
}

// Recursive function to find level of Node 'ptr' in a binary tree
int level(TreeNode *root, TreeNode *ptr, int lev)
{
    // base cases
    if (root == NULL) return 0;
    if (root == ptr)  return lev;

    // Return level if Node is present in left subtree
    int l = level(root->left, ptr, lev+1);
    if (l != 0)  return l;

    // Else search in right subtree
    return level(root->right, ptr, lev+1);
}
TreeNode* find(TreeNode* root,int x)
{
    queue<TreeNode*> q;
    TreeNode* ans;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(t->val == x)
            ans = t;
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
    return ans;
}
    bool isCousins(TreeNode* root, int x, int y) {
         if ((level(root,find(root,x),1) == level(root,find(root,y),1)) && !(isSibling(root,find(root,x),find(root,y))))
        return 1;
    else return 0;
    }
};

