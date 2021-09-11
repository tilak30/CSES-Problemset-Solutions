/*
CSES Problem Set - Dice Combinations

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input

The only input line has an integer n.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n≤106
Example

Input:
3

Output:
4

Solution::::

*/


#include <bits/stdc++.h>
 
using namespace std;
 
long long int solve(int n){
    long long int dp[n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
            dp[i]=0;
        for(int j=1;j<=6;j++){
            if(i-j>=0)
                dp[i]+=dp[i-j];
            dp[i]%=1000000007;
        }
    }
    return dp[n];
}
 
int main()
{
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}