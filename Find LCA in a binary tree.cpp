class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q); 
        if(left && right)
            return root;
        else if(left || right)
        {
            if(root==p)
                return p;
            else if(root==q)
                return q;
            return left?left:right;
        }
        else
        {
            if(root==p)
                return p;
            else if(root==q)
                return q;
            return nullptr;
        }
    }
};
