#include<iostream>
#include<string>
using namespace std;
typedef struct deque{
    int arr[100000];
    int top;
    int bottom;
}Deque;

void reset(Deque *d){
    d->top=0;
    d->bottom=0;
}
void push_back(Deque *d, int x){
    d->top=(d->top+1)%10000;
    d->arr[d->top]=x;
}
void push_front(Deque *d, int x){
    d->arr[d->bottom]=x;
    d->bottom=(d->bottom-1+10000)%10000;
}

int pop_front(Deque *d){
    if(d->top==d->bottom)
        return -1;
    else
        d->bottom=(d->bottom+1)%10000;
        return (d->arr[d->bottom]);
}

int pop_back(Deque *d){
    if(d->top==d->bottom)
        return -1;
    else{
        d->top=(d->top-1+10000)%10000;
        return (d->arr[(d->top+1)%10000]);
    }
}


int size(Deque *d){
    return (d->top-d->bottom +10000)%10000;
}

int empty(Deque *d){
    if(d->top==d->bottom)
        return 1;
    else
        return 0;
}

int front(Deque *d){
    if(d->top==d->bottom)
        return -1;
    else
        return d->arr[(d->bottom+1)%10000];
}

int back(Deque *d){
    if(d->top==d->bottom)
        return -1;
    else
        return d->arr[d->top];
}

int main(){
    Deque d;
    reset(&d);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push_front"){
            int x;
            cin >> x;
            push_front(&d,x);
        }
        else if (str == "push_back"){
            int x;
            cin >> x;
            push_back(&d,x);
        }
        else if (str == "pop_front"){
            cout << pop_front(&d) << '\n';
        }
        else if (str == "pop_back"){
            cout << pop_back(&d) << '\n';
        }
        else if (str == "size"){
            cout << size(&d) << '\n';
        }
        else if (str == "empty"){
            cout << empty(&d) << '\n';
        }        
        else if (str == "front"){
            cout << front(&d) << '\n';
        }  
        else if (str == "back"){
            cout << back(&d) << '\n';
        }          
    }

}