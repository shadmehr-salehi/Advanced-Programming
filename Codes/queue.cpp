// queue class with some fuctions 
#include <bits/stdc++.h>
using namespace std;
vector <int> saf ; 

class saff
{
public : 
    void push(int x)
    { 
        saf.push_back(x); 
    }
    int pop()
    {
        int tmp = saf[0] ; 
        saf.erase(saf.begin()); 
        return tmp ;
    }
    int size()
    {
        return saf.size() ; 
    }
    void revers()
    {
        reverse(saf.begin() , saf.end()) ; 
    }
    int find(int x )
    {
        for(int i = 0 ; i < saf.size() ; i++)
        {
            if(saf[i]==x)
            {
                return i ;
            }
            
        }
        return -1 ; 
    }
    bool isfull()
    {
        if(saf.size()== 100) return true ;

    }
    bool isempty()
    {
        if(saf.size() == 0) return true ;
    }



};



int main()
{

    int x , n ; 
    saff qu ; 
    string op ; 

    while (op != "exit")
    {
        cin>>op ; 
        if(op == "push")
        {
            cin>>x ; 
            qu.push(x) ; 
        }
        if(op == "pop")
        {
            cout<<qu.pop()<<"\n" ; 
        }
        if(op =="size")
        {
            cout<< qu.size()<<"\n" ; 
        }
        if(op == "reverse")
        {
            qu.revers() ; 
        }
        if(op == "find")
        {
            int x ; 
            cin>>x ; 
            cout<<qu.find(x) ; 
        }
        if(op == "isfull")
        {
            if ( qu.isfull() == true ) cout<<"true"<<"\n" ;   
            else cout<<"false"<<"\n" ; 
        }
        if(op == "isempty")
        {
            if(qu.isempty() == true) cout<<"true"<<"\n" ; 
            else cout<<"false"<<"\n" ; 
        }
        if(op =="exit")
        {
            return 0 ; 
        }
        

    }

    return 0 ;    
}

