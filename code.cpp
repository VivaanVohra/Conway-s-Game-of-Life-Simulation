#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <math.h>
#include <random>

int ROW = 20;
int COL = 20;
std::vector<std::vector<int>> newBoard;
std::vector<std::vector<int>> currentBoard(ROW, std::vector<int>(COL));
// std::vector<std::vector<int>> currentBoard= {
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
// };
//
void randomBoard(){
  //creates a random number
  std::random_device rd;

  //we give random number to alg as a random starting point to prevent same random number every run
  std::mt19937 gen(rd());
  //50 percent chance of true acts as a filter for the above generated number 
  std::bernoulli_distribution distrib(0.5);
  
  for(auto &row : currentBoard){
    for(auto  &column : row){
      column = distrib(gen);
    }
  }
}


void clearScreen(){
std::cout << "\033[2J\033[H" << std::flush;
}
void threeSecondDelay(){
  std::this_thread::sleep_for(std::chrono::seconds(3));

}
void updateBoard()

{
  int alive = 0;
  newBoard = currentBoard;
  for(int r = 0; r <currentBoard.size(); r++){
    for(int c =0; c<currentBoard[r].size();c++  )  {
    //making 3x3 grid with each elemtn as its center

      for(int i=r-1;i<=r+1;i++){
        for(int j =c-1; j<=c+1;j++){
          if(i<0 || j<0 || i>=currentBoard.size()||j>=currentBoard[r].size())
            continue;
          if(i==r && j== c)
            continue;
          else if(currentBoard[i][j]==1)
            alive++;
        }
      }
    if((alive ==2 || alive ==3) && currentBoard[r][c]==1)
      newBoard[r][c] = 1;
    if(alive >=4|| alive <=1)
      newBoard[r][c]=0;
    if((alive ==3) && currentBoard[r][c]==0)
      newBoard[r][c] =1;
    alive=0;
    }
  } 
}


void swapBoard(){
  currentBoard = newBoard;
}


void printBoard(){
  using namespace std;

  //printing the 2d vector
  for(auto row:newBoard){
    for(auto column : row){
     cout<<column<<"  ";

    }
    cout<<'\n';
  }
 }


int main ()
{
  randomBoard();
  std:: cout<<"Initial board is \n \n";
  for(auto row:currentBoard){
    for(auto column : row){
      std::cout<<column<<"  ";

    }
    std::cout<<'\n';
  }

  std::cout<<"\n \n \n";

  threeSecondDelay();
  clearScreen();
  for(int n=0; n<5; n++){
  clearScreen();
  updateBoard();
  printBoard();
  swapBoard();
  threeSecondDelay();
  std::cout<<"\n \n \n";
  }
  return 0;
}
