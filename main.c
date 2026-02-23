#include <stdio.h>

void Instructions(){
    printf("\t\t\t Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below "
           "and play\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void ShowBoard(char board[3][3]){
    printf("\n");

    for(int i=0;i<3;i++){
        printf("\t\t\t ");
        for(int j=0;j<3;j++){
            printf(" %c ", board[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");

        if(i<2)
            printf("\t\t\t-------------\n");
    }

    printf("\n");
}

int main(){
    char board[3][3];
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
    Instructions();
    ShowBoard(board);
}