#include <cstring>
#include <iostream>

using namespace std;

struct node{
  char* label;                                       //label
  int d;                                             //distance
  bool visit;                                        //visited

};

class Graph{
 public:
  Graph();                                           //constructor
  ~Graph();                                          //destructor
  int findPath(char* label, char* label);            //use Dijkstra's algorithm to find shortest path
  int findNode(char* label);                         //finds a vertex using label
  int aVertex(char* label);                          //add a vertex
  int rVertex(char* label);                          //remove a vertex
  int aEdge(char* label1, char* label2, int weight); //add an edge
  int rEdge(char* label1, char* label2);             //remove and edge
  int showTable();                                   //display adjacency table
 private:
  int adj[20][20];                                   //adjacency table
  node* vertices;                                    //list of vertices
  int cursize;                                       //current number of vertices
  int maxsize;                                       //maximum number of vertices
};
