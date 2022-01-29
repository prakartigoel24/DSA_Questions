//LINK : https://leetcode.com/problems/binary-tree-preorder-traversal/

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

//RECURSIVE APPROACH
class Solution {
vector<int> v;    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root!=NULL)
        {
            v.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
  
        }
        
        return v;
    }
};
