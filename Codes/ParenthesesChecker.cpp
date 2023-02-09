// Parentheses Checker using stack

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> baste ;

    string data ; 
    cin>>data ; 

    for (int i = 0; i < data.size(); i++)
    {
        if(data[i] == '(')
        {
            baste.push(1) ; 
        }   
        else if (baste.size() != 0)
        {
            baste.pop() ; 
        }
        else
        {   
            cout<<"no" ; 
            return 0 ; 
        } 
        

    }
    if(baste.size() == 0)
    {
        cout<<"yes" ; 

    }
    else cout<<"no" ; 


    return 0 ;
}
