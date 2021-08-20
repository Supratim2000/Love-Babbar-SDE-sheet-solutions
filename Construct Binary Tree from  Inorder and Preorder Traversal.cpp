class Solution{
    public:
    int getRootIndexInInorer(int in[],int inS,int inE,int rootVal)
    {
        for(int i=inS;i<=inE;i++)
            if(in[i]==rootVal)
                return i;
        return INT_MIN;
    }
    
    Node* create(int in[],int pre[],int inS,int inE,int preS,int preE)
    {
        if(inS>inE || preS>preE)
            return nullptr;
        
        int rootVal=pre[preS];
        int rootInInorderIndex=getRootIndexInInorer(in,inS,inE,rootVal);
        
        int lInS=inS;
        int lInE=rootInInorderIndex-1;
        int lpreS=preS+1;
        int lpreE=lInE-lInS+lpreS;
        int rInS=rootInInorderIndex+1;
        int rInE=inE;
        int rpreS=lpreE+1;
        int rpreE=preE;
    
        Node* leftSubTree=create(in,pre,lInS,lInE,lpreS,lpreE);
        Node* rightSubTree=create(in,pre,rInS,rInE,rpreS,rpreE);
    
        Node* root=new Node(rootVal);
    
        root->left=leftSubTree;
        root->right=rightSubTree;
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int inS=0;
        int inE=n-1;
        int preS=0;
        int preE=n-1;
        Node* root=create(in,pre,inS,inE,preS,preE);
        return root;
    }
};
