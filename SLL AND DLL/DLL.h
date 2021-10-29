using namespace std;
//======================================================================================================
// DOUBLY LINKED LIST
struct DLL_node{
    int data;
    DLL_node *prev;
    DLL_node *next;
};
// class for double linked list
class DLL{
    // create head and tail of the linked list
    DLL_node *head;
    DLL_node *tail;
public:
    // set head and tail to null
    DLL(){
        head = NULL;
        tail = NULL;
    }
    // function to insert at head of DLL
    void insert_head_DLL(int val){
       // create a new node
        DLL_node* new_node = new DLL_node;
        // set the values of the new node
        new_node-> data = val;
        new_node-> prev = NULL;
        new_node-> next = NULL;
        // check if the linked list is empty
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        // complete the insert operations
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        // inform the user
        cout << "The value " << val << " has been added to the head";
    }
    // fucntion to delete at tail
    void insert_tail_DLL(int val){
        // create a new node
        DLL_node* new_node = new DLL_node;
        // set the values to the linked list
        new_node->data = val;
        new_node->prev = NULL;
        new_node->next = NULL;
        // check if the linked list is empty
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        // complete operations for insert at tail
        else{
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;

        }
        // inform user
        cout << "The value " << val << " has been added to the tail";
    }
    // function to dlete at head
    void delete_head_DLL(){
        // create temp node
        DLL_node* tmp = new DLL_node;
        // check if the linked list is empty
        if(head == NULL){
            cout << "There is no Doubly linked list stored";
            return;
        }
        // complete operations for delete at head
        else{
            tmp = head;
            head = head->next;
            delete tmp;
        }
        cout << "The head of DLL has been updated";
    }
    // fucntion to delete ate tail
    void delete_tail_DLL(){
        // create temp node
        DLL_node* tmp = new DLL_node;
        // check if the linked list is empty
        if(head == NULL) {
            cout << "There is no Doubly linked list stored";
            return;
        }
        //complete operations for delete at tail
        else{
            tmp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete tmp;
        }
        cout << "The tail of DLL has been updated";
    }
    // fucntion to print the DLL
    void print_DLL(){
        // create temp node
        DLL_node* tmp = head;
        // while loop to loop through all nodes
        while(tmp != NULL){
            cout << " " << tmp -> data ;
            tmp = tmp -> next;
        }
    }
    // fuction for search and delete
    void search_del_DLL(int val){
        // create tmp node
        DLL_node* tmp = head;
        // check if the linked list is empty
        if (tmp != NULL && tmp -> data == val){
            head = tmp->next;
            delete tmp;
            return;
        }

        else{
            //while loop to get tmp to the disired node
            while(tmp != NULL && tmp->data != val){
                tmp = tmp->next;
            }
            // is tmp == null the value in not in DLL
            if(tmp == NULL) {
                cout << "The value " << val << " is not in linked list";
                return;
            }
            // create pointer to prev node
            DLL_node* prev = tmp->prev;
            // assign prev node to next next node
            prev->next = tmp->next;
            // delete tmp node
            delete tmp;
            // inform user
            cout << "The value " << val << " has been deleted";
        }

    }

};