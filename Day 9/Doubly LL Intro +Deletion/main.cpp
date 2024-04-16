#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data,Node *next=nullptr,Node *back=nullptr):data{data},next{next},back{back}{}
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

Node *deletehead(Node *head){
    if(head==nullptr)
        return head;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node *temp=head;
    head=head->next;

    head->back=nullptr;
    temp->next=nullptr;

    delete temp;

    return head;
}
Node *deletetail(Node *head){
    if(head==nullptr)
        return head;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node *temp=head;

    while(temp->next){
        temp=temp->next;
    }

    
    temp->back->next=nullptr;
    temp->back=nullptr;

    delete temp;

    return head;
}
// Node *deletekelement(Node *head,int k){
//     if(head==nullptr)
//         return head;
    
//     if(head->next==nullptr){
//         if(k==1){
//             delete head;
//             return nullptr;
//         }
//         return head;
//     }
//     if(k==1){
//         Node *temp=head;
//         head=head->next;

//         head->back=nullptr;
//         temp->next=nullptr;

//         delete temp;

//         return head;
//     }
//     Node *temp=head;
//     int cnt{};

//     while(temp){
//         cnt++;

//         if(cnt==k){
//             break;
//         }

//         temp=temp->next;
//     }
//     if(temp->back!=nullptr){
//         temp->back->next=temp->next;
//         temp->back=nullptr;
//     }
//     if(temp->next!=nullptr){
//         temp->next->back=temp->back;
//         temp->next=nullptr;
//     }

//             delete temp;

//     return head;
// }

Node *deletekelement(Node *head,int k){
    if(head==nullptr)
        return head;
    
    Node *temp=head;
    int cnt{};

    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }

    if(temp->next==nullptr&&temp->back==nullptr){
        delete temp;
        return nullptr;
    }
    else if(temp->next==nullptr){
        head=deletetail(head);
        return head;
    }
    else if(temp->back==nullptr){
        head=deletehead(head);
        return head;
    }

    temp->back->next=temp->next;
    temp->next->back=temp->back;

    temp->next=nullptr;
    temp->back=nullptr;

    delete temp;

    return head;
}

void deletenode(Node *temp){
    if(temp->next==nullptr){
        temp->back->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }   
        temp->back->next=temp->next;
        temp->next->back=temp->back;
        temp->next=temp->back=nullptr;
        
        delete temp;
        return;
}
int main(){
    vector<int> vec{1,2,3,4,5};
    Node *head=vec2DLL(vec);
    printdll(head);

    cout<<"\nAfter deletion of head: \n";
    head=deletehead(head);
    printdll(head);

    cout<<"\nAfter deletion of tail: \n";
    head=deletetail(head);
    printdll(head);

    cout<<"\nReinitializing dll: \n"<<endl;
    head=vec2DLL(vec);
    printdll(head);
    
     cout<<"\nAfter deletion of k(3) element: \n";
    head=deletekelement(head,3);
    printdll(head);

    deletenode(head->next->next);
    printdll(head);

    return 0;
}