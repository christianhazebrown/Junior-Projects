//Christian brown
#include <iostream>
#include "graph.h"


int main() {
    Graph g(9); // Total 9 vertices in graph
    g.addEdge(0,1);// a -> b
    g.addEdge(0,2);// a -> c
    g.addEdge(8,3);// a -> d
    g.addEdge(1,4);// b -> e
    g.addEdge(2,1);// c -> b
    g.addEdge(2,6);// c -> g
    g.addEdge(3,2);// d -> c
    g.addEdge(3,6);// d -> g
    g.addEdge(4,2);// e -> c
    g.addEdge(4,5);// e -> f
    g.addEdge(5,2);// f -> c
    g.addEdge(5,7);// f -> h
    g.addEdge(6,5);// g -> f
    g.addEdge(6,7);// g -> h
    g.addEdge(6,8);// g -> i
    g.addEdge(7,6);// h -> e
    g.addEdge(7,8);// h -> i
    g.addEdge(8,5);// i -> f
    int choice;
while(choice != -1){
    cout << "==========M E N U==========\n"
            "Depth-First Search(0), Minimum Path Search(1)\n"
            "Exit Program(3):";
    cin >> choice;
    switch(choice) {
        case 0:
            cout << "What vertex would you like to start at:";
            cin >> choice;
            cout << "===Depth first search===\n";
            g.DFS(choice);
            break;
        case 1:
            cout << "What vertex would you like to start at:";
            cin >> choice;
            cout << "===Breath first search===\n";
            g.BFS(choice);
            break;
        case 3:
            choice = -1;
            break;
        default:
            cout << "Please enter a valid choice";
    }
}
    return 0;
}
