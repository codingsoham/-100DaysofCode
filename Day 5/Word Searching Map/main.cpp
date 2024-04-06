#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

string clean_string(const string &s){
    string result;

    for(char c:s){
        if(c=='.'||c==','||c==':'||c==';')
            continue;
        result+=c;
    }

    return result;
}

void display_words(const map<string,int> &m){
    cout<<setw(12)<<left<<"\nWords"
        <<setw(7)<<right<<"Count"<<endl;
    cout<<"=====================================================\n";
    for(const auto &dis:m)
        cout<<setw(12)<<left<<dis.first
            <<setw(7)<<right<<dis.second<<endl;
        
}

void display_words(const map<string,set<int>> &words){
     cout<<setw(12)<<left<<"\nWords"
        <<"Occurences"<<endl;
    cout<<"==========================================================\n";
    for(const auto &dis:words){
        cout<<setw(12)<<left<<dis.first
            <<left<<"[ ";
        for(const auto &dis2:dis.second)
            cout<<dis2<<" ";
        cout<<" ]"<<endl;
    }
}

void part1(){
    cout<<"Part1==========================================================================="<<endl;
    ifstream in_file{"words.txt"};

    if(!in_file){
        throw runtime_error{"Error opening file: words.txt"};
    }

    map<string,int> count;

    string w;

    while(in_file>>w){
        w=clean_string(w);
        count[w]++;
    }

    in_file.close();
    display_words(count);

}

void part2(){
    cout<<"Part2==========================================================================="<<endl;
    ifstream in_file{"words.txt"};

    if(!in_file){
        throw runtime_error{"Error opening file: words.txt"};
    }

    map<string,set<int>> occur;

    string line;
    int l=1;
    while(getline(in_file,line)){
        istringstream input{line};
        string w;

        while(input>>w){
        w=clean_string(w);        
        occur[w].emplace(l);
        }
        l++;
    }

     display_words(occur);

    in_file.close();
}

int main() {
    part1();
    part2();
    return 0;
}