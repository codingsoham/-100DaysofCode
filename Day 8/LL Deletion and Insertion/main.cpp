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
void printLL(Node *head){

    Node *mover=head;
    cout<<"[ ";
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<"]";
}

Node *removehead(Node *head){
    if(head==nullptr) return head;
    Node *temp=head;
    head=head->next;
    delete temp;

    return head;
}
Node *removetail(Node *head){
    if(head==nullptr||head->next==nullptr)
        return nullptr;

    Node *temp=head;

    while(temp->next->next!=nullptr)
        temp=temp->next;
    
    delete temp->next;
    temp->next=nullptr;

    return head;
}
Node *removekelement(Node *head,int k){
    if(head==nullptr||k>lengthofLL(head))
        return head;
    if(k==1){
        Node *temp=head;
        head=head->next;
        delete temp;

        return head;
    }
        int count{};
        Node *temp=head;
        Node *prev=nullptr;
        while(temp) {
            count++;
            if(count==k){
                prev->next=prev->next->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;            
        }

        return head;
    
}
Node *deleteel(Node *head,int el){
    if(head==nullptr)
        return head;

    if(head->data==el){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node *temp=head;
    Node *prev=head;

    while(temp){
        if(temp->data==el){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;
}

Node *inserthead(Node *head,int val){
    return new Node{val,head};
}
Node *inserttail(Node *head,int val){
    if(head==nullptr)
        return new Node{val};
    Node *temp=head;

    while(temp->next){
        temp=temp->next;
    }
    temp->next=new Node{val};

    return head;
}

Node *insertkelement(Node *head,int val,int k){
    if(head==nullptr){
        if(k==1)
            head=new Node{val};
        return head;
    }

    if(k==1){
        return new Node{val,head};        
    }
    int count=0;
    Node *temp=head;
    while(temp){
        count++;
        if(count==k-1){
            temp->next=new Node{val,temp->next};
            break;
        }
        temp=temp->next;
    }

    return head;
    
}
int main(){
    vector<int> vec{12,5,6,8};
    Node *head=convertvec2LL(vec);

    // cout<<"\nLength of the Linked List is: "<<lengthofLL(head)<<endl;
    // cout<<boolalpha;
    // cout<<checkifpresent(head,6);

    printLL(head);

    head=insertkelement(head,100,3);
    cout<<"\nAfter Removing k(3) element: "<<endl;
    printLL(head);

    return 0;
}