#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <string>

const int ROW = 20;
const int COL = 20;

std::vector<std::vector<int>> newBoard;
std::vector<std::vector<int>> currentBoard(ROW, std::vector<int>(COL));


void randomBoard(unsigned int seed){
if(seed ==0){ 

  std::random_device rd;
  seed = rd();
  std::cout<<"Random seed is \n" << seed<<"\n";
}

  std::mt19937 gen(seed);
  
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

      if(currentBoard[r][c] ==1 ){
        if(alive == 0 || alive ==1 || alive >=4)
          newBoard[r][c] = 0;
      }
      else {
      if(alive ==3 )
        newBoard[r][c] = 1;
      }
    alive =0;    
   }
  } 
}


void swapBoard(){
  currentBoard = newBoard;
}


void printBoard(){
  using namespace std;

  std::cout<<string(COL*2, '-')<<"+\n";
  //printing the 2d vector
  for(auto row:currentBoard){
    std::cout<<"|";
    for(auto column : row){
     cout<<(column? "\033[32m[]\033[0m":"  " );

    }
    cout<<"|\n";
  }
  std::cout<<string(COL*2, '-')<<"+\n";

 }

void stepGeneration(){ //introduced to reduce clutter in main fucntion
  updateBoard();
  swapBoard();
}



int main ()
{
  int gen ;
  unsigned int seed;

  std::cout<<"Enter a seed or enter 0 for a random see";
  if(!(std::cin>>seed)){
    std::cout<<"Invalid seed input ";
    return 1;
  }
  
  randomBoard(seed);
  
  std:: cout<<"Initial board is \n \n";
  for(auto row:currentBoard){
    for(auto column : row){
      std::cout<<(column?"\033[32m[]\033[0m":"  ");

    }
    std::cout<<'\n';
  }

  std::cout<<"Enter the number of generations you want to go till \n";
  std::cin>>gen;

  threeSecondDelay();
  clearScreen();

  for(int n=0; n<gen; n++){
  stepGeneration();
  
  clearScreen();
  std::cout << "\033[36mGeneration: "
          << n + 1
          << "\033[0m\n";
  printBoard();
  threeSecondDelay();
  clearScreen();
  }
  return 0;
}
