class Solution {
public:
    bool isLeaf(Node *root)
    {
        return root->left==nullptr && root->right==nullptr;
    }

    void addLeftBoundary(Node *root,vector<int>& ans)
    {
        if(root==nullptr)
            return;
        if(!isLeaf(root))
            ans.push_back(root->data);
        if(root->left)
            addLeftBoundary(root->left,ans);
        else if(root->right)
            addLeftBoundary(root->right,ans);
    }
    
    void addRightBoundary(Node *root,Node* mainRoot,vector<int>& ans)
    {
        if(root==nullptr)
            return;
        if(root->right)
            addRightBoundary(root->right,mainRoot,ans);
        else if(root->left)
            addRightBoundary(root->left,mainRoot,ans);
        if(!isLeaf(root) && root!=mainRoot)
            ans.push_back(root->data);
    }
    
    void addLeaves(Node* root,vector<int>& ans)
    {
        if(root==nullptr)
            return;
        if(isLeaf(root))
            ans.push_back(root->data);
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }
    
    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
        if(root->left && root->right)
        {
            addLeftBoundary(root,ans);
            addLeaves(root,ans);
            addRightBoundary(root,root,ans);
        }
        else if(root->left)
        {
            addLeftBoundary(root,ans);
            addLeaves(root,ans);
        }
        else
        {
            ans.push_back(root->data);
            addLeaves(root,ans);
            addRightBoundary(root,root,ans);
        }
        return ans;
    }
};
