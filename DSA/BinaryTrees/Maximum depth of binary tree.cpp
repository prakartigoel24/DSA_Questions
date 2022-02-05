//LINK : https://leetcode.com/problems/maximum-depth-of-binary-tree/

//USING RECURSION
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        int lh=1+ maxDepth(root->left);
        int rh=1+ maxDepth(root->right);
        
        return max(lh, rh);
        
    }
};
