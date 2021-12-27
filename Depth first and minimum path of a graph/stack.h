//
// Created by christian brown on 11/3/2021.
//
using namespace std;

struct node{
    int data;
    node *prev;
};

class Stack{
    node* top;
public:
    Stack(){
        top = NULL;
    }
    void push(int data){
        // create an new node to be added to the stack
        node* new_node = new node;
        new_node -> data = data;
        new_node -> prev = NULL;

        if (top == NULL){
            top = new_node;
            new_node -> prev = NULL;
        }
        else{
            new_node -> prev = top;
            top = new_node;
        }

    }
    void pop(){
        node* tmp;

        if (top == NULL){
            cout << "\n STACK UNDERFLOW";
            return;
        }
        else{
            tmp = top;

            top = top->prev;

            tmp -> prev = NULL;

            delete tmp;
        }
    }
    void print_stack() {
        node* tmp = top;
        if (top == NULL){
            cout << "\nStack is empty";
        }
        while (tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->prev;
        }
    }
    void clear_stack(){
        if(top == NULL){
            cout << "Stack is empty";
        }
        else{
            while(top != NULL) {
                pop();
            }
        }
    }
    int Top(){
        return top->data;
    }

    bool empty(){
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }

    }

};