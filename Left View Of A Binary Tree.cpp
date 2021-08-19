//Method 1(BFS)
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

//Method 2(DFS)
void traverse(Node *root,int height,int& maxHeightTillNow,vector<int>& view)
{
    if(root==nullptr)
        return;
    if(height>maxHeightTillNow)
    {
        maxHeightTillNow=height;
        view.push_back(root->data);
    }
    traverse(root->left,height+1,maxHeightTillNow,view);
    traverse(root->right,height+1,maxHeightTillNow,view);
}

vector<int> leftView(Node *root)
{
    vector<int> view;
    int maxHeightTillNow=-1;
    if(root==nullptr)
        return view;
    traverse(root,0,maxHeightTillNow,view);
    return view;
}
