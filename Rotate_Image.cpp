class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int l=0;
        int h=n-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                swap(matrix[i][j],matrix[j][i]);
        
        while(l<h)
        {
            for(int i=0;i<n;i++)
                swap(matrix[i][l],matrix[i][h]);
            l++;
            h--;
        }
    }
};
