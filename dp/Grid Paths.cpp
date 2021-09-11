/*
CSES Problem Set
Grid Paths
TASK SUBMIT RESULTS STATISTICS HACKING
Time limit: 1.00 s Memory limit: 512 MB
Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square where you only can move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.

Output

Print the number of paths modulo 109+7.

Constraints
1≤n≤1000
Example

Input:
4
....
.*..
...*
*...

Output:
3


Solution::::

*/



#include <bits/stdc++.h>
using namespace std;

const long long int m = 1e9 +7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	char mat[n][n];
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
	}

	int dp[n][n];

	for(int i=0;i<n;i++){
        if(mat[0][i]=='*'){
            dp[0][i]=0;
            while(i<n){
                dp[0][i]=0;
                i++;
            }
        }
        else{
            dp[0][i]=1;
        }
	}

	for(int i=0;i<n;i++){
        if(mat[i][0]=='*'){
            dp[i][0]=0;
            while(i<n){
                dp[i][0]=0;
                i++;
            }
        }
        else{
            dp[i][0]=1;
        }
	}

	for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j]=='*'){
                dp[i][j]=0;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= m;
            }
        }
	}
	cout<<dp[n-1][n-1];
    return 0;

}