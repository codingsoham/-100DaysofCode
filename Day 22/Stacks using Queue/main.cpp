#include <bits/stdc++.h>

using namespace std;

//single queue
// class Stack{
//     queue<int> q;
// public:
//     Stack()=default;
//     void push(int x){
//         q.push(x);
//         for(size_t i=0;i<q.size()-1;i++){
//             q.push(q.front());
//             q.pop();
//         }
//     }
//     int pop(){
//         int x=q.front();
//         q.pop();
//         return x;
//     }
//     int top(){
//         return q.front();
//     }
//     bool empty(){
//         return q.empty();
//     }
//     int size(){
//         return q.size();
//     }

// };

//double queue
class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    Stack()=default;
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
    }
    int pop(){
        int x=q1.front();
        q1.pop();
        return x;
    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
    int size(){
        return q1.size();
    }
};
int main() {
  Stack s;
  s.push(3);
  s.push(2);
  s.push(4);
  s.push(1);
  cout << "top of the stack: " << s.top() << endl;
  cout << "size of the stack before removing element: " << s.size() << endl;
  cout << "The deleted element is: " << s.pop() << endl;
  cout << "top of the stack after removing element: " << s.top() << endl;
  cout << "size of the stack after removing element: " << s.size();

}