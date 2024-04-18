#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val,Node *next=nullptr)
        :data{val},next{next}{}
};

Node *convertvec2LL(const vector<int> &vec){
    Node *head=new Node{vec.at(0)};
    Node *mover=head;
    for(size_t i=1;i<vec.size();i++){
        mover->next=new Node{vec.at(i)};
        mover=mover->next;
    }
    mover->next=head;

    return head;
}
void printCLL(Node *head){
    Node *temp=head;

    cout<<"[ "<<temp->data<<" ";
    temp=temp->next;

    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"]"<<endl;;
}
Node *deletehead(Node *head){
    if(head==nullptr||head->next==head)
        return head;
    Node *temp=head->next;
    
    while(temp->next!=head)
        temp=temp->next;

    temp->next=head->next;
    Node *temp1=head;
    head=head->next;
    temp1->next=nullptr;
    delete temp1;

    return head;
}
Node *deletetail(Node *head){
    Node *temp=head;

    while(temp->next->next!=head)
        temp=temp->next;

    Node *ptail=temp->next;
    temp->next=temp->next->next;

    delete ptail;
    return head;
}
Node *deletekelem(Node *head,int k){
    if(head==nullptr)
        return head;
    if(k==1)
        return deletehead(head);
    Node *temp=head->next;
    int cnt{1};

    while(temp!=head){
        cnt++;
        if(cnt==k-1)
            break;

        temp=temp->next;
    }
    if(temp==head)
        return deletetail(head);
    Node *nxt=temp->next;
    temp->next=temp->next->next;
    nxt->next=nullptr;

    delete nxt;

    return head;
}
int main(){
    vector<int> vec{1,2,3,4,5};
    Node *head=convertvec2LL(vec);
    printCLL(head);
    head=deletekelem(head,1);

    printCLL(head);





    return 0;
}