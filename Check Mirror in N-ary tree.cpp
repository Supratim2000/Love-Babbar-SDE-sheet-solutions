class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int> ftree[n+1];
        vector<int> stree[n+1];
        
        for(int i=0;i<2*e;i+=2)
        {
            ftree[A[i]].push_back(A[i+1]);
            stree[B[i]].push_back(B[i+1]);
        }
        for(int i=1;i<=n;i++)
        {
            if(ftree[i].size()==stree[i].size())
            {
                int low=0;
                int high=ftree[i].size()-1;
                while(low<=high)
                {
                    if(ftree[i][low++]!=stree[i][high--])
                        return false;
                }
            }
            else
                return false;
        }
    }
};
