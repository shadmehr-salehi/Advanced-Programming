// find the biggest common sub string , they can be reversed too 
/* 
EG : 
3
ABCDEF
FEDCAB
GHCDEFJK

Expected output : CDEF 
*/ 

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    string s[n];

    for(int i = 0; i < n; i++)
        cin >> s[i];

    int ans[s[0].size()];
    for(int i = 0; i < s[0].size(); i++)
        ans[i] = 0;

    int final_ans_size = 0;
    for(int i = 0; i < s[0].size(); i++){
        int letter_tmp_ans = s[0].size();
        for(int j = 0; j < n; j++){
            int string_tmp_ans = 0;
            for(int t = 0; t < s[j].size(); t++){
                int string_letter_tmp_ans = 0;
                for(int h = 0; t + h < s[j].size() and i + h < s[0].size(); h++){
                    if(s[j][t + h] == s[0][i + h])
                        string_letter_tmp_ans++;
                    else
                        break;
                }
                string_tmp_ans = max(string_tmp_ans, string_letter_tmp_ans);

                string_letter_tmp_ans = 0;
                for(int h = 0; t - h >= 0 and i + h < s[0].size(); h++)
                    if(s[j][t - h] == s[0][i + h])
                        string_letter_tmp_ans++;
                    else
                        break;
                string_tmp_ans = max(string_tmp_ans, string_letter_tmp_ans);


            }
            letter_tmp_ans = min(letter_tmp_ans, string_tmp_ans);
        }
        final_ans_size = max(final_ans_size, letter_tmp_ans);
        ans[i] = letter_tmp_ans;
    }

    for(int i = 0; i < s[0].size(); i++)
        if(ans[i] == final_ans_size){
            for(int j = 0; j < final_ans_size; j++)
                cout<<s[0][i + j];
            break;
        }



    return 0 ;    
}
