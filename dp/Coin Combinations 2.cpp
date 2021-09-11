/*
CSES Problem Set -  Coin Combinations II

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
2+2+5
3+3+3
2+2+2+3
Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤106
1≤ci≤106
Example

Input:
3 9
2 3 5

Output:
3


Solution::::
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  int coins[n];
  for(int i=0;i<n;i++){
    cin>>coins[i];
  }

  long long int MOD = 1e9 + 7;
  vector<int> dp(x+1,0); 
  dp[0]=1;

  for(int i=0;i<n;i++){
    for(int j=1;j<x+1;j++){
        if(j-coins[i]>=0){
          dp[j]+=dp[j-coins[i]];
          dp[j] %= MOD;
        }
    }
  }
  cout<<dp[x]<<endl;
}