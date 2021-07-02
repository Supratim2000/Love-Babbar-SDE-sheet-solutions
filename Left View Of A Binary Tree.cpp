vector<int> leftView(Node *root)
{
    vector<int> leftView;
    if(root==nullptr)
        return leftView;
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    leftView.push_back(root->data);
    while(!pendingNodes.empty())
    {
        bool flag=true;
        int n=pendingNodes.size();
        for(int i=0;i<n;i++)
        {
            Node* curNode=pendingNodes.front();
            pendingNodes.pop();
            if(curNode->left!=nullptr)
            {
                if(flag)
                {
                    leftView.push_back(curNode->left->data);
                    flag=false;
                }
                pendingNodes.push(curNode->left);
            }
            if(curNode->right!=nullptr)
            {
                if(flag)
                {
                    leftView.push_back(curNode->right->data);
                    flag=false;
                }
                pendingNodes.push(curNode->right);
            }
        }
        flag=true;
    }
    return leftView;
}
