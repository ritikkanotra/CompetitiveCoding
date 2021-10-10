#include <iostream>
#include <vector>
using namespace std;

 int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 & j == 0){continue;}
                if(i == 0){grid[i][j] += grid[i][j-1];}
                else if(j == 0){grid[i][j] += grid[i-1][j];}
                else{grid[i][j] += min(grid[i-1][j], grid[i][j-1]);}
            }
        }
        return grid[n-1][m-1];
    }
    
int main()
{
   int n, m;
   cout << "Enter the number of rows and columns in the grid: ";
   cin >> n >> m;
   vector<vector<int>> grid(n, vector<int>(m, 0));
   cout << "Enter the elements of the grid: ";
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++){
           int temp;
           cin >> temp;
           grid[i][j] = temp;
       }
   }
   cout << "The minimum path sum from top left of the grid to the bottom right is: ";
   cout << minPathSum(grid) << endl;
   return 0;
}
