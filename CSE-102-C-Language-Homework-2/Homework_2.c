#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

int x_board;
int y_board;
int x_door;
int y_door;
int x_player;
int y_player;
char move;

FILE *board = fopen("game_state.txt","r");

if(board == NULL) {


board = fopen("game_state.txt","w");

printf("Generating a new board...\nEnter the width and height of board: \n");
scanf("%d %d", &x_board, &y_board);

if( x_board <= 1 || y_board <= 1) {
printf("Board size must be greater than 1 in both dimesions.\n");
remove("game_state.txt");

} else {

srand(time(NULL));
x_player = (rand() % (x_board - 1) ) + 1;
y_player = (rand() % (y_board - 1) ) + 1;
x_door = (rand() % (x_board - 1) ) + 1;
y_door = (rand() % (y_board - 1) ) + 1;

fprintf(board,"Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", x_board, y_board, x_player, y_player, x_door, y_door);

printf("Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)\n", x_board, y_board, x_player, y_player, x_door, y_door);

fclose(board);
} 

} else {

fscanf(board, "Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", &x_board, &y_board, &x_player, &y_player, &x_door, &y_door);

fclose(board);

printf("Enter move (WASD): ");
scanf(" %c", &move);

if( move == 'w' || move == 'W' ) {

if( y_player == y_board) {
printf("You hit the edge of the board and stayed where you are !!!\n");

} else {
y_player = y_player + 1;

if(y_player == y_door && x_player == x_door) {

printf("Player moves up to (%d,%d)\n", x_player, y_player);
printf("Congratulations! You escaped !\n");
printf("Generating a new board...\n");
remove("game_state.txt");
} else {

board = fopen("game_state.txt","w");

printf("Player moves up to (%d,%d)\n", x_player, y_player);
printf("Game continues...\n");

fprintf(board,"Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", x_board, y_board, x_player, y_player, x_door, y_door);

fclose(board);

}
}





} else {

if(move == 's' || move == 'S') {

if( y_player == 1) {
printf("You hit the edge of the board and stayed where you are !!!\n");


} else {
y_player = y_player - 1;

if(y_player == y_door && x_player == x_door) {

printf("Player moves down to (%d,%d)\n", x_player, y_player);
printf("Congratulations! You escaped !\n");
printf("Generating a new board...\n");
remove("game_state.txt");
} else {

board = fopen("game_state.txt","w");

printf("Player moves down to (%d,%d)\n", x_player, y_player);
printf("Game continues...\n");

fprintf(board,"Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", x_board, y_board, x_player, y_player, x_door, y_door);

fclose(board);

}
}



} else { 

if( move == 'A' || move == 'a' ) {

if( x_player == 1) {
printf("You hit the edge of the board and stayed where you are !!!\n");


} else {
x_player = x_player - 1;

if(y_player == y_door && x_player == x_door) {

printf("Player moves left to (%d,%d)\n", x_player, y_player);
printf("Congratulations! You escaped !\n");
printf("Generating a new board...\n");
remove("game_state.txt");
} else {

board = fopen("game_state.txt","w");

printf("Player moves left to (%d,%d)\n", x_player, y_player);
printf("Game continues...\n");

fprintf(board,"Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", x_board, y_board, x_player, y_player, x_door, y_door);

fclose(board);

}
}






} else {


if( move == 'd' || move == 'D' ) {

if( x_player == x_board) {
printf("You hit the edge of the board and stayed where you are !!!\n");


} else {
x_player = x_player + 1;

if(y_player == y_door && x_player == x_door) {

printf("Player moves right to (%d,%d)\n", x_player, y_player);
printf("Congratulations! You escaped !\n");
printf("Generating a new board...\n");
remove("game_state.txt");
} else {

board = fopen("game_state.txt","w");

printf("Player moves right to (%d,%d)\n", x_player, y_player);
printf("Game continues...\n");

fprintf(board,"Width: %d, Height: %d Player: (%d,%d), Door: (%d,%d)", x_board, y_board, x_player, y_player, x_door, y_door);

fclose(board);

}
}





} else {

printf("Invalıd ınput. You can only use WASD.\n");

}

}
}
}
}

return 0;

}








