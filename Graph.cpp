#include <cstring>
#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(){
  vertices = new vertex[20];
}

Graph::~Graph(){
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i] != NULL){
      delete [] vertices[i]->label;
      delete vertices[i];
      vertices[i] = NULL;
    }
  }
  delete [] vertices;
}

int Graph::aVertex(char* label){
  //check to make sure vertex with same name DNE
  for(int i = 00; i < vertices->length(); i++){
    if(vertices[i]->label == label){
      return 2;
    }
  }

  //create vertex
  vertex* newvertex;
  newvertex->label = label;

  //find empty place
  bool placed = false;
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i] == NULL){
      vertices[i] = newvertex;
      placed = true;
      break;
    }
  }

  //if a place was not found
  if(!placed){
    delete [] newvertex->label;
    delete newvertex;
    return 1;
  }
  
  return 0;
}

int Graph::rVertex(char* label){
  bool found = false;
  int index = 0;
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i]->label == label){
      found = true;
      index = i;
      delete [] vertices[i]->label;
      delete vertices[i];
      vertices[i] = NULL;
      break;
    }
  }
  if(!found){
    return 1;
  }
  //clear rows in adjacency table
  for(int i = 0; i < adj->length(); i++){
    adj[20][i] = 0;
    adj[i][20] = 0;
  }
  return 0;
}

int Graph::aEdge(char* label1, char* label2, int weight){
  bool found1 = false;
  bool found2 = false;
  int vertex1;
  int vertex2;

  //find both vertices' indices
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i] == label1){
      vertex1 = i;
      found1 = true;
    }
    else if(vertices[i] == label2){
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
  bool found1 = false;
  bool found2 = false;
  int vertex1;
  int vertex2;

  //find both vertices' indices
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i] == label1){
      vertex1 = i;
      found1 = true;
    }
    else if(vertices[i] == label2){
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
  cout << "          ";
  for(int i = 0; i < vertices->length(); i++){
    if(vertices[i] != NULL){
      cout << vertices[i]->label << "   ";
    }
  }
  cout << endl;

  //print out each row
  for(int i = 0; i < adj->length(); i++){
    if(vertices[i] != NULL){
      cout << vertices[i]->label << " " << endl;
      for(int j = 0; j < ajd[0]->length(); j++){
	if(vertices[j] != NULL){
	  cout << adj[i][j] << "     " << endl;
	}
      }
    }
  }
}
