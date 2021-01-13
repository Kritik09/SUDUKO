#include<iostream>
using namespace std;
#define N 9

//Function to print suduko
void print(int G[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Function to check constraints
bool isSafe(int G[N][N],int row,int col,int num){
    // For row
    for(int i=0;i<N;i++){
        if(G[row][i]==num){
            return false;
        }
    }

    // For column
    for(int i=0;i<N;i++){
        if(G[i][col]==num){
            return false;
        }
    }

    // For subgrid
    int srow=row-row%3;     //Knowing the starting row of subgrid
    int scol=col-col%3;     //Knowing the starting col of subgrid
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(G[i+srow][j+scol]==num){
                return false;
            }
        }
    }

    return true;    //If all constraints are satisfied then return true;
}

//Main recursive and solving function
bool suduko(int G[N][N],int row,int col){
    //If row is last row and col has reached the end so suduko is solved then return true
    if(row==N-1 && col==N){
        return true;
    }

    //If column has reached the end so col=0 and row++ to move to start of next row
    if(col==N){
        col=0;
        row+=1;
    }

    //If subsequent row and col block is filled then move to next col
    if(G[row][col]>0){
        return suduko(G,row,col+1);
    }

    //Else check for the block for right element from 1 to 9
    for(int i=1;i<=N;i++){
        if(isSafe(G,row,col,i)){
            G[row][col]=i;      //Set that value of i which satisfies constraints

            //Then check for next col recursively
            if(suduko(G,row,col+1)){
                return true;
            }
        }

        //If any constraint is not satisfied further then backtrack
        G[row][col]=0;      //Backtrack
        }

    //If suduko was unable to solve so return false
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