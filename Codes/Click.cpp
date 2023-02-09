// code to calcuate how many times our variable changed it's value 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[1000] ; 
    int n ;
    cin>>n ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>A[i] ; 
    }
    for (int i = 0 ; i < n - 1 ; i++) 
    {
        if (A[i] != A[i+1] )
        {
            ans ++ ; 
        }
    }
    cout << ans ;  

    return 0 ;    
}
