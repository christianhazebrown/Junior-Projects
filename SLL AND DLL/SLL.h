using namespace std;
//=============================================================================================================
//SINGLE LINKED LIST
struct SLL_node{
    int data;
    SLL_node *next;
};
//class for single linked list
class SLL{
    SLL_node* head;
    SLL_node* tail;
public:
    SLL(){
        // set head and tail to null
        head = NULL;
        tail = NULL;
    }
    // function to insert at head of SLL
    void insert_head_SLL(int data){
        // create a new SLL_node
        SLL_node* new_node = new SLL_node;
        // assign the input data to the new SLL_node
        new_node -> data = data;
        // make the next pointer = to NULL
        new_node -> next = NULL;
        // checks if the linked list is empty
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
            // if linked list is not empty make the head the next SLL_node
            //re assign head
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    // function to insert at tail of SLL
    void insert_tail_SLL(int data){
        // create the new SLL_node
        SLL_node* new_node = new SLL_node;
        // assign data to the new SLL_node
        new_node -> data = data;
        // make the next pointer null
        new_node -> next = NULL;
        // check if the linked list is empty
        if (head == NULL){
            head = new_node;
            tail = new_node;
        }
            // if not empty make the new SLL_node the last SLL_node and
            // reassign tail
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
    // function tp delete at head of SLL
    void del_head_SLL() {
        // check if the SLL is empty
        if (head == NULL){
            return;
        }
        // performs operations of delete at head of SLL
        else{
            SLL_node* tmp = head;
            head = head -> next;
            delete tmp;
        }
    }
    void del_tail_SLL(){
        // check if the SLL is empty
        if(head == NULL){
            return;
        }
        if(head-> next == NULL){
            delete head;
        }
        // performs operations of delete at tail of SLL
        else{
            // create new node to get the node before the tail
            SLL_node* second_last = head;
            while(second_last->next->next != NULL){
                second_last = second_last->next;
            }
            delete(second_last->next);
            second_last->next = NULL;
        }
    }
    // function to search and delete the user request
    void del_search_SLL(int val){
        // create temp node and prev node to delete val
        SLL_node* tmp = head;
        SLL_node* prev = NULL;
        // check if the SLL is empty
        if (tmp != NULL && tmp -> data == val){
            head = tmp->next;
            delete tmp;
            return;
        }
        // complete operations of search and delete in DLL
        else{
            // sets tmp to to correct node and checks is val is store in node
            while(tmp != NULL && tmp->data != val){
                prev = tmp;
                tmp = tmp->next;
            }
            // informs user if node is in DLL
            if(tmp == NULL) {
                cout << "The value " << val << " is not in linked list";
                return;
            }
            //removes node
            prev->next = tmp->next;
            // delete tmp node
            delete tmp;
            // inform user of update
            cout << "The value " << val << " has been deleted";
        }
    }
    // fucntion to print SLL
    void print_SLL(){
        SLL_node* tmp = head;
        while(tmp != NULL){
            cout << "\n" << tmp -> data ;
            tmp = tmp -> next;
        }
    }
};