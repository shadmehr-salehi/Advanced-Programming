// polynomial class for subtract , sum , derivative , calculate number in polynomial and more
#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 ; 

class Polynomial
{
public : 
    int CoffArray[MaxN] ; 
    int Coefficients[MaxN] ;
    int Coefficients2[MaxN] ; 

    Polynomial operator +(Polynomial coe)
    {
        for(int i = 0; i < x ; i++)
        {
            int o = coe.get(i);
            int y = Coefficients[i];
            coe.SetCoefficient(i, o+y);
            Coefficients[i] = o+y ;
        }
        return coe;
    }
    Polynomial operator -(Polynomial coe)
    {
        for(int i = 0; i < x; i ++)
        {
            int o = coe.get(i);
            int y = Coefficients[i];
            coe.SetCoefficient(i, o-y);
            Coefficients[i] = o-y;
        }
        return coe;
    }
    Polynomial operator *(Polynomial coe)
    {
        int ans [MaxN] ;
        for(int i = 0; i < x; i ++)
        {
            for(int j = 0; j < x ; j ++)
            {
                int o = coe.get(i);
                int y = Coefficients[i];
                ans[i+j] += o*y;
            }
        }
        for(int i = 0; i < x; i ++)
        {
            coe.SetCoefficient(i, ans[i]);
            Coefficients[i] = ans[i];
        }
        return coe;
    }
    int get(int index)
    {
        return Coefficients[index] ;
    }
    void Setx(int n )
    {   
        x = n ; 
    }
    void seth(int n )
    {
        h = n ;
    }
    void setIndex(int n)
    {
        index = n ; 
    }
    void setValue(int n)
    {
        value = n ; 
    }
    void SetCoefficient(int index , int value)
    {
        Coefficients[index] = value ; 
    }
    int GetCoefficients()
    {
        for (int i = 0 ; i < x ; i++)
        {
            cout<<Coefficients[i] ; 
        }
    }
    int Calculate(int h)
    {
        long long ans = 0;
        for(int i = 0; i < x ; i ++){
            long long y = 1;
            for(int j = 0; j < i; j ++)
            y = y * h;
            ans = ans + y * Coefficients[i];
        }   
        cout << ans << endl;
    }
    void SetPolynomial(int CoffArray[MaxN])
    {
        for(int i = 0; i < x; i ++){
            
            Coefficients[i] = CoffArray[i];
        }
    }
    void Derivative()
    {
    for(int i = 0; i < x; i ++)
    {
        Coefficients[i] = (i+1)*Coefficients[i+1] ;
    }
    x--;
    for(int i = 0; i < x; i ++)
    {
        cout << Coefficients[i] << " " ;
    }
    cout<<"\n" ; 
    } 
    void YekBeDo(int Coefficients2[MaxN])
    {
    for(int i = 0 ; i < x ; i ++)
    {
        Coefficients[i] = Coefficients2[i];
    }
    }

    
    




private :  
    int value ;
    int index ;
    int x ;
    int h ; 


};

int main()
{


    Polynomial j , k ; 

    int n ; 
    int a ; 
    

    string ope ; 
    
    cin>>n ; 
    j.Setx(n) ; 
    for (int i = 0 ; i < n ; i++)
    {
        cin>>a ;
        j.Coefficients[i] = a ;
    } 
    while (ope != "exit")
    { 
    cin>>ope ; 
    if(ope == "GetCoefficients")
    {
        j.GetCoefficients() ; 
    }
    if(ope == "SetCoefficient")
    {
        int x , y ;
        j.SetCoefficient(x,y) ; 
    }    
    if(ope == "Calculate")
    {
        int h ; 
        cin>>h ;
        j.seth(h) ; 
        j.Calculate(h) ; 
    }
    if(ope == "Derivative")
    {
        j.Derivative() ; 
    }
    if(ope =="SetPolynomial")
    {
        int Arr[MaxN] ; 
        for(int i = 0; i < n; i ++)
        {
            cin >> Arr[i];
        }
        j.SetPolynomial(Arr);
    }
    if(ope == "Add")
    {
        j + k ;
    }
    if(ope == "Sub")
    {
        j - k ;
    }
    if(ope == "Mul")
    {
        j * k ;
    }
    }
    if(ope == "exit")
    {
        return 0 ; 
    }

    return 0 ;    
}
