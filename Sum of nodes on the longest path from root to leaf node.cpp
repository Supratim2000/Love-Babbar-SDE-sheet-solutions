class Solution
{
public:
    bool isLeaf(Node* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    void traverse(Node *root,int curHeight,int curSum,int& maxHeight,int& maxSum)
    {
        if(root==nullptr)
            return;
        curSum+=root->data;
        
        if(isLeaf(root) && curHeight>=maxHeight)
        {
            maxHeight=curHeight;
            maxSum=max(maxSum,curSum);
        }
        
        traverse(root->left,curHeight+1,curSum,maxHeight,maxSum);
        traverse(root->right,curHeight+1,curSum,maxHeight,maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxHeight=0;
        int maxSum=1;
        traverse(root,0,0,maxHeight,maxSum);
        return maxSum;
    }
};
