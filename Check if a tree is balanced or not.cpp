class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isLeaf(Node* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    //<isBalanced,height>
    pair<bool,int> check(Node *root)
    {
        pair<bool,int> ans;
        if(root==nullptr)
        {
            ans.first=true;
            ans.second=0;
        }
        if(isLeaf(root))
        {
            ans.first=true;
            ans.second=1;
        }
        if(root->left && root->right)
        {
            pair<bool,int> left=check(root->left);
            pair<bool,int> right=check(root->right);
            if(abs(left.second-right.second)<=1 && left.first && right.first)
                ans.first=true;
            else
                ans.first=false;
            ans.second=max(left.second,right.second)+1;
        }
        else if(root->left)
        {
            pair<bool,int> left=check(root->left);
            if(left.second==1 && left.first)
                ans.first=true;
            else
                ans.first=false;
            ans.second=left.second+1;
        }
        else if(root->right)
        {
            pair<bool,int> right=check(root->right);
            if(right.second==1 && right.first)
                ans.first=true;
            else
                ans.first=false;
            ans.second=right.second+1;
        }
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        pair<bool,int> result=check(root);
        return result.first;
    }
};
