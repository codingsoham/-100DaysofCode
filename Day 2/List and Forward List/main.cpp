#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

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
void display(const list<T> &l){
    cout<<"[ ";

    for(const auto &dis:l)
        cout<<dis<<" ";
    
    cout<<"]"<<endl;
}
void test1(){
    cout<<"\nTest1============================================================================="<<endl;
    list<int> l1{1,2,3,4,5};
    display(l1);

    list<string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    list<int> l3;
    l3={1,2,3,4,5,6,7,8,9,10};
    display(l3);

    list<int> l4(10,100);
    display(l4);
}
void test2(){
     cout<<"\nTest1============================================================================="<<endl;
     list<int> l1{1,2,3,4,5,6,7,8,9,10};
    display(l1);

    cout<<"Size: "<<l1.size()<<endl;
    cout<<"Front: "<<l1.front()<<endl;
    cout<<"Back: "<<l1.back()<<endl;

    l1.clear();
    display(l1);
     cout<<"Size: "<<l1.size()<<endl;
}
void test3(){
     cout<<"\nTest3============================================================================="<<endl;
     list<int> l1{1,2,3,4,5,6,7,8,9,10};
     display(l1);

     l1.resize(5);
     display(l1);

     l1.resize(10);
     display(l1);

     list<Person> l2;
     l2.resize(5);

     display(l2);
}
void test4(){
    cout<<"\nTest4============================================================================="<<endl;
    list<int> l1{1,2,3,4,5,6,7,8,9,10};
    list<int> l2{1000,2000,3000};
    display(l1);

    auto it=find(l1.begin(),l1.end(),5);

    l1.insert(it,100);
    display(l1);

    l1.insert(it,l2.begin(),l2.end());
    display(l1);

    advance(it,-4);

    cout<<*it<<endl;

    l1.erase(it);
    display(l1);



}
int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}