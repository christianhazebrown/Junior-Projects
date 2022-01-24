#include <iostream>
#include "SLL.h"
#include "DLL.h"
using namespace std;
//Main funtion that cotrols the menu
int main() {
    int choice = 0;
    int value = 0;
    // initalizing the linked lists
    SLL s;
    DLL d;
    //while loop to run program until user decides to exit
    while(choice != 12) {
        // menu display and grad user choice
        cout << "\n              M E N U\n"
                "SLL:  IH(0),  IT(1),  DH(2),  DT(3),  SD(4),  PS(5)\n"
                "DLL:  IH(6),  IT(7),  DH(8),  DT(9),  SD(10),  PD(11)\n"
                "Exit Program (12)\n\n"
                "                       Choice: ";
        cin >> choice;
        // switch statment to select proper function per users choice
        switch (choice) {
            // SLL INSTERT AT HEAD
            case 0:
                cout << "\nWhat is the value to be added at head: ";
                cin >> value;
                s.insert_head_SLL(value);
                cout << "\nThe value " << value << " has been created at the head.";
                break;
                // SLL INSERT AT TAIL
            case 1:
                cout << "\nWhat is the value to be added at tail: ";
                cin >> value;
                s.insert_tail_SLL(value);
                cout << "\nThe value " << value << " has been created at the tail.";
                break;
                //SLL DELETE AT HEAD
            case 2:
                s.del_head_SLL();
                cout << "\nThe head SLL_node has been deleted";
                break;
                //SLL DELETE AT TAIL
            case 3:
                s.del_tail_SLL();
                cout << "\nThe tail SLL_node has been deleted";
                break;
                //SLL SEARCH AND DELETE VALUE
            case 4:
                cout << "\nEnter the value to be deleted: ";
                cin >> value;
                s.del_search_SLL(value);
                break;
                //PRINT SINGLE LINKED LIST
            case 5:
                s.print_SLL();
                break;
                //DLL INSERT AT HEAD
            case 6:
                cout << "\nEnter the value to be added to head: ";
                cin >> value;
                d.insert_head_DLL(value);
                break;
                //DLL INSERT AT TAIL
            case 7:
                cout << "\nEnter the value to be added to head: ";
                cin >> value;
                d.insert_tail_DLL(value);
                break;
                //DLL DELETE AT HEAD
            case 8:
                d.delete_head_DLL();
                break;
                //DLL DELETE AT TAIL
            case 9:
                d.delete_tail_DLL();
                break;
                //DLL SEARCH AND DELETE
            case 10:
                cout << "\nEnter the value to be searched and delted: ";
                cin >> value;
                d.search_del_DLL(value);
                break;
                //PRINT DOUBLY LINKED LIST
            case 11:
                d.print_DLL();
                break;
                //EXIT PROGRAM
            case 12:
                return 0;
                //CHECK FOR VALID USER INPUT
            default:
                cout << "\nValue error, PLease try again";
        }
    }
    return 0;
}
