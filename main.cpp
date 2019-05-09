/*Takes numbers and creates a graph with weighted edges
 *Author: Grace Hunter
 *Date: May 9, 2019
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

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

  cout << "note: commands do not have to be uppercase" << endl;
  
  //keep asking for command until user asks to quit
  book go = true;
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
	//add vertex function call
      }
      //edge
      else if(strcmp(edgestr, input) == 0){
	//edge function call
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
	//add vertex function call
      }
      //edge
      else if(strcmp(edgestr, input) == 0){
	//edge function call
      }
      else{
	cout << "not an option" << endl;
      }
    }
    else if(strcmp(quitstr, input) == 0){
    }
    else if(strcmp(tablestr, input) == 0){
    }
    else{
      cout << "not an option" << endl;
    }
  }
  return 0;
}
