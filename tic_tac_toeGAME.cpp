#include<bits/stdc++.h>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool t ; // t-> tie
char token='X';
string n1;
string n2;
int row,col;
int c=0;
void f1(){
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[0][0]<<" "<<"|"<<" "<<space[0][1]<<" "<<"|"<<" "<<space[0][2]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[1][0]<<" "<<"|"<<" "<<space[1][1]<<" "<<"|"<<" "<<space[1][2]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[2][0]<<" "<<"|"<<" "<<space[2][1]<<" "<<"|"<<" "<<space[2][2]<<" "<<endl;
    cout<<"   |   |   "<<endl;
}
void f2(){
    int dizit;
    if(token=='X'){
        cout<<n1<<" enter dizit"<<endl;
        cin>>dizit;
        token='0';
    }
    else if(token=='0'){
        cout<<n2<<" enter dizit"<<endl;
        cin>>dizit;
        token='X';
    }
    if(dizit==1){
        row=0;col=0;
    }
    else if(dizit==2){
        row=0;col=1;
    }
    else if(dizit==3){
        row=0;col=2;
    }
    else if(dizit==4){
        row=1;col=0;
    }
    else if(dizit==5){
        row=1;col=1;
    }
    else if(dizit==6){
        row=1;col=2;
    }
    else if(dizit==7){
        row=2;col=0;
    }
    else if(dizit==8){
        row=2;col=1;
    }
    else if(dizit==9){
        row=2;col=2;
    }
    else if(dizit<1 or dizit>9)cout<<"invalid!!!"<<endl;


    if(token=='X' and space[row][col]!='X' and space[row][col]!='0'){
        space[row][col]='X';
    }
    else if(token=='0' and space[row][col]!='X' and space[row][col]!='0'){
        space[row][col]='0';
    }
    else {
        cout<<" u are putting your choice over other choice , try at another place"<<endl;
        f2();
    }
    f1();//display your upgrades in grid
}

bool f3(){
    for(int i=0; i<3; i++){
        if(space[0][i]==space[1][i] and space[0][i]==space[2][i] or space[i][0]==space[i][1]and space[i][0]== space[i][2])return true;
    }
    // diagonal check
    if(space[0][0]==space[1][1] and space[0][0]== space[2][2] or space[0][3] == space[1][1] and space[0][2]== space[2][0])return true;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j]!='X' and space[i][j]!='0'){
    
                return false;
            }
        }
    }
    t=true;
    
    return false ;
}
int main(){
    cout<<"enter name of player 1"<<endl;
    cin>>n1;
    cout<<"enter name of player 2"<<endl;
    cin>>n2;
    while(!f3()){
        f1();
        f2();
        f3();
    }
    if(token=='X' and t==false){
        cout<<n2<<"wins"<<endl;
    }
    else if(token=='0' and t==false){
        cout<<n1<<"wins"<<endl;
    }
    else cout<<"draw"<<endl;
    return 0;
}