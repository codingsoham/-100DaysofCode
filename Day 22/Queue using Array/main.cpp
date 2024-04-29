#include <bits/stdc++.h>

using namespace std;

class Queue{
public:
    int front,rear,cnt,max_size;
    int *arr;

    Queue(int ms=16):front{0},rear{0},cnt{0},max_size{ms}{
        arr=new int[ms];
    }
    ~Queue(){
        delete []arr;
    }
    int top(){
        if(cnt!=0)
            return arr[front%max_size];
        return -1;
    }
    int pop(){
        if(cnt!=0){
            int num=arr[front];
            cnt--;
            arr[front++%max_size]=-1;

            return num;
        }
        return -1;
    }

    void push(int x){
        if(cnt<max_size){
            arr[rear++%max_size]=x;
            cnt++;
        }
    }
    int size(){
        return cnt;
    }
    bool empty(){
        return (cnt)?false:true;
    }
    void display(){
        cout<<"[ ";
        for(int i=front;i<rear;i++)
            cout<<arr[i%max_size]<<" ";
        cout<<"]"<<endl;
    }
    
};

int main(){
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    q.push(8);
    q.push(7);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout<<"Elements before deletion.: ";
    q.display();
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;
    cout<<"Elements after deletion.: ";
    q.display();
    return 0;
}

