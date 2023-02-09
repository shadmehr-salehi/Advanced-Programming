// simple library with some functions 

#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<string> list ; 

    int n ; 
    cin>>n ; 
    string esm ;

    for(int i = 0 ; i< n ; i++)
    {
        
        getline(cin >> ws , esm) ;
        list.push_back(esm) ; 
    }
    string op; 
    while (true)
    {
        getline(cin ,op) ; 
        if(op == "AddLeft")
        {
            getline(cin , esm) ; 
            list.push_front(esm) ; 
        }
        if(op == "AddRight")
        {
            getline(cin , esm); 
            list.push_back(esm) ;
        }
        if(op == "DeleteLeft")
        {
            list.pop_front();

        }
        if(op == "Exit")
        {
            cout<<list.size()<<"\n" ;
            while(!list.empty())
            {
                cout<<list.front()<<"\n" ;
                list.pop_front() ; 
            }
            return 0 ; 
        }
    
    }

    


    return 0 ;    
}
