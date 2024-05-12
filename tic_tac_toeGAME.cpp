#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>board;
void drawboard(){
  for(int i=0; i<3; i++){
    cout<<"|";
    for(int j=0; j<3; j++){
      cout<<board[i][j];
      cout<<" |";
    }cout<<endl;
    cout<<"-------------"<<endl;
  }
}
bool checkwin(char player){
  for(int i=0; i<3; i++){
    if(board[i][0]==player and board[i][1]==player and board[i][2]==player )return true;
  }for(int j=0; j<3; j++){
    if(board[0][j]==player and board[1][j]==player and board[2][j]==player)return true;
  }
  if(board[0][0]==player and board[1][1]==player and board[2][2]==player  or board[0][2]==player and board[1][1]==player and board[2][0]==player)return true;
  else false;
}

int main(){
  board.resize(3,vector<char>(3,' '));
  char player = 'X';
  int turn;

  for(turn=0; turn<9; turn++){
    drawboard();
    int row,col;
    while(1){
      cout<<"enter row"<<endl;
      cin>>row;
      cout<<"enter col"<<endl;
      cin>>col;
      if(row>2 or row <0 or col>2 or col<0 or board[row][col] !=' '){
        cout<<"enter valid row and col"<<endl;
      }
      else break;
    }
    board[row][col]=player;
    if(checkwin(player)){
      cout<<player<<" wins"<<endl;
      break;
    }
    player = (player=='X')?'0':'X';

  }
  if(turn ==9 and !checkwin('X') and !checkwin('0')){
    cout<<"its draw"<<endl;
  }
  return 0;
}