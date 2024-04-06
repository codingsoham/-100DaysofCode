#include <iostream>
#include <queue>
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
    //return age<rhs.age;
    return name<rhs.name;
}

ostream &operator<<(ostream &os,const Person &obj){
    os<<obj.name<<" :"<<obj.age;

    return os;
}

template<typename T>
void display(priority_queue<T> pq){
    cout<<"[ ";
    while(!pq.empty()){
        T elem=pq.top();
        pq.pop();
        cout<<elem<<" ";
    }
    cout<<"]"<<endl;
}
void test1(){
    cout<<"Test1======================================================================================"<<endl;

    priority_queue<int> pq;
    for(int i:{3,5,7,12,23,12,4,100,0,3,5,7})
        pq.push(i);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top: "<<pq.top()<<endl;

    display(pq);
    pq.pop();
    display(pq);
}
void test2(){
    cout<<"Test1======================================================================================"<<endl;

    priority_queue<Person> pq;

    pq.push(Person{"A",10});
    pq.push({"B",1});
    pq.push({"C",14});
    pq.push({"D",18});
    pq.push({"E",7});
    pq.push({"F",27});

    display(pq);

}
int main() {
    test1();
    test2();
    return 0;
}