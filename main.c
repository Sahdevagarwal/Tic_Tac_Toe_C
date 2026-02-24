#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char player = 'X';
int moves = 9;
typedef void (*BotMove)(char board[3][3]);

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

int WinCheck(char board[3][3]){
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

void Player(char board[3][3]){
    int ch;
    Instructions();
    ShowBoard(board);
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
        if(WinCheck(board)){
            break;
        }
        else if(moves == 0){
            printf("Draw!");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

void EasyBot(char board[3][3]){
    int ch,row,col;
    srand(time(NULL));

    while(1){
        ch = rand()% 9 + 1;
        row = (ch-1)/3;
        col = (ch-1)%3;

        if (board[row][col] == ' '){
            board[row][col] = 'O';
        }
        else{
            continue;
        }
        break;
    }
}

int FindMove(char board[3][3],char symbol,int *r,int *c){
    int win[8][3][2] = {
        {{0,0},{0,1},{0,2}},
        {{1,0},{1,1},{1,2}},
        {{2,0},{2,1},{2,2}},

        {{0,0},{1,0},{2,0}},
        {{0,1},{1,1},{2,1}},
        {{0,2},{1,2},{2,2}},

        {{0,0},{1,1},{2,2}},
        {{0,2},{1,1},{2,0}}
    };

    for (int i=0;i<8;i++){

        int count = 0;
        int empty = -1;

        for(int j = 0;j < 3;j++){
            int row = win[i][j][0];
            int col = win[i][j][1];

            if(board[row][col] == symbol){
                count++;
            }
            else if (board[row][col] == ' '){
                empty = j;
            }
        }
        if(count == 2 && empty != -1){
            *r = win[i][empty][0];
            *c = win[i][empty][1];
            return 1;
        }
    }
    return 0;
}

void MediumBot(char board[3][3]){
    int r,c;

    if(FindMove(board,'O',&r,&c)){
        board[r][c] = 'O';
        return;
    }
    else if(FindMove(board,'X',&r,&c)){
        board[r][c] = 'O';
        return;
    }
    else{
        EasyBot(board);
    }
}

void Gameloop(char board[3][3], BotMove bot){
    int ch;
    Instructions();
    ShowBoard(board);
    while (1){
        if (player == 'X'){
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
        }
        else{
            bot(board);
        }
        moves--;
        ShowBoard(board);
        printf("-\t-\t-\t-\t-\t-\t-\t-\n\n");
        if(WinCheck(board)){
            break;
        }
        else if(moves == 0){
            printf("Draw!");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main(){
    char board[3][3];
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
    int ch;
    printf("Enter 1 to play against another or 2 to play against computer: ");
    scanf("%d",&ch);
    if (ch == 1){
        Player(board);
    }
    else if (ch == 2){
        int n;
        printf("\n---------Choose Difficulty---------\n");
        printf("1.Easy\n");
        printf("2.Medium\n");
        printf("3.Hard\n");
        printf("Enter Your Choice: ");
        scanf("%d",&n);
        switch (n){
            case 1:
                Gameloop(board,EasyBot);
                break;
            case 2:
                Gameloop(board,MediumBot);
                break;
            case 3:
                printf("Coming Soon");
                break;
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    else{
        printf("Invalid Input!");
    }
}