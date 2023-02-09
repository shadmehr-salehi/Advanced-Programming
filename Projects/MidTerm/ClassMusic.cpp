// Storing Music details 
#include <bits/stdc++.h>
using namespace std;

class music 
{
public:
    music(string n )
    {
        name = n ; 
    }
    void PrintSong()
    {
        cout<<name<<"\n" ; 
    }
    string name ; 
};
class album
{
public:
    album(string n , int y )
    {
        name = n ; 
        year = y;  
    }
    void PrintName()
    {
        cout<<name<<" published at "<<year<<"\n" ; 
    }
    bool hasSameName(string n )
    {
        return name == n ;
    }
    void PrintSongs()
    {
        for (int i = 0 ; i<songs.size() ; i++)
        {
            songs[i]->PrintSong();
        }
        if(songs.size() == 0)
        {
            cout<<"no songs found in "<<name<<"\n"; 
        }
    }
    string name ;
    int year ; 
    vector<music*> songs;  
};


class band 
{
public : 
    string name ;
    vector<music*> singles ; 
    vector<album*> albums ; 
    band(string n)
    {
        name = n ;
    }
    void MakeAlbum(album* al)
    {
        albums.push_back(al) ; 
    }
    void AddtoAlbum(string Album ,  music* song)
    {
        for(int i = 0 ; i < albums.size() ; i++)
        {
            if(albums[i]->name== Album)
            {
                albums[i]->songs.push_back(song) ; 
            }
        }
    }
    void MakeSingle(music* single)
    {
        singles.push_back(single) ; 
    }
    void PrintAlbums()
    {
        for (int i = 0 ; i<albums.size() ; i++)
        {
            albums[i]->PrintName() ; 
        }
        if(albums.size() == 0)
        {
            cout<<"no albums by "<< name ; 
        }
    }
    album* has_album(string n )
    {
        for(int i = 0 ; i<albums.size(); i++)
        {
            if(albums[i]->hasSameName(n)) 
            return albums[i] ; 
        }
        return NULL ; 
    }
    void PrintSingles()
    {
        for(int i = 0 ; i<singles.size() ; i++)
        {
            singles[i]->PrintSong() ; 
        }
        if(singles.size() == 0)
        {
            cout<<"no singles found by "<<name<<"\n" ; 
        }
    }

    bool has_name(string n)
    {
        return n == name ; 
    }


};




band* findband(string name, vector<band*> bands) 
{
    for (int i = 0 ; i< bands.size() ; i++)
    {
        if(bands[i]->has_name(name))
        {
            return bands[i] ; 
        }
    }
    return NULL ; 

}
album* findAlbumFromName(string n , vector<band*> bands)
{
    for(int i = 0 ; i < bands.size() ; i++)
    {
        if(bands[i]->has_album(n) != NULL) return bands[i]->has_album(n) ; 
    }
}
vector<string> split(string n) 
{
    stringstream str(n) ; 
    vector<string> splstr ; 
    string word ; 
    while(getline(str , word, ' ')) 
    {
        splstr.push_back(word) ; 
    }
    return splstr ; 
}


int main()
{

    int n ; 
    cin>> n ; 
    int i = 0 ;
    vector<band*> bands ; 
    while (i < n )
    {
        string op ; 
        getline(cin >> ws , op); 
        vector<string> op_splitted ; 
        op_splitted = split(op) ; 
        if (op_splitted[1] =="band" ) //add band system-of-a-down

        {
            string name = op_splitted[2];
            bands.push_back(new band(name)) ; 
        }
        if(op_splitted[1]=="song") //add song chop-suey! by system-of-a-down to toxicity
        {
            string SongName = op_splitted[2]; 
            string BandName = op_splitted[4]; 
            string AlbumName = op_splitted[6];  
            findband(BandName , bands)->AddtoAlbum(AlbumName , new music(SongName)); 
            
        }
        if(op_splitted[1] == "album") //add album toxicity published at 2001 by system-of-a-down
        {
            string AlbumName = op_splitted[2]; 
            string BandName = op_splitted[7];
            int year = atoi(op_splitted[5].c_str())  ; 
            findband(BandName , bands)->MakeAlbum(new album(AlbumName , year)) ; 
            

        } 
        if(op_splitted[1] == "single") //add single nothing-else-matters by metallica

        {
            string BandName = op_splitted[4];
            string SongName = op_splitted[2]; 
            findband(BandName,bands)->MakeSingle(new music(SongName)) ; 


        }
        if(op_splitted[2] =="albums") // print metallica albums
        {
            string BandName = op_splitted[1]; 
            if( findband(BandName,bands)!= NULL)
            {
                findband(BandName,bands)->PrintAlbums() ; 
            }
            else 
            {
                cout<<"no albums by "<<BandName<<" found \n" ;
            }
        }
        if(op_splitted[1] == "songs") //print songs in the-wrong-side-of-heaven

        {
            string AlbumName = op_splitted[3]; 
            findAlbumFromName(AlbumName , bands)->PrintSongs() ;
        }
        if(op_splitted[1] =="singles") //print singles by Guns-N-roses
        {
            string BandName = op_splitted[3]; 
            findband(BandName,bands)->PrintSingles() ;  

        }

        i++ ; 
    }




    return 0 ;    
}
