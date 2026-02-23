#include <stdio.h>

void Instructions(){
    printf("\t\t\t Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below and play\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void ShowBoard(char board[3][3]){
    printf("\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

int WinCheck(char board[3][3],char player){
    for(int i = 0;i < 3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            printf("Player %c has won!\n",player);
            return 1;
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            printf("Player %c has won!\n",player);
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
        printf("Player %c has won!\n",player);
        return 1;
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
        printf("Player %c has won!\n",player);
        return 1;
    }
    else{
        return 0;
    }
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
    
    char player = 'X';
    int ch,moves=9;

    while(1){
        printf("Player %c , Enter position (1-9): ",player);
        scanf("%d",&ch);

        int row = (ch-1)/3;
        int col = (ch-1)%3;

        if(board[row][col] == ' '){
            board[row][col] = player;
        }
        else{
            printf("Cell is Not Empty!\n");
            continue;
        }
        moves--;
        ShowBoard(board);
        if(WinCheck(board,player)){
            break;
        }
        else if(moves == 0){
            printf("Draw!");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    
}