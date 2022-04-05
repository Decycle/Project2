/*************************************************
* AUTHOR        : Zimin Yang
* ASSIGNMENT 7  : Dijkstra's Algorithm and MST
* CLASS         : CS 008
* DUE DATE      : 3/16/22
*************************************************/
#include "graph.h"
#include <iostream>
#include <iomanip>

using namespace std;

/***************
 * CONSTRUCTOR *
 * ************/

/*************************************************
 * Method Graph(): Class Graph
 * _______________________________________________
 * Constructor that initializes an empty Graph
 * object
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * none
 * POST-CONDITIONS:
 * Creates an empty Graph object
 * ***********************************************/
Graph::Graph()
{
    adjMatrix = new int*[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        adjMatrix[i] = new int[CAPACITY];
    }
    numVertices = 0;
    numEdges = 0;
    names = new string[CAPACITY];
}

/**************
 * DESTRUCTOR *
 * ************/

/*************************************************
 * Method ~Graph(): Class Graph
 * _______________________________________________
 * Destructor that deletes the adjacency matrix
 * and the names array
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * names : the names array
 * POST-CONDITIONS:
 * Deletes the adjacency matrix and the names array
 * ***********************************************/
Graph::~Graph()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;
    delete [] names;
}

/*************
 * ACCESSORS *
 * ***********/

/*************************************************
 * Method getId(): Class Graph
 * _______________________________________________
 * Accessor: returns a vertex's id given its name
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * name : the name of the vertex
 * POST-CONDITIONS:
 * Returns the id of the vertex
 * ***********************************************/
int Graph::getId(string name)
{
    for (int i = 0; i < numVertices; i++)
    {
        if (names[i] == name)
        {
            return i;
        }
    }
    return -1;
}

/*************************************************
 * Method printGraph(): Class Graph
 * _______________________________________________
 * Accessor: prints the graph
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the adjacency matrix
 * ***********************************************/
void Graph::printGraph()
{
    cout << "  ";

    for(int i = 0; i < numVertices; i++)
    {
        cout << names[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << names[i] << " ";

        for (int j = 0; j < numVertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*************************************************
 * Method findShortestPaths(): Class Graph
 * _______________________________________________
 * Accessor: finds the shortest paths from a
 * vertex to all other vertices
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the shortest paths from a vertex to all
 * other vertices
 * ***********************************************/
void Graph::findShortestPaths(int start)
{
    int visited[numVertices];
    int distance[numVertices];
    int parent[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start] = 0;

    for(int node = 0; node < numVertices; node++)
    {
        for(int i = 0; i < numVertices; i++)
        {
            if(visited[i] == 0 && adjMatrix[node][i] != 0 && distance[node] + adjMatrix[node][i] < distance[i])
            {
                distance[i] = distance[node] + adjMatrix[node][i];
                parent[i] = node;
            }
        }
        visited[node] = 1;
    }

    //output path
    cout << "---Dijkstra's Algorithm (starting from " << names[start] <<")---" << endl;

    for(int i = 0; i < numVertices; i++)
    {
        cout << names[i] << ": " << distance[i];

        string path = "";

        int p = i;
        while(p != -1)
        {
            path = names[p] + ", " + path;
            p = parent[p];
        }

        cout << " {" << path.substr(0, path.length() - 2) << "}" << endl;
    }
}

/*************************************************
 * Method findShortestPaths(): Class Graph
 * _______________________________________________
 * Accessor: finds the shortest paths from a
 * vertex to all other vertices
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the shortest paths from a vertex to all
 * other vertices
 * ***********************************************/
void Graph::findShortestPaths(string start)
{
    int startId = getId(start);
    findShortestPaths(startId);
}

/*************************************************
 * Method MSTPrim(): Class Graph
 * _______________________________________________
 * Accessor: finds the minimum spanning tree using
 * Prim's algorithm
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the minimum spanning tree
 * ***********************************************/
void Graph::MSTPrim(int start)
{
    cout << "---Minimum Spanning Tree (Prim's Algorithm)---" << endl;

    int visited[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;

    for(int index = 0; index < numVertices - 1; index++)
    {
        int min = INT_MAX;
        int startId = -1;
        int endId = -1;
        for(int i = 0; i < numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                if(visited[i] == 0)
                {
                    continue;
                }

                if(adjMatrix[i][j] != 0 && visited[j] == 0 && adjMatrix[i][j] < min)
                {
                    min = adjMatrix[i][j];
                    startId = i;
                    endId = j;
                }
            }
        }
        visited[endId] = 1;
        cout << index + 1 << ": (" << names[startId] << ", " << names[endId] << ") " << min << endl;
    }
}

/*************************************************
 * Method MSTPrim(): Class Graph
 * _______________________________________________
 * Accessor: finds the minimum spanning tree using
 * Prim's algorithm
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the minimum spanning tree
 * ***********************************************/
void Graph::MSTPrim(string start)
{
    int startId = getId(start);
    MSTPrim(startId);
}

/*************************************************
 * Method kruskalParent(): Class Graph
 * _______________________________________________
 * Accessor: finds the parent of a vertex
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * parent : the parent array
 * POST-CONDITIONS:
 * Returns the parent of a vertex
 * ***********************************************/
int Graph::kruskalParent(int i, int* parent)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

/*************************************************
 * Method MSTKruskal(): Class Graph
 * _______________________________________________
 * Accessor: finds the minimum spanning tree using
 * Kruskal's algorithm
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * adjMatrix : the adjacency matrix
 * POST-CONDITIONS:
 * Prints the minimum spanning tree
 * ***********************************************/
void Graph::MSTKruskal()
{
    cout << "---Minimum Spanning Tree (Kruskal's Algorithm)---" << endl;

    int parent[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        parent[i] = i;
    }

    for(int index = 0; index < numVertices - 1; index++)
    {
        int min = INT_MAX;
        int startId = -1;
        int endId = -1;

        for(int i = 0; i < numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                if(kruskalParent(i, parent) != kruskalParent(j, parent)
                   && adjMatrix[i][j] != 0 && adjMatrix[i][j] < min)
                {
                    min = adjMatrix[i][j];
                    startId = i;
                    endId = j;
                }
            }
        }
        int parentStart = kruskalParent(startId, parent);
        int parentEnd = kruskalParent(endId, parent);
        parent[parentStart] = parentEnd;
        cout << index + 1 << ": (" << names[startId] << ", " << names[endId] << ") " << min << endl;
    }
}

/************
 * MUTATORS *
 * **********/

/*************************************************
 * Method addVertex(): Class Graph
 * _______________________________________________
 * Adds a named vertex to the graph, append the
 * name to the names array, and increase the
 * number of vertices by 1
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * name : the name of the vertex
 * POST-CONDITIONS:
 * Adds a named vertex to the graph, append the
 * name to the names array, and increase the
 * number of vertices by 1
 * ***********************************************/
void Graph::addVertex(string name)
{
    names[numVertices] = name;
    numVertices++;
}

/*************************************************
 * Method addEdge(): Class Graph
 * _______________________________________________
 * Adds an edge to the graph, and increase the
 * number of edges by 1
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * from : the id of the vertex that the edge starts from
 * to : the id of the vertex that the edge ends at
 * weight : the weight of the edge
 * POST-CONDITIONS:
 * Adds an edge to the graph, and increase the
 * number of edges by 1
 * ***********************************************/
void Graph::addEdge(int from, int to, int weight)
{
    adjMatrix[from][to] = weight;
    numEdges++;
}
/*************************************************
 * Method addEdge(): Class Graph
 * _______________________________________________
 * Adds an edge to the graph, and increase the
 * number of edges by 1
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * from : the name of the vertex that the edge
 * starts from
 * to : the name of the vertex that the edge ends at
 * weight : the weight of the edge
 * POST-CONDITIONS:
 * Adds an edge to the graph, and increase the
 * number of edges by 1
 * ***********************************************/
void Graph::addEdge(string from, string to, int weight)
{
    int fromId = getId(from);
    int toId = getId(to);
    adjMatrix[fromId][toId] = weight;
    numEdges++;
}

/*************************************************
 * Method addUndirectedEdge(): Class Graph
 * _______________________________________________
 * Adds an undirected edge to the graph, and
 * increase the number of edges by 2
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * from : the id of the vertex that the edge starts from
 * to : the id of the vertex that the edge ends at
 * weight : the weight of the edge
 * POST-CONDITIONS:
 * Adds an undirected edge to the graph, and
 * increase the number of edges by 2
 * ***********************************************/
void Graph::addUndirectedEdge(int from, int to, int weight)
{
    addEdge(from, to, weight);
    addEdge(to, from, weight);
}

/*************************************************
 * Method addUndirectedEdge(): Class Graph
 * _______________________________________________
 * Adds an undirected edge to the graph, and
 * increase the number of edges by 2
 * _______________________________________________
 * PRE-CONDITIONS:
 * The following needs previous defined values:
 * from : the name of the vertex that the edge
 * starts from
 * to : the name of the vertex that the edge ends at
 * weight : the weight of the edge
 * POST-CONDITIONS:
 * Adds an undirected edge to the graph, and
 * increase the number of edges by 2
 * ***********************************************/
void Graph::addUndirectedEdge(string from, string to, int weight)
{
    addEdge(from, to, weight);
    addEdge(to, from, weight);
}
