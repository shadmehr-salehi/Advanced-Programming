// class for creating a new article with details
#include <bits/stdc++.h>
using namespace std;

class Article
{
public :
    
    void SetAuthorName(string esm) {
        AuthorName = esm;
    }
    void SetArticleName(string esm)
    {
        if (ValidateArticleName(esm)) ArticleName = esm ;     
    }
    void SetYear(int esm)
    {
        if (ValidateYear(esm)) year = esm ;  
    }
    void SetContext(string esm)
    {   
        if(ValidateContext(esm)) Context = esm;
        
    }    


    int GetYear() {
        return year;
    }

    string GetContext()  {
        return Context;
    }

    string GetArticleName() {
        return ArticleName;
    }


    string GetAuthorName()  {
        return AuthorName;
    }




private:
    string ArticleName ; 
    string AuthorName ; 
    int year ;
    string Context ; 
    
    bool ValidateArticleName(string s)
    {
        return s.length() <= 30 ;  
    }
    bool ValidateAuthorName(string s )
    {
        return s.length() <= 30 ; 
    }
    bool ValidateYear(int adad)
    {
        return ((adad/1000 >0)&&(adad/10000 <1)); 
    }
    bool ValidateContext(string mohtava)
    {
        return mohtava.length() <= 500 ; 
    }

};




int main()
{


    Article Maghale ; 

    string Article_Name ; 
    string Author_Name ;
    string Context ; 
    int Year ; 

    cin>>Year ; 
    Maghale.SetYear(Year) ; 


    getline(cin >> ws , Article_Name) ;
    Maghale.SetArticleName(Article_Name) ; 

    getline(cin , Author_Name) ; 
    Maghale.SetAuthorName(Author_Name) ;

    getline(cin , Context) ; 
    Maghale.SetContext(Context) ;

    cout<<Maghale.GetArticleName()<<endl<<Maghale.GetYear()<<endl<<Maghale.GetAuthorName()<<endl<<Maghale.GetContext();



    return 0 ;    
}
