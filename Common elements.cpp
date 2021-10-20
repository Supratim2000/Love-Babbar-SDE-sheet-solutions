//Approach 1
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
    
//Approach 2
    class Solution
{
    public:    
        vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> common;
            int i=0;
            int j=0;
            int k=0;
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k])
                {
                    if(common.size()== 0 || A[i]!=common.at(common.size()-1))
                        common.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j] && A[i]<C[k])
                    i++;
                else if(B[j]<A[i] && B[j]<C[k])
                    j++;
                else if(C[k]<A[i] && C[k]<B[j])
                    k++;
                else if(A[i]==B[j])
                {
                    i++;
                    j++;
                }
                else if(B[j]==C[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    i++;
                    k++;
                }
            }
            return common;
        }
};
