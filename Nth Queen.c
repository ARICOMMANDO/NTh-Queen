#include <stdio.h>
#define N 8
int board[N][N];
int solCount = 0;
void Board() {
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            board[i][j]=0; 
        }
    }
}
void printBoard(){
    for(int i =0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j]==1){
                printf("[Q] ");
            }else{
                printf("[ ] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int check(int row, int col){
    for(int i=0;i<col; i++){
        if(board[row][i]) return 0;
    }
    for(int i = row,j = col; i>=0 && j >= 0; i--,j--){
        if(board[i][j]) return 0;
    }
    for(int i = row, j=col; j>=0 && i < N; i++, j--){
        if(board[i][j]) return 0;
    }
    return 1;
}
void solve(int col){
    if (col >= N){
        solCount++;
        printf("solution %d:\n",solCount);
        printBoard();
        return;
    }
    for(int i=0; i<N; i++){
        if(check(i,col)){
            board[i][col]=1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
}
int main(){
    Board();
    solve(0);
    printf("total number of solutions: %d\n", solCount);
    return 0;
}