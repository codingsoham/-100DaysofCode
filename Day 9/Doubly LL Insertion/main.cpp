#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data,Node *next=nullptr,Node *back=nullptr)
        :data{data},next{next},back{back}{}
};
Node *vec2DLL(vector<int> vec){
    Node *head=new Node{vec.at(0)};
    Node *temp=head;

    for(size_t i=1;i<vec.size();i++){
        temp->next=new Node{vec.at(i),nullptr,temp};
        temp=temp->next;
    }

    return head;
}

void printdll(Node *head){
    Node *temp=head;
    cout<<"[ ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"]"<<endl;
}
Node *insertbhead(Node *head,int val){
    Node *temp=new Node{val,head,nullptr};
    head->back=temp;
    return temp;;
}
Node *insertbtail(Node *head,int val){
    if(head->next==nullptr)
        return insertbhead(head,val);
    Node *temp=head;

    while(temp->next){
        temp=temp->next;
    }
    temp->back->next=new Node{val,temp,temp->back};
    temp->back=temp->back->next;

    return head;
}
Node *insertbkey(Node *head,int val,int k){
    if(k==1)
        return insertbhead(head,val);
    Node *temp=head;
    int cnt{};
    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    temp->back->next=new Node{val,temp,temp->back};
    temp->back=temp->back->next;

    return head; 
}
void insertbnode(Node *node,int val){
    node->back->next=new Node{val,node,node->back};
    node->back=node->back->next;

}
int main(){
    vector<int> vec{1,2,3,4,5};
    Node *head=vec2DLL(vec);
    printdll(head);

    cout<<"\ninsertion before head: \n";
    head=insertbhead(head,100);
    printdll(head);

    cout<<"\ninsertion before tail: \n";
    head=insertbtail(head,20);
    printdll(head);

    cout<<"\ninsertion before key(4): \n";
    head=insertbkey(head,20,1);
    printdll(head);

    cout<<"\ninsertion before node: \n";
    insertbnode(head->next->next,69);
    printdll(head);

    return 0;
}