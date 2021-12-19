//
// Created by christian on 11/16/2021.
//
#include <bits/stdc++.h>
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void BFS(int s);
};

// Initialize graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
    // cerate arr to store what nodes have been visited
    visited[vertex] = true;
    // list used to create adj list
    list<int> adjList = adjLists[vertex];
    // prints the visited vertext
    cout << vertex << " ";
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void Graph::BFS(int s){
    // queue created to be used in Breath-first search
    list<int> queue;

    // make starting node true and enqeue it
    visited[s] = true;
    queue.push_back(s);

    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // dequeue a vertex from queue and print it
        s = queue.front();
        cout << "visited "<< s << " \n";
        queue.pop_front();


        // set it as visited and enqueue it
        for (i = adjLists[s].begin(); i != adjLists[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}