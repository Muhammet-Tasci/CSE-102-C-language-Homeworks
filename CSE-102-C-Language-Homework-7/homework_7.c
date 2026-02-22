#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 100

int move_rows[MAX_MOVES];
int move_cols[MAX_MOVES];
int move_top = 0;

void push(int row, int col ) {
    if(move_top < MAX_MOVES) {
        move_rows[move_top] = row;
        move_cols[move_top] = col;
        move_top++;
    }
}

void pop() {
    if(move_top > 0 ){
    move_top--;

    }
}

int isEmpty() {
    return move_top == 0;
}


char** make_board(int* N) {
int i;
int k;
int bomb;

*N = 2 + rand() % 9;
char** board;


board = (char**)malloc((*N) * sizeof(char*));

for(i=0;i<*N;i++) {
    board[i] = (char*)malloc((*N) * sizeof(char));
}

FILE* file = fopen("map.txt","w");


for(i=0; i<*N;i++) {
    for(k=0;k<*N;k++){ 
       bomb = rand();
       if(bomb % 4 == 0) {
        board[i][k] = '*';
        fprintf(file,"*");
       }else{
        board[i][k] = '#';
        fprintf(file,".");
       }
    }
    fprintf(file,"\n");
}


fclose(file);


return board;
}


void flood(char** board, int row, int col, char** board_user,int N, int* X) {
    int dx;
    int dy;
    int bomb_counter;

        if(board[row][col] == '*') {
        board_user[row][col] ='X';
        *X = 1;
        return;
        }
        
        if(board_user[row][col] != '#') return;
        
        int temp_row;
        int temp_col;
        
            bomb_counter = 0;
            for(dy=-1;dy<=1;dy++) {
                for(dx=-1;dx<=1;dx++){
                    temp_row = row + dy;
                    temp_col = col + dx;
                    if(temp_row>= 0 && temp_row<N && temp_col>= 0 && temp_col<N && (dy != 0 || dx != 0) ) {
                        if(board[temp_row][temp_col] == '*') {
                            bomb_counter++;
                        }

                    }
                }
            }

            board_user[row][col] = bomb_counter + '0';
            
            if(bomb_counter == 0) {


                for(dy=-1;dy<=1;dy++) {
                    for(dx=-1;dx<=1;dx++){
                        temp_row = row + dy;
                        temp_col = col + dx;
                        if(temp_row>= 0 && temp_row<N && temp_col>= 0 && temp_col<N && (dy != 0 || dx != 0) ) {
                            if(board_user[temp_row][temp_col] == '#') {
                            flood(board, temp_row, temp_col, board_user, N, X);
                            }
                            }
    
                        }
                    }
                }

            
        }



void print_user(char** board_user, int N) {
int i;
int k;

    printf(" ");
    for(i=0;i<N;i++) {
        printf(" %d",i);
    }
printf("\n");
    for(i=0;i<N;i++) {
        printf("%d",i);
        for(k=0;k<N;k++) {
            printf(" %c",board_user[i][k]);
        }
        printf("\n");
    }
}


void refresh_board(char** board_user,int N) {
int i;
int k;
    for(i=0;i<N;i++) {
        for(k=0;k<N;k++) {
            board_user[i][k] = '#';
        }
    }

}


int main() {
int i,k;
int N,flag;
int row,col;
int X = 0;
char input [100];

srand(time(NULL));

char** board = make_board(&N);

char** board_user = (char**)malloc(N * sizeof(char*));
for (i = 0; i < N; i++) {
    board_user[i] = (char*)malloc(N * sizeof(char));
}

refresh_board(board_user,N);

print_user(board_user,N);

while(X==0) {
printf("Enter move(row col) or 'undo': ");

    fgets(input, sizeof(input), stdin); 

    i = 0;
    while (input[i] != '\0') {  
        i++;
    }

    if (i > 0 && input[i - 1] == '\n') {  
        input[i - 1] = '\0'; 
    }


    if (input[0] == 'u' && input[1] == 'n' && input[2] == 'd' && input[3] == 'o' && input[4] == '\0') {
       if(isEmpty()){
        printf("No move has been made yet.\n");
       }else {
        refresh_board(board_user,N);
        pop();

        for(i=0;i<move_top;i++) {
            flood(board,move_rows[i],move_cols[i],board_user, N, &X);
        }
        printf("Last move undone.\n\n");
        print_user(board_user,N);
        printf("\n");
       }



    } else {
        int result = sscanf(input, "%d %d", &row, &col);
        if (result == 2 && row>=0 && row<= N-1 && col>=0 && col<=N-1 ) { 
            push(row,col);
            flood(board,row,col,board_user,N, &X);
            print_user(board_user,N);
            printf("\n");

            if(X == 1) {
            break;
           }
            flag = 1;
            for(i=0;i<N;i++) {
                for(k=0;k<N;k++) {
                    if(board_user[i][k] == '#' && board[i][k] != '*'){
                       flag = 0;
                       X = 0;
                       break;
                        }
                    }
                    if(!flag) break;
                }

                if(flag == 1){
                    X = 2;
                }
            

        } else {
            printf("İnvalid input.\n\n");
        }
    }

}

if(X == 2) {
    printf("Congratulations!!! You won the game.\n");
}else{
    printf("BOOM ! You hit a mine. Game Over.\n");
}
FILE* moves = fopen("moves.txt","w");
fprintf(moves,"--- Game Moves ---\n");

for(i=0;i<move_top;i++) {
    fprintf(moves,"Move %d: (Row %d, Col %d)\n",i+1,move_rows[i],move_cols[i]);
}

fprintf(moves,"\nTotal Moves: %d\n",move_top);

fclose(moves);



for(i=0;i<N;i++) {
  free(board[i]);
}

free (board);
return 0;
}