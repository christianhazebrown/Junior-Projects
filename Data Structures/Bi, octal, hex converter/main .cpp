// HOMEWORK 3 Christian brown
#include <iostream>
#include <string>
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

};
// function protoypes
void binary_convert(int data);
void octal_conveter(int data);
void hex_converter(int data);


int main() {
    Stack s;
    hex_converter(20);
    return 0;
}
void octal_conveter(int data){
    int remainder;
    Stack s;
    if(data <= 0){
        cout << "Please enter a valid integer";
        main();
    }
    else{
        while(data != 0) {
            remainder = data % 8;
            data = data / 8;
            s.push(remainder);
        }
        s.print_stack();
        s.clear_stack();
    }
    cout << "\nDecimal has been converted to octal.";
    //main();  UNCOMMENT

}
void hex_converter(int data){
    int remainder, i = 0, n =0;
    char Array[100];
    Stack s;
    if(data <= 0){
        cout << "Please enter a valid integer";
        main();
    }
    else{
        while(data != 0) {
            remainder = data % 16;
            data = data / 16;
                switch (remainder) {
                    case 1:
                        Array[i] = '1';
                        break;
                    case 2:
                        Array[i] = '2';
                        break;
                    case 3:
                        Array[i] = '3';
                        break;
                    case 4:
                        Array[i] = '4';
                        break;
                    case 5:
                        Array[i] = '5';
                        break;
                    case 6:
                        Array[i] = '6';
                        break;
                    case 7:
                        Array[i] = '7';
                        break;
                    case 8:
                        Array[i] = '8';
                        break;
                    case 9:
                        Array[i] = '9';
                        break;
                    case 10:
                        Array[i] = 'A';
                        break;
                    case 11:
                        Array[i] = 'B';
                        break;
                    case 12:
                        Array[i] = 'C';
                        break;
                    case 13:
                        Array[i] = 'D';
                        break;
                    case 14:
                        Array[i] = 'E';
                        break;
                    case 15:
                        Array[i] = 'F';
                        break;
                    default:
                        return;
                }
            i++;
                n++;
        }
        for(int i = 0; i<=n-1; i++){
            cout << Array[i];
        }
    }
    cout << "\nDecimal has been converted to hex.";
}
void  binary_convert(int data){
    int remainder;
    Stack s;
    if(data <= 0){
        cout << "Please enter a valid integer";
        main();
    }
    else{
        while(data != 0) {
            remainder = data % 2;
            data = data / 2;
            s.push(remainder);
        }
        s.print_stack();
        s.clear_stack();
    }
    cout << "\nDecimal has been converted binary.";
    //main();       UNCOMMENT
}
