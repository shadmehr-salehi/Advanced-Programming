// class for working with Comples Numbers 

#include <bits/stdc++.h>
using namespace std;

class complexNum 
{
public:
    void Printnum() 
    {
        cout<<RealPart<<" + "<<ImgPart<<" i";
    }
    complexNum()
    {
        RealPart = 0 ;
        ImgPart = 0 ; 
    }
    complexNum(float a , float b)
    {
        RealPart = a ; 
        ImgPart = b ; 
    }
    complexNum add (complexNum x)
    {
        complexNum z(0,0) ; 
        z.RealPart = x.RealPart + RealPart ; 
        z.ImgPart = x.ImgPart + ImgPart; 
        return z ; 
    }
    complexNum minus(complexNum x)
    {
        complexNum z(0,0) ; 
        z.RealPart = x.RealPart - RealPart ; 
        z.ImgPart = x.ImgPart - ImgPart; 
        return z ; 
    }
    complexNum  multiply(complexNum x)
    {      
        complexNum z(0,0) ;
        z.RealPart = x.RealPart * RealPart - (x.ImgPart * ImgPart);
        z.ImgPart = x.RealPart * ImgPart + (x.ImgPart * RealPart) ; 
        return z;
    }
    complexNum divid(complexNum x)
    {
        complexNum z(0,0) ; 
        z.RealPart = (x.RealPart * RealPart + x.ImgPart * ImgPart ) / (RealPart * RealPart + ImgPart * ImgPart) ; 
        z.ImgPart  = (RealPart * x.ImgPart - x.RealPart * ImgPart) / (RealPart * RealPart + ImgPart * ImgPart) ;        
        return z;

    }
    

private:
    float RealPart; 
    float ImgPart; 
};





int main()
{


    float a , b , c , d ; 
    string op ;  
    cin>>a>>b>>c>>d; 
    complexNum num1(a,b) , num2(c,d) ;
    cin>>op; 
    

    if (op == "+")  num1.add(num2).Printnum() ; 
    if (op == "-")  num1.minus(num2).Printnum() ;
    if (op == "*")  num1.multiply(num2).Printnum();
    if (op == "/")  num1.divid(num2).Printnum() ;

    

    return 0 ;    
}
