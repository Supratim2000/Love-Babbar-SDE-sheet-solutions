class Solution {
public:
    void addLeft(Node* root, vector<int>& ans)
    {
        if(root==nullptr)
            return;
        if(root->left)
        {
            ans.push_back(root->data);
            addLeft(root->left,ans);
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            addLeft(root->right,ans);
        }
    }
    
    void addLeaf(Node* root,vector<int>& ans)
    {
        if(root==nullptr)
            return;
        addLeaf(root->left,ans);
        if(root->left==nullptr && root->right==nullptr)
            ans.push_back(root->data);
        addLeaf(root->right,ans);
    }
    
    void addRight(Node* root, vector<int>& ans)
    {
        if(root==nullptr)
            return;
        if(root->right)
        {
            addRight(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            addRight(root->left,ans);
            ans.push_back(root->data);
        }
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
        if(root->left==nullptr && root->right==nullptr)
            ans.push_back(root->data);
        else if(root->left==nullptr)
        {
            ans.push_back(root->data);
            addLeaf(root,ans);
            addRight(root,ans);
            ans.pop_back();
        }
        else if(root->right==nullptr)
        {
            addLeft(root,ans);
            addLeaf(root,ans);
        }
        else
        {
            addLeft(root,ans);
            addLeaf(root,ans);
            addRight(root,ans);
            ans.pop_back();
        }
        return ans;
    }
};
