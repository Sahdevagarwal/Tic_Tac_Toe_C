#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char player = 'X';
int moves = 9;
typedef void (*BotMove)(char board[3][3], char botSymbol, char humanSymbol);

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
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }
        if (ch < 1 || ch > 9) {
            printf("Invalid position! Please enter a number between 1 and 9.\n");
            continue;
        }

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

void EasyBot(char board[3][3], char botSymbol, char humanSymbol){
    int ch,row,col;

    while(1){
        ch = rand()% 9 + 1;
        row = (ch-1)/3;
        col = (ch-1)%3;

        if (board[row][col] == ' '){
            board[row][col] = botSymbol;
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

void MediumBot(char board[3][3], char botSymbol, char humanSymbol){
    int r,c;

    if(FindMove(board,botSymbol,&r,&c)){
        board[r][c] = botSymbol;
        return;
    }
    else if(FindMove(board,humanSymbol,&r,&c)){
        board[r][c] = botSymbol;
        return;
    }
    else{
        EasyBot(board, botSymbol, humanSymbol);
    }
}

void Gameloop(char board[3][3], BotMove bot, char humanSymbol, char botSymbol){
    int ch;
    Instructions();
    ShowBoard(board);
    while (1){
        if (player == humanSymbol){
            printf("Player %c , Enter position (1-9): ",player);
            if (scanf("%d", &ch) != 1) {
                printf("Invalid input! Please enter a number between 1 and 9.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                continue;
            }
            if (ch < 1 || ch > 9) {
                printf("Invalid position! Please enter a number between 1 and 9.\n");
                continue;
            }

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
            bot(board, botSymbol, humanSymbol);
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

int Evaluation(char board[3][3], char botSymbol, char humanSymbol){
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == botSymbol) return 10;
            else if (board[i][0] == humanSymbol) return -10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == botSymbol) return 10;
            else if (board[0][i] == humanSymbol) return -10;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == botSymbol) return 10;
        else if (board[0][0] == humanSymbol) return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == botSymbol) return 10;
        else if (board[0][2] == humanSymbol) return -10;
    }
    return 0;
}

int MovesLeft(char board[3][3]){
    for (int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(board[i][j] == ' '){
                return 1;
            }
        }
    }
    return 0;
}

int Minimax(char board[3][3], int depth, int isMax, char botSymbol, char humanSymbol){
    int score = Evaluation(board, botSymbol, humanSymbol);

    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if(!MovesLeft(board)){
        return 0;
    }
    if (isMax){
        int best = -1000;

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if (board[i][j] == ' '){
                    board[i][j] = botSymbol;
                    int value = Minimax(board, depth + 1, 0, botSymbol, humanSymbol);
                    if (value > best){
                        best = value;
                    }
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else{
        int best = 1000;

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if (board[i][j] == ' '){
                    board[i][j] = humanSymbol;
                    int value = Minimax(board, depth + 1, 1, botSymbol, humanSymbol);
                    if (value < best){
                        best = value;
                    }
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void HardBot(char board[3][3], char botSymbol, char humanSymbol){
    int bestVal = -1000;
    int bestRow = -1;
    int bestCol = -1;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j] = botSymbol;
                int moveVal = Minimax(board, 0, 0, botSymbol, humanSymbol);
                board[i][j] = ' ';

                if(moveVal > bestVal){
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    if (bestRow != -1 && bestCol != -1) {
        board[bestRow][bestCol] = botSymbol;
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
    srand(time(NULL));
    printf("Enter 1 to play against another or 2 to play against computer: ");
    if (scanf("%d", &ch) != 1) {
        printf("Invalid Input! Exiting...\n");
        return 1;
    }
    if (ch == 1){
        Player(board);
    }
    else if (ch == 2){
        char humanSymbol, botSymbol;
        printf("\nDo you want to play as X or O? (X goes first): ");
        if (scanf(" %c", &humanSymbol) != 1) {
            printf("Invalid Input! Exiting...\n");
            return 1;
        }
        if (humanSymbol == 'x') humanSymbol = 'X';
        if (humanSymbol == 'o') humanSymbol = 'O';

        if (humanSymbol != 'X' && humanSymbol != 'O') {
            printf("Invalid symbol! Exiting...\n");
            return 1;
        }
        botSymbol = (humanSymbol == 'X') ? 'O' : 'X';

        int n;
        printf("\n---------Choose Difficulty---------\n");
        printf("1.Easy\n");
        printf("2.Medium\n");
        printf("3.Hard\n");
        printf("Enter Your Choice: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid Choice! Exiting...\n");
            return 1;
        }
        switch (n){
            case 1:
                Gameloop(board,EasyBot, humanSymbol, botSymbol);
                break;
            case 2:
                Gameloop(board,MediumBot, humanSymbol, botSymbol);
                break;
            case 3:
                Gameloop(board,HardBot, humanSymbol, botSymbol);
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