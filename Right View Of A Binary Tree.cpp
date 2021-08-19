//Method 1(BFS)
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> view;
        if(root==nullptr)
            return view;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* curNode=q.front();
                q.pop();
                if(i==n-1)
                    view.push_back(curNode->data);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
        }
        return view;
    }
};

//Method 1(DFS)

