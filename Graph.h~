#include <cstring>
#include <iostream>

using namespace std;

struct vertex{
  char* label;
  bool visit;
};

class Graph{
 public:
  Graph();
  ~Graph();
  int aVertex(char* label);
  int rVertex(char* label);
  int aEdge(char* label1, char* label2, int weight);
  int rEdge(char* label1, char* label2);
  int showTable();
 private:
  int adj[20][20];
  vertex* vertices;
};
