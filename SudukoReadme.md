Sudoku Solver using backtracking

Introduction
Sudoku is a simple puzzle consisting of a 9X9 grid having 9 rows and columns and 9 sub-grids of 3X3.
The objective of the puzzle is to place a number in each of the 81 blocks from 1 to 9 satisfying the following constraints.
•	No row can have a single number twice.
•	No column can have a single number twice.
•	No sub-grid of 3X3 can have a single number twice.
Code used and its description
#include<iostream>
using namespace std;
#define N 9

void print(int G[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int G[N][N],int row,int col,int num){

    for(int i=0;i<N;i++){
        if(G[row][i]==num){
            return false;
        }
    }

    for(int i=0;i<N;i++){
        if(G[i][col]==num){
            return false;
        }
    }

    int srow=row-row%3;      
    int scol=col-col%3;      
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(G[i+srow][j+scol]==num){
                return false;
            }
        }
    }

    return true;    
}


bool suduko(int G[N][N],int row,int col){

    if(row==N-1 && col==N){
        return true;
    }

    if(col==N){
        col=0;
        row+=1;
    }


    if(G[row][col]>0){
        return suduko(G,row,col+1);
    }


    for(int i=1;i<=N;i++){
        if(isSafe(G,row,col,i)){
            G[row][col]=i;
 
            if(suduko(G,row,col+1)){
                return true;
            }
        }

        G[row][col]=0;      
        }

    
    return false;
}
int main(){
    int G[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>G[i][j];
        }
    }

    if(suduko(G,0,0)){
        cout<<endl<<endl<<endl;
        print(G);
    }
    
    else{
        cout<<"Invalid Suduko";
    }
    return 0;
}


Functions and their description-
	Print- This function takes a 9X9 matrix as an argument and output that matrix to screen which is the sudoku board.
	is Safe- This function takes the 9X9 matrix, row, column and the number and check for the constraints.
	Sudoku- This function is the recursive function where the number is filled and checked for the answer through that number if the answer is not reached then backtracking is done.

