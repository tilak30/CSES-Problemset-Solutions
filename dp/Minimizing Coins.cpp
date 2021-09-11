
/*CSES Problem Set - Minimizing Coins

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Constraints
1≤n≤100
1≤x≤106
1≤ci≤106
Example

Input:
3 11
1 5 7

Output:
3 


Solution:::::

*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;  cin>>n>>x;
	vector<int> v(n);
	for(int &p: v){
        cin>>p;
	}
	long int dp[x+1];
	dp[0]=0;
	for(int i=1;i<=x;i++){
        dp[i]=1000000000;
        for(auto coins: v){
            if(i-coins>=0){
                dp[i]=min(dp[i],dp[i-coins]+1);
            }
        }
	}
	if(dp[x]==1000000000)
        cout<<"-1";
    else
        cout<<dp[x];
}