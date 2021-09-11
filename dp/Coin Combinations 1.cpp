/* 
CSES Problem Set - Coin Combinations I

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
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
8


Solution:::::
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define INF (int)1e9
const long long int m = 1e9 +7;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;  cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++){
        cin>>v[i];
	}
	vector<int> arr(x+1,0);
	arr[0]=1;
 
	for(int i=1;i<=x;i++){
        for(auto c : v){
            if(i-c>=0){
                arr[i]+=arr[i-c];
                arr[i]%=m;
            }
        }
	}
	cout<<arr[x];
    return 0;
 
}