#include <bits/stdc++.h>
using namespace std;

struct Class
{
    int idno ;
    vector<vector<int> > nomre ;
};

double SemAvg (Class & A , int t )
{
    double ans = 0 ;
    for (int i = 0 ; i < A.nomre[t].size() ; i++)
        ans += A.nomre[t][i] ;
    ans = ans/A.nomre[t].size() ;
    return ans ;
}




int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<Class> Daneshjo ;
    //
    while (true){
        string op ;
        cin>>op ;
        if(op == "add") {
            Class temp ;
            cin>>temp.idno;
            Daneshjo.push_back(temp) ;
        }


        //<c1, c2, ..., c10,..., cn, temp>
        //69
        if(op == "new_semester"){
            int id ;
            int vahed;
            vector<int> nomarat ;

            cin>>id>>vahed ;
            for (int i = 0 ; i < vahed ; i++){
                int nomre ;
                cin>>nomre ;
                nomarat.push_back(nomre) ;
            }

            int i = 0 ;
            for (; i < Daneshjo.size() ; i++)
                if(Daneshjo[i].idno == id ) break ;

            sort(nomarat.begin() , nomarat.end()) ;
            reverse(nomarat.begin() , nomarat.end()) ;

            Daneshjo[i].nomre.push_back(nomarat) ;

            }

            if(op == "grades" ){

                int id , term ;
                cin>>id>>term ;
                term -- ;

                for (int i = 0 ; i < Daneshjo.size() ; i++){
                    if (Daneshjo[i].idno == id){
                        for (int j = 0 ; j < Daneshjo[i].nomre[term].size() ; j++)
                            cout<<Daneshjo[i].nomre[term][j]<<" ";

                        cout<<endl ;
                    }
                }
            }

             if(op =="semester_avg" ){
                int id ;
                int term ;
                cin>>id>>term ;
                term -- ;

                int i = 0 ;
                for (; i<Daneshjo.size() ; i++ )
                    if(Daneshjo[i].idno == id) break ;

                cout << fixed << setprecision(2)<< SemAvg(Daneshjo[i] , term)<<endl ;
            }

             if(op == "avg"){
                int id ;
                cin>>id ;

                int i = 0 ;
                for (; i<Daneshjo.size() ; i++ )
                    if(Daneshjo[i].idno == id) break ;

                double ans = 0 ;
                int cnt = 0;
                for ( int j = 0 ; j < Daneshjo[i].nomre.size() ; j++)
                    for(int h  = 0; h < Daneshjo[i].nomre[j].size(); h++){
                        ans += Daneshjo[i].nomre[j][h];
                        cnt++;
                    }
                ans = ans / cnt;
                cout << fixed << setprecision(2)<< ans <<endl ;
                }

                if (op == "exit")
                    exit (0) ;
    }

}
/*
add 999
new_semester 999 5 20 20 20 10 15
new_semester 999 5 20 20 20 2 0
new_semester 999 3 15 12 3
add 500
new_semester 500 12 1 2 3 4 5 6 7 8 9 10 11 12
grades 999 1
avg 500
semester_avg 999 2
exit
*/
