// stocks market simulation with file savings and more 
// run the code and you'll see a little guide 
#include <bits/stdc++.h>
using namespace std;
// ---- A Drunk Man Will Find His Way Home but a Drunk Bird May Get Lost Forever =) ---- //
// ---- Well , let's See will Drunk Man Find His Way Home ? ---- // 

class sahm
{
public : 
    void print()
    {
        cout<<"Symbol : "<<namad<<"\n"<<"shortname : "<<fullname<<"\n"<<"price :"<<price<<"\n"<<"volume :"<<volume<<"\n" ; 
    }  
    void save(ofstream &data)
    {
        data<<namad<<"\n"<<fullname<<"\n"<<price<<"\n"<<volume<<"\n";
    }
    bool has_symbol(string s)
    {
        return namad == s ;
    }
    int getprice()
    {
        return price ; 
    }
    string getsymbol()
    {
        return namad ; 
    }
    sahm(string n , string fn , int p , int v )
    {
        namad = n ; 
        fullname = fn ; 
        price = p ; 
        volume = v ; 
    }
    sahm(ifstream &data)
    {
        data>>namad>>fullname>>price>>volume ;
    }

    private : 
    string namad ; 
    string fullname ; 
    int price ; 
    long long int volume ; 
};

class user  // creating a class for user 
{
public : 
    void printuser()
    {
        cout<<uid<<"\n"<<pass<<"\n"<<name<<"\n"<<Lname<<"\n"<<ID<<"\n"<<CCnum<<"\n"<<shaba<<"\n"<<wallet<<"\n"<<isverified ; 
    }
    bool has_username(string un) 
    {
        return un == uid ; 
    }
    bool has_password(string up) 
    {
        return up == pass ; 
    }
    void Deposit(int n )
    {
        wallet += n ; 
    }
    void withdraw(int n )
    {
        wallet -= n ; 
    }
    void AddDebt(int n)
    {
        debt += n ; 
    }
    void paydebts(int n )
    {
        debt -= n ;
    }
    void setverified (int n)
    {
        isverified = n ; 
    }
    void save(ofstream &data)
    {
        data<<name<<" "<<Lname<<"\n"<<uid<<"\n"<<pass<<"\n"<<ID<<"\n"<<shaba<<"\n"<<CCnum<<"\n"<<wallet<<"\n"<<debt<<"\n"<<isverified<<"\n" ; 
        data << UserStocks.size()<<"\n" ; 
        for(auto it = UserStocks.begin() ; it != UserStocks.end() ; it++)
        {
            data<<it->first <<" "<<it->second<<"\n" ; 
        }
    }
    int getverified()
    {
        return isverified ; 
    }
    int getDebt()
    {
        return debt ; 
    }    
    int getMoney()
    {
        return wallet ; 
    }
    void addstock(string n , int c)
    {
        UserStocks[n] += c ;
    }
    void setuser(string n , string ln , string i , string cc , string sh )
    {
        name = n ;
        Lname = ln ; 
        ID = i ; 
        CCnum = cc ; 
        shaba = sh ;
        isverified = 1 ;
        wallet = 0 ; 
        debt = 0; 
    }
    user (string u , string pas) 
    {
        uid = u ;
        pass = pas ; 
    }      
    user(ifstream &data)
    {
        data>>name>>Lname>>uid>>pass>>ID>>shaba>>CCnum>>wallet>>debt>>isverified ; 
        int tedad = 0 ;
        data >> tedad ; 
        for(int i = 0 ; i < tedad ; i++)
        {
            string s ; 
            int d ; 
            data>>s ;
            data>>d ; 
            UserStocks[s] = d ; 
        }
    }
    void printUserStocks()
    {
        for(auto it = UserStocks.begin() ; it != UserStocks.end() ; it++)
        {
            if(it->second == 0 ) pass ; 
            else 
            {
                cout<<it->first <<" "<<it->second<<"\n" ; 
            }
        }
    }
    bool has_stock(string s)
    {
        if (UserStocks.find(s) != UserStocks.end()) return true ; 
        return false ; 
    }
    bool has_count_stock(string s , int n)
    {
        if(UserStocks[s] < n) return false ;
        return true ; 
    }
    void sell(string n , int c )
    {
        UserStocks[n] -= c ;
    }
private : 
    string name ; 
    string Lname ; 
    string uid;
    string pass;
    string shaba ; 
    string ID ; 
    string CCnum ; 
    int debt  ; 
    int wallet  ; 
    bool isverified ; 
    map<string,int> UserStocks ; 
};


int passcheck(string str) // validate chosen password 
{ 
    int l_case=0, u_case=0, digit=0, special=0;
    int l=str.length(),i;
  
  for(i=0;i<l;i++)
  {
        if(islower(str[i]))
            l_case=1;
        if(isupper(str[i]))
            u_case=1;
        if(isdigit(str[i]))
            digit=1;
        if(!isalpha(str[i]) && !isdigit(str[i]))
            special=1;  
  }
  return(l_case + u_case + digit + special) ; 
};



int main()
{

    ifstream UserData ("users.txt") ; // load users data from file 
    ifstream Stocks_file ("stock_market_data.csv") ; // load stocks file from file 
    vector<sahm> stocks ; // create a vector of stocks 
    vector<user> users ;  // create a vector of users 
    int tedad = 0 ; // user counts 
    UserData >> tedad ; // getting user counts from file
    for(int i = 0 ; i < tedad ; i++) //geting all users data from file 
    {
        user newuser(UserData) ;
        users.push_back(newuser) ; 
    }
    UserData.close() ; // closing the file to save changes 

    string line ; 
    getline(Stocks_file, line) ; // to ignore the first line of the file 
    while(getline(Stocks_file, line)) // getting data from file 
    {
        string id ; 
        string namad ;
        string fullname ;
        string price ;
        string volume ;
        stringstream line_stream (line) ;
        getline(line_stream , id , ',') ;
        getline(line_stream , namad , ',') ;
        getline(line_stream , fullname , ',') ;
        getline(line_stream , price , ',') ;
        getline(line_stream , volume , ',') ;
        sahm newsahm(namad,fullname,atoi(price.c_str()),atoi(volume.c_str())) ; // creating an object with the data pulled 
        stocks.push_back(newsahm) ; // pushing the object to the vector 
    }
    bool lf = 0 ; // checks if user is logged in or not  
    cout<<"Menu : \n register = 1 \n login = 2 \n" ; 
    int CurrentUser = -1 ; // saving current user index 
    string op ; 
    while (op != "exit")
    {
        
        if (lf == 0) getline(cin >> ws  , op) ;
        else op = "2" ; 

        ofstream UserData("users.txt") ; 
        UserData << users.size()<<"\n" ; 
        for(int i = 0 ; i < users.size() ; i++)
        {
            users[i].save(UserData) ; 
        }
        UserData.close() ; 
        if(CurrentUser == -1 ) 
        {
            if (op == "1")  // sign up 
            {
                string un ; 
                string up ; 
                cout<<"please enter your desired username : \n";
                getline(cin , un) ; 
                cout<<"please enter a strong password \n (your password should have at least one capital letter , one digit and one special character ) \n" ;
                getline(cin , up) ; 
                while (passcheck(up) <= 2) // checks if user password is strong enough or not 
                {
                    cout<<"weak password , try another one \n";
                    getline(cin , up) ; 
                } 

                user newuser (un , up) ; 
                cout<<"succsesfully Done ! to complete your profile and access panel please login  \n register = 1 \n login = 2 \n " ;
                users.push_back(newuser) ; // saving new user data 
            }
            
            if(op =="2")
            {   
                int userindex = -1 ; 
                string un ;
                string up ; 
                cout<<"username : " ; 
                getline(cin , un) ; 

                
                 for(int i = 0 ; i < users.size() ; i++) // finding username among all users 
                 {
                     if(users[i].has_username(un))
                     {
                        userindex = i ; 
                        break ; 
                     }
                 }
                if(userindex != -1 ) // check is chosen username is available or not 
                {
                    lf = 0 ;
                    cout<<"password : " ; 
                    getline(cin , up) ; 
                    if(users[userindex].has_password(up) == true) // checks if chosen password for chosen username is correct or not 
                    {
                        cout<<"login succsecful !\n " ; 
                        CurrentUser = userindex ; 
                        if(users[CurrentUser].getverified() == 1)
                        {
                            cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                        }
                    }
                    else  // if first input was wrong , get a new one 
                    {
                        cout<<"invalid password for this username \n Try again : " ;    
                        int flag = 0 ; 
                        while (flag == 0)
                        {
                            
                            getline(cin , up) ; 
                            if(users[userindex].has_password(up) == true) 
                            {
                                cout<<"login successful !\n " ; 
                                if(users[CurrentUser].getverified() == 1)
                                {
                                    cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                                }                 
                                flag = 1 ; 
                                CurrentUser = userindex ; 
                            }
                            else
                            {
                                cout<<"invalid password for this username \n password : " ;  
                            }
                        }
                        
                    }
                }
                else 
                {
                    cout << " invalid username \n" ;   
                    lf = 1 ; 
                }    
                    if(users[CurrentUser].getverified() != 1)
                    {
                        cout<<"in order to access your panel , please complete your profile \n " ; 
                        cout <<"please enter your name \n"; 
                        string name ; 
                        cin>>name ; 
                        cout<<"please enter your last name \n" ; 
                        string Lname ; 
                        cin>>Lname ;
                        cout<<"please enter your ID number\n" ; 
                        string ID ;
                        cin>>ID ;
                        ID = ID.substr(0,10) ; 
                        cout<<"please enter your CC number \n " ; 
                        string CCnum ; 
                        cin>>CCnum ; 
                        CCnum = CCnum.substr(0,10) ;  
                        cout<<"please enter your SHABA\n" ; 
                        string Shaba ;
                        cout<<"IR" ; 
                        cin>>Shaba ; 
                        Shaba = Shaba.substr(0,10) ; 
                        users[CurrentUser].setuser(name,Lname,ID,CCnum,Shaba);
                        cout<<"profile completed successfully\n" ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }

            }            

        }
        else 
        {
            if (op == "1")
            {
                cout<<"Buy panel \n please enter the symbol you want to buy \n" ; 
                string symbol ;
                cin>>symbol ; 
                int index = -1 ; 
                for(int i = 0 ; i < stocks.size() ; i++)
                {
                    if(stocks[i].has_symbol(symbol))
                    {
                        index = i ;
                        break ;
                    }
                }
                if(index == -1)
                {
                    cout<<"symbol not found \n";
                    cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                }
                else 
                {
                    int UserMoney = users[CurrentUser].getMoney() ; 
                    cout<<"your money : "<<UserMoney<<"\n"; 
                    cout<<"how much of "<<stocks[index].getsymbol()<<" do you want to buy : \n";
                    int n ; 
                    cin>>n ;
                    if( n*stocks[index].getprice() < UserMoney)
                    {
                         
                        users[CurrentUser].withdraw(n*stocks[index].getprice()) ;
                        users[CurrentUser].addstock(stocks[index].getsymbol() , n) ;
                        cout<<"Added to your balance \n" ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;

                    }
                    else 
                    {
                        cout<<"insufficient money , please deposit some money and try again \n" ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }


                }



            }
            if (op =="2")
            {
                cout<<"sell panel \n" ;
                cout<<"what do u want to sell \n" ; 
                string s ; 
                cin>>s ; 
                if (users[CurrentUser].has_stock(s))
                {
                    int c ;
                    cout<<"how much do you want to sell \n" ;
                    cin>>c ; 
                    if(users[CurrentUser].has_count_stock(s,c))
                    {
                        users[CurrentUser].sell(s ,c) ; 
                        int money ; 
                        int index ; 
                        for(int i = 0 ; i < stocks.size() ; i++)
                        {
                            if(stocks[i].has_symbol(s))
                            {
                                index = i ;
                                break ;
                            }
                        }
                        money = stocks[index].getprice() * c ; 
                        users[CurrentUser].Deposit(money) ; 
                        cout<<"you've sold your stocks for "<<money<<" tomans \n"; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }
                    else 
                    {
                        cout<<"insufficient amount of "<<s<<"\n" ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }
                }
                else 
                {
                    cout<<"symbol invalid or you don't have this symbol in your balance " ; 
                    cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                }
            }
            if(op == "3")
            {
                // users[CurrentUser].test() ; 
                cout<<"1- deposit \n 2- withdraw \n 3- loan \n 4- pay debts \n" ; 
                string o ; 
                cin>>o ; 
                if(o == "1")
                {
                    cout<<"how much do you want to deposit in tomans : \n" ;
                    int Dmoney ; 
                    cin >> Dmoney ; 
                    users[CurrentUser].Deposit(Dmoney) ;  
                    cout<<"Deposited successfully ! \n" ;
                    cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                }
                if(o == "2")
                {
                    cout<<"how much do you want to withdraw in tomans : \n" ;
                    int Wmoney ; 
                    cin >> Wmoney ; 
                    users[CurrentUser].withdraw(Wmoney) ; 
                    cout<<"Withdrawed successfully ! \n" ;
                    cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                }
                if(o == "3")
                {
                cout<<"how much do you want to borrow: \n " ; 
                int n ;
                cin>>n ;
                if(users[CurrentUser].getDebt() + n < 1000000 )
                    {
                        users[CurrentUser].AddDebt(n) ;
                        users[CurrentUser].Deposit(n) ;
                        cout<<"borrowed successfully !\n " ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }
                    else 
                    {
                        cout<<"you've already reached the maximum amount you can borrow \n please pay your debt so you can borrow again \n " ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit\n" ; 
                    }
                }
                if(o == "4")
                {
                    int debt = users[CurrentUser].getDebt() ; 
                    cout<<debt<<" Tomans"<<"\n" ;
                    cout<<"how much money do you want to pay for your debt \n " ; 
                    int n ;
                    cin>>n ;
                    if (debt < n)

                    {
                        int r = n - debt ; 
                        users[CurrentUser].Deposit(r);
                        users[CurrentUser].paydebts(debt);
                        cout<<"you have paid your debt and you've added "<<r<<" Tomans to your wallet \n" ; 
                        cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                    }
                    else 
                    {
                        users[CurrentUser].paydebts(n) ;
                        if(users[CurrentUser].getDebt() == 0)
                        {
                            cout<<"you've paid your debt" ; 
                            cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                        }                        
                        else 
                        {
                            cout<<"you have paid"<<n<<" Tomans \n remaining debt :"<<users[CurrentUser].getDebt()<<"\n" ;
                            cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                        }
                    }


                }
            }
            if(op == "4")
            {
                cout<<"viewing your balance \n" ;
                cout<<users[CurrentUser].getMoney()<<" Tomans \n" ; 
                users[CurrentUser].printUserStocks() ;
                cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
                 

            }
            if(op == "5")
            {
                cout<<"viewing market ( first 10 stocks ) \n" ;
                for(int i = 0 ; i< 10 ; i++) 
                {
                    stocks[i].print() ;
                    cout<<"\n" ;  
                }
                cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit \n" ;
            }
            if(op == "6")
            {
                cout<<"please enter your information again\n" ;
                cout <<"please enter your name \n"; 
                string name ; 
                cin>>name ; 
                cout<<"please enter your last name \n" ; 
                string Lname ; 
                cin>>Lname ;
                cout<<"please enter your ID number\n" ; 
                string ID ;
                cin>>ID ;
                ID = ID.substr(0,10) ; 
                cout<<"please enter your CC number \n " ; 
                string CCnum ; 
                cin>>CCnum ; 
                CCnum = CCnum.substr(0,10) ;  
                cout<<"please enter your SHABA\n" ; 
                string Shaba ;
                cout<<"IR" ; 
                cin>>Shaba ; 
                Shaba = Shaba.substr(0,10) ; 
                users[CurrentUser].setuser(name,Lname,ID,CCnum,Shaba);
                cout<<"profile completed successfully\n" ; 
                cout<<"menu: \n 1- buy \n 2- sell \n 3- deposit/withdraw money \n 4- view your stocks balance \n 5- view market \n 6- edit your information \n 0-exit\n" ;

            }
            if(op == "0")
            {
                CurrentUser = -1 ; 
                cout<<"Menu : \n register = 1 \n login = 2 \n" ; 
            }
            
            // if(op == "10") users[CurrentUser].printuser() ;

        }

    
    }

    return 0 ;    
}

// Well Well , It Seems Our Drunk Man Found His Way Home =) //
// Uh... , See Ya Soon Mate //
// Good Luck  //
