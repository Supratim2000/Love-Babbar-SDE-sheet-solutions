class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> rightView;
        if(root==nullptr)
            return rightView;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        rightView.push_back(root->data);
        while(!pendingNodes.empty())
        {
            bool flag=true;
            int n=pendingNodes.size();
            for(int i=0;i<n;i++)
            {
                Node* curNode=pendingNodes.front();
                pendingNodes.pop();
                if(curNode->right!=nullptr)
                {
                    if(flag)
                    {
                        rightView.push_back(curNode->right->data);
                        flag=false;
                    }
                    pendingNodes.push(curNode->right);
                }
                if(curNode->left!=nullptr)
                {
                    if(flag)
                    {
                        rightView.push_back(curNode->left->data);
                        flag=false;
                    }
                    pendingNodes.push(curNode->left);
                }
            }
            flag=true;
        }
        return rightView;
    }
};
