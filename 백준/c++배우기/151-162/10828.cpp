#include<iostream>
#include<string>
using namespace std;
typedef struct stack{
    int arr[100000];
    int top;
}Stack;

void reset(Stack *s){
    s->top=-1;
}
void push(Stack *s, int x){
    s->top++;
    s->arr[s->top]=x;
}

int pop(Stack *s){
    if(s->top==-1)
        return -1;
    else
        return (s->arr[(s->top)--]);
}

int size(Stack *s){
    return (s->top +1);
}

int empty(Stack *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int top(Stack *s){
    if(s->top==-1)
        return -1;
    else
        return s->arr[s->top];
}

int main(){
    Stack s;
    reset(&s);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "push"){
            int x;
            cin >> x;
            push(&s,x);
        }
        else if (str == "pop"){
            cout << pop(&s) << '\n';
        }
        else if (str == "size"){
            cout << size(&s) << '\n';
        }
        else if (str == "empty"){
            cout << empty(&s) << '\n';
        }        
        else if (str == "top"){
            cout << top(&s) << '\n';
        }  
    }

}