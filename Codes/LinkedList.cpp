// linked list class with some functions 
#include <bits/stdc++.h>
using namespace std;

class node
{
public :
    node (int x) 
    {
        next = NULL ; 
        item = x ; 
    }
    void Insertion(int x)
    {
        if(next == NULL) 
        {
            node* New = new node(x) ;
            next = New ; 
        }
        else 
        {
            node* New = new node(x) ; 
            node* Old = next ; // 
            next = New ; // 1xsdfsfegw
            New->next = Old ; 
        }
    }
    void Deletion()
    {
        if(next == NULL)
        {
            return ; 
        }
        else 
        {
            next = next->next ; 
        }
    }
    int Del()
    {
        if(next == NULL)
        {
            return 1 ; 
        }
        else 
        {
            int tmp = next->Del() ;
            if (tmp == 0 ) return 0 ; 
            else if (tmp == 1) Deletion() ; 
            return tmp-1 ;  
        }       
    }
    void Display()
    {
        if(next == NULL) return ;
        else
        {
            next->Display() ;
            cout<< next->item<<" " ; 
        }
    }
    int Search(int x)
    {
        if(next == NULL) return 0 ;
        else
        {
            int tmp = next->Search(x) ;
            if (tmp > 0) return tmp ;
            else if(next->item == x) return -tmp+1 ;
            else
            {
                return tmp -1 ; 
                
            }
        }
    }
    void Delete(int x)
    {
        if (next == NULL) return ;
        else
        {
            if(next->item == x)
            {
                Deletion() ; 
            }
            else
            {
                next->Delete(x) ; 
            }
        }

    }


private:
    int item ; 
    node* next = NULL ;
};



int main()
{
    node head(0) ; 

    string op ;
    while (op != "exit")
    {
        cin>>op ; 
        if (op == "Insertion")
        {
            int x ;
            cin>>x ; 
            head.Insertion(x) ;
        }
        if(op == "Deletion")
        {
            head.Del();
        }
        if(op == "Display")
        {
            head.Display();
            cout<<"\n" ; 
        }
        if(op =="Search")
        {
            int x ; 
            cin>>x ; 
            cout<<head.Search(x) -1 ;
            cout<<"\n" ;   
        }
        if (op == "Delete")
        {
            int x ; 
            cin>> x ; 
            head.Delete(x); 
        }
        if (op == "exit")
        {
            return 0 ; 
        }
    }
    



    return 0 ;    
}
