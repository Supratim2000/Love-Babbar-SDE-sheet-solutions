vector<int> leftView(Node *root)
{
    vector<int> view;
    if(root==nullptr)
        return view;
    int flag=true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curNode=q.front();
            q.pop();
            if(flag)
            {
                view.push_back(curNode->data);
                flag=false;
            }
            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }
        flag=true;
    }
    return view;
}
