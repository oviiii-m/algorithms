class Solution {
public:
    // int t[201][201];
//     int solve(int n,int m,vector<vector<int>>& grid){
//        if(n<=0 || m<=0) return INT_MAX; 
//         if(n==1 && m==1) return grid[0][0];
//         if(t[n][m]!=-1) return t[n][m];
        
//         int a = solve(n-1,m,grid) ;
//         int b = solve(n,m-1,grid) ;
//         return t[n][m] =  min(a,b) + grid[n-1][m-1];
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t[n][m];
        t[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t[i][j] = grid[i][j];
                int temp = INT_MAX;
                if(i-1>=0){
                    temp = min(temp,t[i-1][j]);
                }
                if(j-1>=0){
                    temp = min(temp,t[i][j-1]);
                }
                if(temp!=INT_MAX) t[i][j]+=temp;
            }
        }
        return t[n-1][m-1];
       
    }
};
