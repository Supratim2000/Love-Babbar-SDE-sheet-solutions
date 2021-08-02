class Solution
{
    pair<bool,int> solve(Node* root)
    {
        pair<bool,int> ans;
        if(!root)
        {
            ans.first=true;
            ans.second=0;
        }
        else if(root->left==nullptr && root->right==nullptr)
        {
            ans.first=true;
            ans.second=root->data;
        }
        else if(root->left && root->right)
        {
            pair<bool,int> leftPart=solve(root->left);
            pair<bool,int> rightPart=solve(root->right);
            root->data==leftPart.second+rightPart.second?ans.first=true:ans.first=false;
            ans.second=leftPart.second+rightPart.second+root->data;
        }
        else if(root->left)
        {
            pair<bool,int> leftPart=solve(root->left);
            root->data==leftPart.second?ans.first=true:ans.first=false;
            ans.second=leftPart.second+root->data;
        }
        else
        {
            pair<bool,int> rightPart=solve(root->right);
            root->data==rightPart.second?ans.first=true:ans.first=false;
            ans.second=rightPart.second+root->data;
        }
        return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
        pair<bool,int> finalRes=solve(root);
        bool ifSumTree=finalRes.first;
        return ifSumTree;
    }
};
