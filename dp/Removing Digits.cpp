/*
CSES Problem Set - Removing Digits

TASK SUBMIT RESULTS STATISTICS
Time limit: 1.00 s Memory limit: 512 MB
You are given an integer n. On each step, you may substract from it any one-digit number that appears in it.

How many steps are required to make the number equal to 0?

Input

The only input line has an integer n.

Output

Print one integer: the minimum number of steps.

Constraints
1≤n≤106
Example

Input:
27

Output:
5

Explanation: An optimal solution is 27→20→18→10→9→0.


Solution::::

*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;  cin>>n;
	int count=0;
  while(n!=0){
    int greatest = -1;
    int fake = n;
    while(fake != 0){
      greatest = max(greatest, (fake % 10));
      fake = fake / 10 ;
    }
    n -= greatest;
    count++;
  }
  cout<<count<<endl;

}