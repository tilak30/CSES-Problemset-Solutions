/*
CSES Problem Set
Counting Rooms

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n and m: the height and width of the map.

Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3


Solution :::
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define INF (int)1e9
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
 
int n, m, answer = 0;
int vis[1010][1010];
char grid[1010][1010];
 
bool isValid (int y, int x) {
  if (y < 0) return false;
  if (x < 0) return false;
  if (y >= n) return false;
  if (x >= m) return false;
  if (grid[y][x] == '#') return false;
  return true;
}
 
void DFS (int y, int x) {
  vis[y][x] = 1;
  for (int i = 0 ; i < 4 ; i++) {
    int newX = x + neighborX[i];
    int newY = y + neighborY[i];
    if (isValid(newY, newX)) {
      if (!vis[newY][newX]) {
        DFS(newY, newX);
      }
    }
  }
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
        vis[i][j] = 0;
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.' && !vis[i][j]) {
          DFS(i, j);
          answer++;
        }
      }
    }
    cout << answer << endl;
    return 0;
 
}