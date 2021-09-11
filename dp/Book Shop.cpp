/*

CSES Problem Set - Book Shop

You are in a book shop which sells n different books. You know the price and number of pages of each book.

You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.

Input

The first input line contains two integers n and x: the number of books and the maximum total price.

The next line contains n integers h1,h2,…,hn: the price of each book.

The last line contains n integers s1,s2,…,sn: the number of pages of each book.

Output

Print one integer: the maximum number of pages.

Constraints
1≤n≤1000
1≤x≤105
1≤hi,si≤1000
Example

Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.


Solution ::::::
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if (left >= 0) {
	dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
}