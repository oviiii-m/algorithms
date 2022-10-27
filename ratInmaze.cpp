#include<iostream>
using namespace std;
void helper(int maze[][20], int **sol, int n, int r, int c)
{
    if(r == n-1 && c == n-1){
        sol[r][c] =1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << sol[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    // if(r>=n && c>=n && sol[r+1][c]==1 && sol[r-1][c]==1 && sol[r][c+1]==1 && sol[r][c-1]==1){
    //     return;
    // }
    if(r>=n || c>=n || r<0 || c<0 || maze[r][c]==0 || sol[r][c]==1){
        return;
    }
    sol[r][c] = 1;
    helper(maze, sol, n, r-1, c); 		//4 possible directions
    helper(maze, sol, n, r+1, c);
    helper(maze, sol, n, r, c-1);
    helper(maze, sol, n, r, c+1);
    sol[r][c] = 0;
    
}
void ratInAMaze(int maze[][20], int n){
	int **sol = new int*[n]{0};
    for(int i=0; i<n; i++){
        sol[i] = new int[n]{0};
    }
	helper(maze, sol, n, 0, 0);
}
int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}
