#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <sstream>

#include "appcontroller.h"

using namespace std;

const int CAPACITY = 100;

//make a graph class using matrix implementation
class Graph {
private:
    // Matrix to store the shortest path
    int **adjMatrix;
    // Number of vertices
    int numVertices;
    // Number of edges
    int numEdges;
    // Names of vertices for output
    string *names;
    //returns the index of the vertex given the name
    int getId(string name);
    //returns the parent of the vertex (for Kruskal's algorithm)
    int kruskalParent(int, int*);

public:
    //constructor
    Graph();
    //destructor
    ~Graph();
    //add a vertex to the graph with name
    void addVertex (string);
    //add an edge to the graph with id
    void addEdge(int, int, int);
    //add an edge to the graph with name
    void addEdge(string, string, int);
    //add an undirected edge to the graph with id
    void addUndirectedEdge(int, int, int);
    //add an undirected edge to the graph with name
    void addUndirectedEdge(string, string, int);

    //find the shortest path from the source vertex
    // to all other vertices using Dijkstra's algorithm
    // using id
    int** findShortestPaths(int);
    //find the shortest path from the source vertex
    // to all other vertices using Dijkstra's algorithm
    // using name
    int** findShortestPaths(string);

    int findShortestDistance(int, int);
    void findShortestPath(int, int, int*, int*);

    void findShortestTripIter(int point, bool* travelled,
                              int* points, int totalPoint,
                              int length, int* minLength,
                              int* minPath, int* currentPath,
                              int iter);

    //find the shortest path from the source vertex
    //to all other vertices which has travelled some
    //points
    int* findShortestTrip(int, int*, int, int*, int*, int*);

    //find the minimum spanning tree using Prim's algorithm
    // using id
    void MSTPrim(int);
    //find the minimum spanning tree using Prim's algorithm
    // using name
    void MSTPrim(string);
    //find the minimum spanning tree using Kruskal's algorithm
    void MSTKruskal();
    string printGraph();
};

#endif

/***************
 * CONSTRUCTOR *
 * ************/

/****************************************************************
* Graph();
*   Constructor: initializes an empty Graph object.
*   Parameters:
*       none
*   Return: an empty Graph object
****************************************************************/

/**************
 * DESTRUCTOR *
 * ************/

/****************************************************************
 * ~Graph();
 *  Destructor: frees all dynamically allocated memory.
 * Parameters:
 *     none
 * Return: none
 * **************************************************************/

/*************
 * ACCESSORS *
 * ***********/

/****************************************************************
 * int getId(string name);
 *   Accessor: returns the index of the vertex given the name
 *   Parameters:
 *       string name: the name of the vertex
 *   Return: the index of the vertex
 * **************************************************************/

/****************************************************************
 * int kruskalParent(int, int*);
 *   Accessor: returns the parent of the vertex (for Kruskal's algorithm)
 *   Parameters:
 *       int: the index of the vertex
 *       int*: the array of parent
 *   Return: the index of the parent
 * **************************************************************/

/****************************************************************
 * void findShortestPaths(int);
 *   Mutator: finds the shortest path from the source vertex
 *   to all other vertices using Dijkstra's algorithm
 *   using id
 *   Parameters:
 *       int: the index of the source vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void findShortestPaths(string);
 *   Mutator: finds the shortest path from the source vertex
 *   to all other vertices using Dijkstra's algorithm
 *   using name
 *   Parameters:
 *       string: the name of the source vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void MSTPrim(int);
 *   Mutator: finds the minimum spanning tree using Prim's algorithm
 *   using id
 *   Parameters:
 *       int: the index of the source vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void MSTPrim(string);
 *   Mutator: finds the minimum spanning tree using Prim's algorithm
 *   using name
 *   Parameters:
 *       string: the name of the source vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void MSTKruskal(int);
 *   Mutator: finds the minimum spanning tree using Kruskal's algorithm
 *   using id
 *   Parameters:
 *       int: the index of the source vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void MSTKruskal(string);
 *   Mutator: finds the minimum spanning tree using Kruskal's algorithm
 *   using name
 *   Parameters:
 *       string: the name of the source vertex
 *   Return: none
 * **************************************************************/

/*************
 * MUTATORS *
 * ***********/

/****************************************************************
 * void addVertex(string);
 *   Mutator: adds a vertex to the graph with name
 *   Parameters:
 *       string name: the name of the vertex
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void addEdge(int, int, int);
 *   Mutator: adds an edge to the graph with id
 *   Parameters:
 *       int: the index of the source vertex
 *       int: the index of the destination vertex
 *       int: the weight of the edge
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void addEdge(string, string, int);
 *   Mutator: adds an edge to the graph with name
 *   Parameters:
 *       string: the name of the source vertex
 *       string: the name of the destination vertex
 *       int: the weight of the edge
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void addUndirectedEdge(int, int, int);
 *   Mutator: adds an undirected edge to the graph with id
 *   Parameters:
 *       int: the index of the source vertex
 *       int: the index of the destination vertex
 *       int: the weight of the edge
 *   Return: none
 * **************************************************************/

/****************************************************************
 * void addUndirectedEdge(string, string, int);
 *   Mutator: adds an undirected edge to the graph with name
 *   Parameters:
 *       string: the name of the source vertex
 *       string: the name of the destination vertex
 *       int: the weight of the edge
 *   Return: none
 * **************************************************************/
