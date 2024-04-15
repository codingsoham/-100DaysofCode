#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data,Node *nxt=nullptr):data{data},next{nxt}{}
};

Node *convertvec2LL(const vector<int> &vec){
    Node *head=new Node{vec.at(0)};
    Node *mover=head;
    for(size_t i=1;i<vec.size();i++){
        mover->next=new Node{vec.at(i)};
        mover=mover->next;
    }

    return head;
}

int lengthofLL(Node *head){
    Node *mover=head;
    int count{};
    while(mover!=nullptr){
        mover=mover->next;
        count++;
    }

    return count;
}

bool checkifpresent(Node *head,int val){
    Node *mover=head;
   
    while(mover!=nullptr){
        if(mover->data==val)
            return true;
        mover=mover->next;       
    }

    return false;

}
int main(){
    vector<int> vec{12,5,6,8};
    Node *head=convertvec2LL(vec);
    cout<<head->data<<endl;
    Node *mover=head;
    cout<<"[ ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<"]";

    cout<<"\nLength of the Linked List is: "<<lengthofLL(head)<<endl;
    cout<<boolalpha;
    cout<<checkifpresent(head,6);

    return 0;
}