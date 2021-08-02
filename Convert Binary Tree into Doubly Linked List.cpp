class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    pair<Node*,Node*> convert(Node *root)
    {
        pair<Node*,Node*> finalRes;
        if(!root)
        {
            finalRes.first=nullptr;
            finalRes.second=nullptr;
        }
        else if(root->left==nullptr && root->right==nullptr)
        {
            finalRes.first=root;
            finalRes.second=root;
        }
        else if(root->left && root->right)
        {
            pair<Node*,Node*> leftll=convert(root->left);
            pair<Node*,Node*> rightll=convert(root->right);
            leftll.second->right=root;
            root->left=leftll.second;
            rightll.first->left=root;
            root->right=rightll.first;
            finalRes.first=leftll.first;
            finalRes.second=rightll.second;
        }
        else if(root->left)
        {
            pair<Node*,Node*> leftll=convert(root->left);
            leftll.second->right=root;
            root->left=leftll.second;
            finalRes.first=leftll.first;
            finalRes.second=root;
        }
        else
        {
            pair<Node*,Node*> rightll=convert(root->right);
            root->right=rightll.first;
            rightll.first->left=root;
            finalRes.first=root;
            finalRes.second=rightll.second;
        }
        return finalRes;
    }
    
    Node* bToDLL(Node *root)
    {
        pair<Node*,Node*> resultLL=convert(root);
        Node* head=resultLL.first;
        return head;
    }
};
