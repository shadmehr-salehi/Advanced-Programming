/*
there is a given n*n Array by user , 0's are paths and 1's are walls so we can't go through 1's 
this code calculates is there a way from A[0][0] to A[n-1][n-1] or no 
EG : 
5
0 0 0 1 0
1 1 0 0 0
0 0 0 0 0
1 1 1 1 0
1 1 1 1 0

Expected out = YES 
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 20, inf = 1e9 + 69, delta = 1e9 + 7;

#define all(x) (x).begin(), (x).end()

int inp(){
    int x;
    cin >> x;
    return x;
}

bool grid[10][10];

bool dfs(int x, int y, int n){
    if(x < 0 or x == n or y < 0 or y == n or grid[x][y])
        return false;
    grid[x][y] = 1;
    return ((x == n - 1 and y == n - 1) or (dfs(x - 1, y, n) or dfs(x + 1, y, n) or  dfs(x, y - 1, n) or dfs(x, y + 1, n)));


}

int main(){

    int n = inp();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    if(dfs(0, 0, n))
        cout << "YES";
    else
        cout << "NO";
