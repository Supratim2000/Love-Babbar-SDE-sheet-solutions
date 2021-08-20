//Method 1(Using Queue and Iteration)
//---------------------------------------------------------------------------------------------------
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root==nullptr)
        return ans;
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
    return ans;
}
//---------------------------------------------------------------------------------------------------

//Method 2(Using Map and Recursion)
//---------------------------------------------------------------------------------------------------
void traverse(Node* root,int leftSpreadLevel,map<int,vector<int>>& diagonalLevel)
{
    if(!root)
        return;
    diagonalLevel[leftSpreadLevel].push_back(root->data);
    traverse(root->left,leftSpreadLevel+1,diagonalLevel);
    traverse(root->right,leftSpreadLevel,diagonalLevel);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    int leftSpreadLevel=0;
    map<int,vector<int>> diagonalLevel;
    traverse(root,leftSpreadLevel,diagonalLevel);
    for(auto x: diagonalLevel)
        for(auto y: x.second)
            ans.push_back(y);
    return ans;
}
//---------------------------------------------------------------------------------------------------
