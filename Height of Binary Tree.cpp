int maxm(int x, int y)
{
    return x>y?x:y;
}
int height(struct Node* node)
{
    return node==NULL?0:maxm(height(node->left),height(node->right))+1;
}
