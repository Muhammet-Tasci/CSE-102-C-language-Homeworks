#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Enum for the state of a cell: empty, computer(X), user(O) */
typedef enum {
    empty, /* 0 for .*/
    computer, /* 1 for X*/
    user, /* 2 for O*/
} cellstate;

/* Struct for representing a position on the board */
typedef struct {
    int x;
    int y;
}position;

/* Function to print the current board */
void print_board(cellstate** board, int size) {
int i,k;
char temp = 'a';

    printf("  ");
    for(i=0;i<size;i++){
        printf("%c ",temp +i);
    }
    printf("\n");

    for(i=0;i<size;i++){
        printf("%d ",i+1);
        for(k=0;k<size;k++){
            if(board[i][k] == empty)printf(". ");
            if(board[i][k] == computer)printf("X ");
            if(board[i][k] == user)printf("O ");
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to calculate and print current score */
void score_board(cellstate** board,int size){
    int i,k;
    int computer_score = 0;
    int user_score = 0;

    for(i=0;i<size;i++){
        for(k=0;k<size;k++){
            if(board[i][k] == computer)computer_score++;
            if(board[i][k] == user)user_score++;
        }
    }

    printf("Computer: %d  |  User: %d \n",computer_score, user_score);

}

/* Check if a move is valid for the current player */
int ismove_valid(cellstate** board, int size, position move, cellstate player) {
    int di;
    cellstate opponent;
    if(move.x < 0 || move.x >= size || move.y < 0 || move.y >= size || board[move.y][move.x] != 0) return 0;

    if(player == computer) {
        opponent = user;
    }else{
        opponent = computer;
    }

    /* All 8 directions (N, NE, E, SE, S, SW, W, NW) */
    int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
    int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

    /* Check all directions for a valid capturing move */
    for(di=0; di<8;di++){

        int x = move.x + dx[di];
        int y = move.y + dy[di];
        int found_opponent = 0;

        while (x >= 0 && x < size && y >= 0 && y < size) {
            if (board[y][x] == empty)break;

            if (board[y][x] == player) {
                if (found_opponent){
                    return 1;
                }else{
                    break;
                }
            }
            if (board[y][x] == opponent)found_opponent = 1;

            x += dx[di];
            y += dy[di];
        }
    }

    return 0;

}

/* Apply a valid move to the board and flip opponent cells */
void apply_move(cellstate** board, int size, position move, cellstate player) {
    int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
    int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};
    cellstate opponent;
    int d; 

    if(player == computer) {
        opponent = user;
    }else{
        opponent = computer;
    }

    board[move.y][move.x] = player; /* Place the new piece */

    for (d = 0; d < 8; d++) {
        int x = move.x + dx[d];
        int y = move.y + dy[d];
        int count = 0;

        /* Count opponent cells in the current direction */
        while (x >= 0 && x < size && y >= 0 && y < size && board[y][x] == opponent) {
            x += dx[d];
            y += dy[d];
            count++;
        }

        /* If player piece is found after opponent pieces, flip them */
        if (x >= 0 && x < size && y >= 0 && y < size && board[y][x] == player) {
            int flip_x = move.x + dx[d];
            int flip_y = move.y + dy[d];
            for (int i = 0; i < count; i++) {
                board[flip_y][flip_x] = player;
                flip_x += dx[d];
                flip_y += dy[d];
            }
        }
    }

}

/* Simulate the move to find how many opponent cells would be flipped */
int simulate_move(cellstate** board, int size, position move) {
    int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
    int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};
    cellstate opponent;
    int total_flip = 0;
    int d; 

    for (d = 0; d < 8; d++) {
        int x = move.x + dx[d];
        int y = move.y + dy[d];
        int count = 0;

        /* Count opponent cells in this direction */
        while (x >= 0 && x < size && y >= 0 && y < size && board[y][x] == user) {
            x += dx[d];
            y += dy[d];
            count++;
        }

        /* Add to total if followed by a computer piece */
        if (x >= 0 && x < size && y >= 0 && y < size && board[y][x] == computer) {
            total_flip += count;
        }
    }

    return total_flip;

}

/* Check if player has any valid move */
int has_valid_move(cellstate** board,int size,cellstate player){
    int i,k;
    position temp;
    for(i=0;i<size;i++){
        for(k=0;k<size;k++){
            temp.x = k;
            temp.y = i;
            if(ismove_valid(board,size,temp,player))return 1;
        }
    }

    return 0;
}

/* Recursive function to alternate turns between user and computer */
void playturn(cellstate** board,int size, cellstate player) {
    position move;
    char temp;

    score_board(board,size);

    /* End the game if no moves for both players */
    if(!has_valid_move(board,size,computer) && !has_valid_move(board,size,player)) {
        printf("Game Over.\n");
        return;
    }

    if(player == user) {

        if(!has_valid_move(board,size,player) ) {
            printf("There are not any move that you can do. Your turn pass.\n");
        }else{

            print_board(board,size);
            printf("Please enter the your next move (y x): ");

            /* Loop until a valid user move is entered */
            while (1) {
                if (scanf(" %d %c", &move.y, &temp) != 2) {
                    while (getchar() != '\n'); /* flush invalid input */
                    printf("Invalid input. Please try again: ");
                    continue;
                }

                if(temp < 'a' || temp > ('a' + size - 1)){
                    printf("Invalid move. Please try again: ");
                    continue;
                }

                move.x = temp - 'a';
                move.y -= 1;

                if (!ismove_valid(board, size, move, player)) {
                    printf("Invalid move. Please try again: ");
                    continue;
                }

                break; 
            }

            apply_move(board,size,move,player);
            print_board(board,size);
        }

        playturn(board,size,computer); /* Computer turn */

    }else{
        int i,k;
        int max_flip = 0;
        int temp_flip;
        position best_move;

        if(!has_valid_move(board,size,player) ) {
            printf("There are not any move that computer can do. Computer turn pass.\n");
        }else{

            /* Try all moves and choose the one with maximum gain */
            for(i=0;i<size;i++){
                for(k=0;k<size;k++){
                    move.x = k;
                    move.y = i;

                    if(ismove_valid(board,size,move,player) ){

                        temp_flip = simulate_move(board,size,move);
                        if(temp_flip > max_flip){
                            max_flip = temp_flip;
                            best_move = move;
                        }
                    }
                }
            }

            apply_move(board,size,best_move,player);
            printf("Computer moved its turn.\n\n");
        }

        playturn(board,size,user); /* User turn */
    }

}

/* Determine who won the game and print result */
void who_won(cellstate** board,int size) {
    int i,k;
    int user_counter = 0;
    int computer_counter = 0;

    for(i=0;i<size;i++){
        for(k=0;k<size;k++){
            if(board[i][k] == computer)computer_counter++;
            if(board[i][k] == user)user_counter++;
        }
    }

    if(computer_counter > user_counter) printf("Computer won! Dont be sad. It is very clever.");
    if(user_counter > computer_counter) printf("You won! You are smarter than you look.");
    if(computer_counter == user_counter) printf("TİE. Wow this is rare.");

}


/* Main function: initialize board, run the game, clean memory */
int main() {
    cellstate** board;
    int board_size;
    int i,k;

    printf("Please enter a digit for the board size: ");

    /* Validate board size (must be even and >= 4) */
    while (scanf(" %d",&board_size) != 1 || board_size % 2 != 0 || board_size < 4) {
        while(getchar() != '\n');
        printf("Please enter a even digit that bigger than 3: ");
    }

    /* Allocate memory for the board */
    board = (cellstate**)malloc(board_size * sizeof(cellstate*));

    for(i=0; i< board_size;i++){
        board[i] = (cellstate*)malloc(board_size * sizeof(cellstate));
    }

    /* Initialize all cells to empty */
    for(i=0;i<board_size;i++){
        for(k=0;k<board_size;k++){
            board[i][k] = 0;
        }
    }

    /* Set initial 4 pieces in the center */
    board[(board_size / 2) - 1][(board_size / 2) - 1] = computer;
    board[(board_size / 2) - 1][(board_size / 2)] = user;
    board[(board_size / 2)][(board_size / 2) - 1] = user;
    board[(board_size / 2)][(board_size / 2)] = computer;

    /* Start the game */
    playturn(board,board_size,user);
    print_board(board,board_size);
    who_won(board,board_size);

    /* Free dynamically allocated memory */
    for(i=0;i<board_size;i++){
        free(board[i]);
    }

    free(board);

    return 0;
}
