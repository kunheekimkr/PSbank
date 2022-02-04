#include<iostream>
#include<string>
using namespace std;
typedef struct queue{
    int arr[100000];
    int top;
    int bottom;
}Queue;

void reset(Queue *q){
    q->top=-1;
    q->bottom=0;
}
void push(Queue *q, int x){
    q->top++;
    q->arr[q->top]=x;
}

int pop(Queue *q){
    if(q->top-q->bottom==-1)
        return -1;
    else
        return (q->arr[(q->bottom)++]);
}

int size(Queue *q){
    return (q->top-q->bottom +1);
}

int empty(Queue *q){
    if(q->top-q->bottom==-1)
        return 1;
    else
        return 0;
}

int front(Queue *q){
    if(q->top-q->bottom==-1)
        return -1;
    else
        return q->arr[q->bottom];
}

int back(Queue *q){
    if(q->top-q->bottom==-1)
        return -1;
    else
        return q->arr[q->top];
}

int main(){
    Queue q;
    reset(&q);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push"){
            int x;
            cin >> x;
            push(&q,x);
        }
        else if (str == "pop"){
            cout << pop(&q) << '\n';
        }
        else if (str == "size"){
            cout << size(&q) << '\n';
        }
        else if (str == "empty"){
            cout << empty(&q) << '\n';
        }        
        else if (str == "front"){
            cout << front(&q) << '\n';
        }  
        else if (str == "back"){
            cout << back(&q) << '\n';
        }          
    }

}