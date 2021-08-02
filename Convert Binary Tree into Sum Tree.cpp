class Solution {
  public:
    void toSumTree(Node *node)
    {
        if(node->left==nullptr && node->right==nullptr)
            node->data=0;
        else
        {
            if(node->left && node->right)
            {
                int leftVal=node->left->data;
                int rightVal=node->right->data;
                toSumTree(node->left);
                toSumTree(node->right);
                node->data=leftVal+rightVal+node->left->data+node->right->data;
            }
            else if(node->left)
            {
                int leftVal=node->left->data;
                toSumTree(node->left);
                node->data=node->left->data+leftVal;
            }
            else
            {
                int rightVal=node->right->data;
                toSumTree(node->right);
                node->data=node->right->data+rightVal;
            }
        }
    }
};
