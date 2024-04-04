#include <iostream>
#include <set>

using namespace std;

class Person{
private:
    string name;
    int age;
    friend ostream &operator<<(ostream&,const Person&);

public:
    Person();
    Person(string,int);
    bool operator==(const Person&)const;
    bool operator<(const Person&)const;
};

Person::Person()
    :Person{"Unknown",0}{}

Person::Person(string name,int age)
    :name{name},age{age}{}

bool Person::operator==(const Person &rhs)const{
    return (rhs.age==age&&rhs.name==name);
}
bool Person::operator<(const Person &rhs)const{
    return age<rhs.age;
}

ostream &operator<<(ostream &os,const Person &obj){
    os<<obj.name<<" :"<<obj.age;

    return os;
}

template<typename T>
void display(const set<T> &l){
    cout<<"[ ";

    for(const auto &dis:l)
        cout<<dis<<" ";
    
    cout<<"]"<<endl;
}
void test1(){
    cout<<"Test1========================================================================="<<endl;
    set<int> s1{1,4,3,5,2};
    display(s1);

    s1={1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if(s1.count(10))
        cout<<"10 is in the set."<<endl;

    auto it=s1.find(5);

    if(it!=s1.end())
        cout<<"Found: "<<5<<endl;

    s1.clear();

    display(s1);
}

void test2(){
    cout<<"Test2========================================================================="<<endl;

    set<Person> stooges{
        {"Larry",1},
        {"Moe",2},
        {"Curly",3}
    };
    display(stooges);

    stooges.emplace("James",50);
    display(stooges);

    stooges.emplace("Frank",50);
    display(stooges);

    auto it=stooges.find(Person{"Moe",2});

    if(it!=stooges.end())
        stooges.erase(it);
    display(stooges);

    it=stooges.find(Person{"XXX",50});
     if(it!=stooges.end())
        stooges.erase(it);
    display(stooges);
}

void test3(){
    cout<<"Test2========================================================================="<<endl;
    set<string> s{"A","B","C"};
    display(s);

    auto result=s.insert("D");
    cout<<boolalpha;
    cout<<"first: "<<*(result.first)<<endl;
    cout<<"second: "<<result.second<<endl<<endl;
    display(s);

    result=s.insert("A");
    cout<<"first: "<<*(result.first)<<endl;
    cout<<"second: "<<result.second<<endl;

}
int main() {
    test1();
    test2();
    test3();
    return 0;
}