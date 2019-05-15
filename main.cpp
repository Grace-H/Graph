/*Takes numbers and creates a graph with weighted edges
 *Author: Grace Hunter
 *Date: May 9, 2019
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "Graph.h"

using namespace std;

int addVertex(Graph* graph);
int removeVertex(Graph* graph);
int addEdge(Graph* graph);
int removeEdge(Graph* graph);

int main(){
  //commands
  char* addstr = new char[20];
  char* removestr = new char[20];
  char* tablestr = new char[20];
  char* vertexstr = new char[20];
  char* edgestr = new char[20];
  char* quitstr = new char[20];

  strcpy(addstr, "ADD");
  strcpy(removestr, "REMOVE");
  strcpy(tablestr, "TABLE");
  strcpy(vertexstr, "VERTEX");
  strcpy(edgestr, "EDGE");
  strcpy(quitstr, "QUIT");

  char* input = new char[256];

  //initialize graph
  Graph* graph = new Graph();
  
  cout << "note: commands do not have to be uppercase" << endl;
  
  //keep asking for command until user asks to quit
  bool go = true;
  while(go){
    //get input
    cout << "'ADD' 'REMOVE' 'QUIT' or print adjacency 'TABLE'?" << endl;
    cin.get(input, 256);
    cin.get();

    //uppercase
    for(int i = 0; i < strlen(input); i++ ){
      input[i] = toupper(input[i]);
    }

    //identify command and act accordingly
    //add
    if(strcmp(addstr, input) == 0){
      cout << "'VERTEX' or 'EDGE'?" << endl;
      cin.get(input, 256);
      cin.get();

      //uppercase
      for(int i = 0; i < strlen(input); i++){
	input[i] = toupper(input[i]);
      }
      
      //vertex
      if(strcmp(vertexstr, input) == 0){
	addVertex(graph);
      }
      //edge
      else if(strcmp(edgestr, input) == 0){
	addEdge(graph);
      }
      else{
	cout << "not an option" << endl;
      }
    }
    else if(strcmp(removestr, input) == 0){
      cout << "'VERTEX' or 'EDGE'?" << endl;
      cin.get(input, 256);
      cin.get();

      //uppercase
      for(int i = 0; i < strlen(input); i++){
	input[i] = toupper(input[i]);
      }
      
      //vertex
      if(strcmp(vertexstr, input) == 0){
	removeVertex(graph);
      }
      //edge
      else if(strcmp(edgestr, input) == 0){
	removeEdge(graph);
      }
      else{
	cout << "not an option" << endl;
      }
    }
    else if(strcmp(quitstr, input) == 0){
      go = false;
      delete [] addstr;
      delete [] removestr;
      delete [] vertexstr;
      delete [] edgestr;
      delete [] quitstr;
      delete [] tablestr;
    }
    else if(strcmp(tablestr, input) == 0){
      //call table function of graph
      graph->showTable();
    }
    else{
      cout << "not an option" << endl;
    }
  }
  return 0;
}

int addVertex(Graph* graph){
  char* label = new char[256];
  cout << "Enter label: " << endl;
  cin.get(label, 256);
  cin.get();
  
  //call add vertex in graph
  int error = graph->aVertex(label);
  //if equals 1
  if(error == 1){
    cout << "There are already 20 vertices in the graph." << endl;
    delete [] label;
  }
  else if(error == 2){
    cout << "There is already a vertex with that name." << endl;
    delete [] label;
  }
  return 0;
}

int removeVertex(Graph* graph){
  char* label = new char[256];
  cout << "Enter label: " << endl;
  cin.get(label, 256);
  cin.get();
  //call remove vertex in graph
  int error = graph->rVertex(label);
  
  //if equals 1
  if(error == 1){
    cout << "Vertex does not exist." << endl;
  }
  delete [] label;
  return 0;
}

int addEdge(Graph* graph){
  char* label1 = new char[256];
  cout << "Enter label of first vertex: " << endl;
  cin.get(label1, 256);
  cin.get();
  
  char* label2 = new char[256];
  cout << "Enter label of second: " << endl;
  cin.get(label2, 256);
  cin.get();
  
  char* weightstr = new char[256];
  cout << "Enter weight of edge: " << endl;
  cin.get(weightstr, 256);
  cin.get();
  int weight = atoi(weightstr);
  delete weightstr;
  
  //call add
  int error = graph->aEdge(label1, label2, weight);
  
  //if equals 1
  if(error == 1){
    cout << "One or both vertices does not exist." << endl;
  }
  delete [] label1;
  delete [] label2;
  
  return 0;
}

int removeEdge(Graph* graph){
  char* label1 = new char[256];
  cout << "Enter label of first vertex: " << endl;
  cin.get(label1, 256);
  cin.get();
  
  char* label2 = new char[256];
  cout << "Enter label of second: " << endl;
  cin.get(label2, 256);
  cin.get();

  //call remove
  int error = graph->rEdge(label1, label2);
  
  //if equals 1
  if(error == 1){
    cout << "One or both vertices does not exist." << endl;
  }
  delete [] label1;
  delete [] label2;
  
  return 0;
}
