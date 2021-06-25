vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    if(root==nullptr)
        return res;
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        Node* curNode=pendingNodes.front();
        res.push_back(curNode->data);
        pendingNodes.pop();
        if(curNode->right!=nullptr)
            pendingNodes.push(curNode->right);
        if(curNode->left!=nullptr)
            pendingNodes.push(curNode->left);
    }
    reverse(res.begin(),res.end());
    return res;
}
