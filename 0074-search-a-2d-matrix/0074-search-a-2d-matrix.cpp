class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x){
        int n=mat.size(),m=mat[0].size();
        int st=0,end=n*m-1,mid=0,mx,my;
        while(st<=end){
            mid=(st+end)/2;
            mx=mid/m;
            my=mid%m;

            if(mat[mx][my]==x)return true;
            
            if(mat[mx][my]<x)st=mid+1;
            else end=mid-1;
        }
        return false;
    }
};