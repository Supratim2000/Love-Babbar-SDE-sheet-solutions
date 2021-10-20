class Solution {
{
    public:    
        vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> temp;
            vector<int> common;
            int i=0;
            int j=0;
            while(i<n1 && j<n2)
            {
                if(A[i]==B[j])
                {
                    if(!temp.size() || A[i]!=temp.at(temp.size()-1))
                        temp.push_back(A[i]);
                    i++;
                    j++;
                }
                else if(A[i]<B[j])
                    i++;
                else
                    j++;
            }
            i=0;
            j=0;
            while(i<temp.size() && j<n3)
            {
                if(temp[i]==C[j])
                {
                    if(!common.size() || temp.at(i)!=common.at(common.size()-1))
                        common.push_back(temp.at(i));
                    i++;
                    j++;
                }
                else if(temp.at(i)<C[j])
                    i++;
                else
                    j++;
            }
            return common;
        }
};
