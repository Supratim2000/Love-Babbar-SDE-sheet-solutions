//APPROACH 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int src_row=0;
        if(matrix.size()==0 || matrix[0].size()==0 || matrix[matrix.size()-1][matrix[0].size()-1]<target)
            return 0;
        int r=matrix.size();
        int c=matrix.at(0).size();
        int l=0;
        int h=r-1;
        int mid;
        while(l<=h)
        {
            mid=l+((h-l)/2);
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]<target)
            {
                src_row=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }

        int low=0;
        int high=matrix[src_row].size()-1;
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(matrix[src_row][mid]>target)
                high=mid-1;
            else if(matrix[src_row][mid]<target)
                low=mid+1;
            else
                return true;
        }
        return false;
    }
};


//APPROACH 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix.at(0).size();
        int l=0;
        int h=row*col-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(matrix[mid/col][mid%col]==target)
                return true;
            else if(matrix[mid/col][mid%col]>target)
                    h=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};
