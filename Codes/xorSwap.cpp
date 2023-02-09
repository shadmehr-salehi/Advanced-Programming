// code to swap to numbers using xor 
#include <bits/stdc++.h>
using namespace std;

void sw(int &a, int &b){
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}


int main()
{
    int a , b ; 
    cin>>a>>b ; 
    sw(a,b) ; 
    cout<<a<< b ; 



    return 0 ;
