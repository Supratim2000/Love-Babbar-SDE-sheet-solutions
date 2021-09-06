class Solution {
public:
    void inorder(TreeNode* root,vector<int>& arr)
    {
        if(!root)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    TreeNode* convert(vector<int>& sorted,int l,int h)
    {
        if(l>h)
            return nullptr;
        int mid=l+(h-l)/2;
        TreeNode* newRoot=new TreeNode(sorted[mid]);
        TreeNode* newLeft=convert(sorted,l,mid-1);
        TreeNode* newRight=convert(sorted,mid+1,h);
        newRoot->left=newLeft;
        newRoot->right=newRight;
        return newRoot;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root,sorted);
        int l=0;
        int h=sorted.size()-1;
        root=convert(sorted,l,h);
        return root;
    }
};
