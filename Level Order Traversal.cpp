class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        Node* root=node;
        vector<int> arr;
        if(root==nullptr)
            return arr;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            Node* cur=pendingNodes.front();
            arr.push_back(cur->data);
            pendingNodes.pop();
            if(cur->left!=nullptr)
                pendingNodes.push(cur->left);
            if(cur->right!=nullptr)
                pendingNodes.push(cur->right);
        }
        return arr;
    }
};
