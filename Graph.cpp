#include <cstring>
#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(){
  maxsize = 20;
  vertices = new node[maxsize];
  cursize = 0;
}

Graph::~Graph(){
  for(int i = 0; i < cursize; i++){
    delete [] vertices[i].label;
  }
  delete [] vertices;
}

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

int Graph::rVertex(char* label){
  bool found = false;
  int index = 0;
  for(int i = 0; i < cursize; i++){
    //shift all left if found
    if(found == true){
      vertices[i - 1] = vertices[i];
      for(int j = 0; j < cursize; j++){
	adj[i][j - 1] = adj[i][j];
	adj[i - 1][j] = adj[i][j];
      }
    }
    else if(vertices[i].label == label){
      found = true;
      index = i;
      delete [] vertices[i].label;
    }
  }
  if(!found){
    return 1;
  }
  else{
    cursize--;
  }
  return 0;
}

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
      found2 == true;
    }
  }

  //add weight to table
  if(found1 && found2){
    adj[vertex1][vertex2] = weight;
    adj[vertex2][vertex1] = weight;
    return 0;
  }
  //if vertices did not exist
  return 1;
}

int Graph::rEdge(char* label1, char* label2){
  cout << label1 << ", " << label2 << endl;
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
      found2 == true;
    }
  }

  //add weight to table
  if(found1 && found2){
    adj[vertex1][vertex2] = 0;
    adj[vertex2][vertex1] = 0;
    return 0;
  }
  //if vertices did not exist
  return 1;
}

int Graph::showTable(){
  //print out labels across top
  cout << "     ";
  for(int i = 0; i < cursize; i++){
    cout << vertices[i].label << "   ";
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
