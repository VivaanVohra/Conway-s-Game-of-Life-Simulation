
#include <iostream>
#include <vector>
#include <math.h>

void printBoard(){
  using namespace std;

  vector<vector<char>> vec(20, vector<char>(20,'.'));

  //printing the 2d vector
  for(auto row: vec){
    for(auto column : row){
     cout<<column<<"  ";

    }
    cout<<'\n';
  }

}

void updateBoard(){

}

void checkBoard(){

}

int main (){
  printBoard();
  return 0;
}
