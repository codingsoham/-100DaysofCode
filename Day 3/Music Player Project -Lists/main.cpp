#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>

using namespace std;


class Song{
private:    
    string name;
    string author;
    int rating;

    friend ostream &operator<<(ostream&,const Song&);

public:
    Song()=default;
    Song(string name,string author,int rating)
        :name{name},author{author},rating{rating}{}

    bool operator<(const Song &rhs)const{
        return rating<rhs.rating;
    }

    bool operator==(const Song &rhs)const{
        return (name==rhs.name&&author==rhs.author&&rating==rhs.rating);
    }

    string get_author()const{return author;}
    string get_name()const{return name;}
    int get_rating()const{return rating;}
};

ostream &operator<<(ostream &os,const Song &obj){
    os<<setw(20)<<left<<obj.name<<setw(30)<<setw(30)<<obj.author<<setw(2)<<obj.rating;

    return os;
}

void display_menu(){
    cout<<"\nF -  Play First Song"<<endl;
    cout<<"N -  Play Next Song"<<endl;
    cout<<"P -  Play Previous Song"<<endl;
    cout<<"A -  Add and play a new Song at current location."<<endl;
    cout<<"L -  List the current playlist"<<endl;
    cout<<setw(49)<<setfill('=')<<""<<endl;
    cout<<setfill(' ');
    cout<<"Enter a selection (Q to quit): ";
}

void play_current_song(const Song &cs){
    cout<<"Playing: "<<endl<<cs<<endl;
}

void display_playlist(list<Song> songs,const Song &cs){
    for(const auto &dis:songs)
        cout<<dis<<endl;
    play_current_song(cs);
}

void input_file(ifstream &in_file,list<Song> &songs){
    string line;

    for(int i=1;getline(in_file,line);i++){
        if(i==1)
            continue;
        int c1=line.find(',');
        string name=line.substr(0,c1);
        int c2=line.find(',',c1+1);
        string author=line.substr(c1+1,c2-c1-1);
        int rating = stoi(line.substr(c2 + 1));

        songs.emplace_back(name,author,rating);
    }
}
void update_file(const Song &c_obj,const Song &i_obj,ifstream &in_file,ofstream &out_file){
    string line;
    string search=c_obj.get_name()+","+c_obj.get_author()+","+to_string(c_obj.get_rating());
    
    in_file.clear();  
    in_file.seekg(0);

    while(getline(in_file,line)){
        if(line==search)
            out_file<<i_obj.get_name()<<","<<i_obj.get_author()<<","<<i_obj.get_rating()<<endl;
        
        out_file<<line<<endl;
    }
    in_file.close();  
    out_file.close(); 

    
    remove("songs.csv");
    rename("temp.csv", "songs.csv");

}
int main() {
    ifstream in_file{"songs.csv"};
    ofstream out_file{"temp.csv"};

    if(!in_file){
        cerr<<"Error opening file.";
        in_file.close();
        return 1;
    }

    if(!out_file){
        cerr<<"Error writing file.";
        out_file.close();
        return 1;
    }

    list<Song> songs;

    bool cond=true;
    
    input_file(in_file,songs);
    auto it=songs.begin();

    display_playlist(songs,*it);
    do{
    char c;
    display_menu();
    cin>>c;

    switch(tolower(c)){
        case 'f':
            it=songs.begin();
            play_current_song(*it);
        break;
        case 'n':
            if(++it==songs.end()){
                cout<<"Wrapping to start of playlist"<<endl;
               it++; 
            }
            play_current_song(*it);
        break;
        case 'p':
            if(it==songs.begin()){
                cout<<"Wrapping to end of playlist"<<endl;
               it--;
            }
            it--; 
            play_current_song(*it);
        break;
        case 'a':{
            cout<<"Adding and playing new song"<<endl;
            string name;
            string artist;
            int rating;

            cout << "Enter Song Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Song artist: ";
            getline(cin, artist);

            cout << "Enter your rating (1-5): ";
            cin >> rating;
            cin.ignore(); 

            update_file(*it,Song{name,artist,rating},in_file,out_file);
            
            in_file.open("songs.csv");
            out_file.open("temp.csv");
            
            songs.emplace(it,name,artist,rating);
            it--;
            play_current_song(*it);
        }break;
        case 'l':            
            display_playlist(songs,*it);
        break;
        case 'q':
            cond=false;
        break;
        default:
            cout<<"Invalid Input. Try Again!!";

    }
    }while(cond);

    cout<<"Thanks for Listening!!";
    in_file.close();
    out_file.close();
    getchar();
    return 0;
}