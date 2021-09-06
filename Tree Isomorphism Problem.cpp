class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        bool isRootValSame=root1->data==root2->data;
        bool isoFirst=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
        bool isoSecond=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
        return isRootValSame && (isoFirst || isoSecond);
    }
};
