//Method 1
//---------------------------------------------------------------------------------------------------
void diagonalLevelTraversal(Node* root,vector<int>& ans)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curNode=q.front();
        q.pop();
        while(curNode)
        {
            ans.push_back(curNode->data);
            if(curNode->left)
                q.push(curNode->left);
            curNode=curNode->right;
        }
    }
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root==nullptr)
        return ans;
    diagonalLevelTraversal(root,ans);
    return ans;
   
}
//---------------------------------------------------------------------------------------------------

//Method 2
//---------------------------------------------------------------------------------------------------
void preOrder(Node* root,map<int,vector<int>>& dLevel,vector<int>& ans,int level)
{
    if(root==nullptr)
        return;
    dLevel[level].push_back(root->data);
    preOrder(root->left,dLevel,ans,level+1);
    preOrder(root->right,dLevel,ans,level);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int,vector<int>> dLevel;
    if(root==nullptr)
        return ans;
    preOrder(root,dLevel,ans,0);
    for (auto x :dLevel)
    {
        vector<int> curVector=x.second;
        for(auto y:curVector)
          ans.push_back(y);
    }
    return ans;
}
//---------------------------------------------------------------------------------------------------
