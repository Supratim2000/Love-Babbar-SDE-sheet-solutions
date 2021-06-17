typedef long long ll;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix.at(0).size();
        //0->right, 1->down, 2->left, 3->up ;
        int dir=0;
        int a=0,b=row-1,c=0,d=col-1;
        while(a<=b && c<=d)
        {
            if(dir==0)
            {
                for(int i=c;i<=d;i++)
                    ans.push_back(matrix[a][i]);
                a++;
            }
            else if(dir==1)
            {
                for(int i=a;i<=b;i++)
                    ans.push_back(matrix[i][d]);
                d--;
            }
            else if(dir==2)
            {
                for(int i=d;i>=c;i--)
                    ans.push_back(matrix[b][i]);
                b--;
            }
            else
            {
                for(int i=b;i>=a;i--)
                    ans.push_back(matrix[i][c]);
                c++;
            }
            
            dir=(dir+1)%4;
        }
        return ans;
    }
};
