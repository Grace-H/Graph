#include <cstring>
#include <iostream>
#include "Graph.h"

using namespace std;

//constructor
Graph::Graph(){
  maxsize = 20;
  vertices = new node[maxsize];
  cursize = 0;
}

//destructor
Graph::~Graph(){
  for(int i = 0; i < cursize; i++){
    delete [] vertices[i].label;
  }
  delete [] vertices;
}

//returns shortest path between two nodes
//returns -2 if one node doesn't exist
//returns -1 if there is no complete path
int Graph::findPath(char* label1, char* label2){
  int s = findNode(label1); //start node
  int e = findNode(label2); //end node

  //if either node doesn't exist
  if(s < 0 || e < 0){
    return -2;
  }
  
  //make all nodes unvisited and set distances
  //infinity is represented as -1
  for(int i = 0; i < cursize; i++){
    if(i == s){
      vertices[i].d = 0;
    }
    else{
      vertices[i].d = -1;
    }
    vertices[i].visit = false;
  }

  int cur = s;
  bool go = true;
  while(go){
    for(int i = 0; i < cursize; i++){
      cout << adj[cur][i] << endl;
      if(adj[cur][i] != 0 && vertices[i].visit != true){
	cout << "nodes are connected" << endl;
	if((adj[cur][i] + vertices[cur].d) <= vertices[i].d || vertices[i].d == -1){
	  cout << "changing path" << endl;
	  vertices[i].d = adj[cur][i] + vertices[cur].d;
	}
      }
    }
    vertices[cur].visit = true;
    if(vertices[e].visit){
      go = false;
      return vertices[e].d;
    }
    //find node with lowest d and make cur
    int lowest = -1;
    int index = -1;
    for(int i = 0; i < cursize; i++){
      cout << lowest << endl;
      if(vertices[i].visit == false && vertices[i].d > 0 && lowest == -1){
	lowest = vertices[i].d;
	index = i;
	cout << vertices[i].label << " is the first unvisited node with a distance greater than 0" << endl;
      }
      else if(vertices[i].visit == false && vertices[i].d > 0 && vertices[i].d < lowest){
	lowest = vertices[i].d;
	index = i;
	cout << vertices[i].label << " has a smaller d than " << lowest << endl;
      }
    }
    if(index == -1){
      cout << "index is -1" << endl;
      go = false;
      return -1;
    }
    cout << "going to next node at index = " << index << endl;
    cur = index;
  }
  return -1;
}

//returns index of a mode
//-1 if doesn't exist
int Graph::findNode(char* label){
  for(int i = 0; i < cursize; i++){
    if(strcmp(label, vertices[i].label) == 0){
      return i;
    }
  }
  return -1;
}

//add a vertex to the list using label
//add row to adj table
int Graph::aVertex(char* label){
  //check to make sure vertex with same name DNE
  for(int i = 00; i < cursize; i++){
    if(strcmp(vertices[i].label, label) == 0){
      return 2;
    }
  }

  //create vertex
  node newnode;
  newnode.label = label;

  //find empty place
  if(cursize < 20){
    vertices[cursize] = newnode;
    cursize++;
  }
  
  //if a place was not found
  else{
    delete [] newnode.label;
    return 1;
  }
  
  return 0;
}

//remove vertex: remove vertex from list and adj table
int Graph::rVertex(char* label){
  bool found = false;
  int index = 0;
  for(int i = 0; i < cursize; i++){
    if(strcmp(vertices[i].label, label) == 0){
      found = true;
      index = i;
      delete [] vertices[i].label;
    }
  }

  //clear row and column at index
  for(int i = 0; i < cursize; i++){
    adj[i][index] = 0;
    adj[index][i] = 0;
  }
  
  //shift table left and up
  for(int i = index + 1; i < cursize; i++){
    for(int j = 0; j < cursize; j++){
      adj[i - 1][j] = adj[i][j];
      adj[j][i - 1] = adj[j][i];
    }
    vertices[i - 1] = vertices[i];
  }

  if(!found){
    return 1;
  }
  else{
    cursize--;
  }
  return 0;
}

//add edge: takes the labels for two vertices and connects
//them in adjacency table using weight
//returns 1 for vertex DNE, 2 for same vertex, 3 for weight is invalid
int Graph::aEdge(char* label1, char* label2, int weight){
  bool found1 = false;
  bool found2 = false;
  int vertex1;
  int vertex2;
  
  //find both vertices' indices
  for(int i = 0; i < cursize; i++){
    if(strcmp(vertices[i].label, label1) == 0){
      vertex1 = i;
      found1 = true;
    }
    else if(strcmp(vertices[i].label, label2) == 0){
      vertex2 = i;
      found2 = true;
    }
  }
  
  //add weight to table
  if(found1 && found2){

    //return 2 if they are the same
    if(strcmp(label1, label2) == 0){
      return 2;
    }

    //return 3 if the weight is <= 0
    if(weight <= 0){
      return 3;
    }
    
    adj[vertex1][vertex2] = weight;
    return 0;
  }
  //if vertices did not exist
  return 1;
}

//remove edge: takes labels of two vertices, removes their edge in adj table
int Graph::rEdge(char* label1, char* label2){
  bool found1 = false;
  bool found2 = false;
  int vertex1;
  int vertex2;

  //find both vertices' indices
  for(int i = 0; i < cursize; i++){
    if(strcmp(vertices[i].label, label1) == 0){
      vertex1 = i;
      found1 = true;
    }
    else if(strcmp(vertices[i].label, label2) == 0){
      vertex2 = i;
      found2 = true;
    }
  }

  //add weight to table
  if(found1 && found2){
    adj[vertex1][vertex2] = 0;
  }
  //if vertices did not exist
  return 1;
}

//show table: print table in grid
int Graph::showTable(){
  //print out labels across top
  cout << "     ";
  for(int i = 0; i < cursize; i++){
    cout << vertices[i].label << "     ";
  }
  cout << endl;

  //print out each row
  for(int i = 0; i < cursize; i++){
    cout << vertices[i].label << " ";
    for(int j = 0; j < cursize; j++){
      cout << adj[i][j] << "     ";
    }
    cout << endl;
  }
  cout << endl;
}
