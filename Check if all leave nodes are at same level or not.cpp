class Solution{
  public:
    //Returns if leaves are at same level and height of tree
    pair<bool,int> solve(Node* root)
    {
        pair<bool,int> ans;
        if(root==nullptr)
        {
            ans.first=true;
            ans.second=0;
        }
        else if(root->left==nullptr && root->right==nullptr)
        {
            ans.first=true;
            ans.second=1;
        }
        else if(root->left && root->right)
        {
            pair<bool,int> leftPart=solve(root->left);
            pair<bool,int> rightPart=solve(root->right);
            if(leftPart.first && rightPart.first && leftPart.second==rightPart.second)
            {
                ans.first=true;
                ans.second=leftPart.second+1;
            }
            else
            {
                ans.first=false;
                ans.second=max(leftPart.second,rightPart.second)+1;
            }
        }
        else if(root->left)
        {
            pair<bool,int> leftPart=solve(root->left);
            if(leftPart.first)
            {
                ans.first=true;
                ans.second=leftPart.second+1;
            }
        }
        else
        {
            pair<bool,int> rightPart=solve(root->right);
            if(rightPart.first)
            {
                ans.first=true;
                ans.second=rightPart.second+1;
            }
        }
        return ans;
    }
    
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        pair<bool,int> finalAns=solve(root);
        bool leaveSameLevel=finalAns.first;
        return leaveSameLevel;
    }
};
