//
// Created by christian brown on 11/3/2021.
//
using namespace std;

struct q_node{
    int data;
    q_node *next;

};

class Queue{
    q_node* head;
    q_node* tail;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }
    void push(int data){
        q_node* new_node = new q_node;
        new_node -> data = data;
        new_node -> next = NULL;

        if(tail == NULL){
            head = new_node;
            tail = new_node;
            new_node -> next = NULL;
        }
        else{
            tail -> next = new_node;
            tail = new_node;
        }
    }
    void print_next_in_queue(){
        cout << "Head " << head->data;
    }
    void pop(){
        q_node* tmp = new q_node;
        if(head == NULL){
            cout << "The queue is empty";
        }
        else{
            tmp = head;
            head = head -> next;
            delete tmp;
        }

    }



};


