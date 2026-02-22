#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void make_board( char board[N][N],char copy[N][N]) {
int direction;
int head_x;
int head_y;
int flag = 0;
int temp;
int i;

/* 4lük için*/


direction = rand();

if( direction % 2 == 0) {
/* çiftse aşağı */


head_x = rand() % 10;
head_y = rand() % 7;


for(i = 0; i < 4;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'A';
head_y = head_y + 1;
}

}else{
/* degilse saga */


head_x = rand() % 7;
head_y = rand() % 10;

for(i = 0; i < 4;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'A';
head_x = head_x + 1;
}

}




/* ilk 3lük */

direction = rand();

if( direction % 2 == 0) {

/* çiftse aşağı */
do {
flag = 0;


head_x = rand() % 10;
head_y = rand() % 8;
temp = head_y;

for(i = 0; i < 3;i++) {

if ( board[temp][head_x] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 3;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'B';
head_y = head_y + 1;
}



}else{
/* degilse saga */

do {
flag = 0;

head_x = rand() % 8;
head_y = rand() % 10;
temp = head_x;

for(i = 0; i < 3;i++) {

if ( board[head_y][temp] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 3;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'B';
head_x = head_x + 1;
}

}



/* ikinci 3lük */

direction = rand();

if( direction % 2 == 0) {

/* çiftse aşağı */
do {
flag = 0;

head_x = rand() % 10;
head_y = rand() % 8;
temp = head_y;

for(i = 0; i < 3;i++) {

if ( board[temp][head_x] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 3;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'b';
head_y = head_y + 1;
}



}else{
/* degilse saga */

do {
flag = 0;

head_x = rand() % 8;
head_y = rand() % 10;
temp = head_x;

for(i = 0; i < 3;i++) {

if ( board[head_y][temp] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 3;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'b';
head_x = head_x + 1;
}

}




/* 2lik */

direction = rand();

if( direction % 2 == 0) {

/* çiftse aşağı */
do {
flag = 0;

head_x = rand() % 10;
head_y = rand() % 9;
temp = head_y;

for(i = 0; i < 2;i++) {

if ( board[temp][head_x] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 2;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'C';
head_y = head_y + 1;
}



}else{
/* degilse saga */

do {
flag = 0;

head_x = rand() % 9;
head_y = rand() % 10;
temp = head_x;

for(i = 0; i < 2;i++) {

if ( board[head_y][temp] != '-') {
flag = 1;
break;
}

temp = temp + 1;
} 

}while(flag == 1);

for(i = 0; i < 2;i++) {
board[head_y][head_x] = 'S';
copy[head_y][head_x] = 'C';
head_x = head_x + 1;
}

}

}



void board_file(char board[N][N]) {
int i;
int k;

FILE *ships = fopen("ships.txt","w");

fprintf(ships," ");
for(i = 0; i < 10; i++) {
fprintf(ships," %d",i);
}
fprintf(ships,"\n");

for(i = 0; i < 10;i++) {
fprintf(ships,"%d ",i);
for(k = 0; k < 10;k++) {
fprintf(ships,"%c ",board[i][k]);
}
fprintf(ships,"\n");

}

fclose(ships);

}


void player_board(char print[N][N]) {
int i;
int k;

printf(" ");
for(i = 0; i < 10; i++) {
printf(" %d",i);
}
printf("\n");

for(i = 0; i < 10;i++) {
printf("%d ",i);
for(k = 0; k < 10;k++) {
printf("%c ",print[i][k]);
}
printf("\n");

}

}











int main() {

int i;
int k;
int x;
int y;
int finish = 0;
int counter = 0;
int shot = 0;
char option;
char input[100];

char board[N][N];
char print[N][N];
char copy[N][N];

/* ship-4 A , ship-3_1 B, ship-3_2 b,  ship-2 C in copyde */
srand(time(NULL));



for(i = 0; i < N;i++) {
for(k = 0; k < N;k++) {

board[i][k] = '-';
copy[i][k] = '-';
print[i][k] = '-';
}
}


make_board(board, copy);

board_file(board);

FILE* log;



remove("battleship_log.txt");
printf("Welcome the Battleship Game !\n");

player_board(print);


do { 


if( finish == 2) {
remove("battleship_log.txt");
finish = 0;
counter = 0;
shot = 0;

for(i = 0; i < N;i++) {
for(k = 0; k < N;k++) {

board[i][k] = '-';
copy[i][k] = '-';
print[i][k] = '-';
}
}


make_board(board, copy);

board_file(board);

FILE* log;




printf("Welcome the Battleship Game !\n");

player_board(print);
}


printf("Enter the coordinates (X to quit): ");

while (1) {
fgets(input, sizeof(input), stdin);


if (input[0] == 'X' && input[1] == '\n') {
option = 'K'; 
break;
  }

        /* Sayıları okumayı dene */
if (sscanf(input, "%d %d", &y, &x) == 2) {
   if (x >= 0 && x <= 9 && y >= 0 && y <= 9) {
   option = copy[y][x];
break;
    }
}

        /* Geçersiz giriş */
        printf("Invalid input. Please enter values between 0 and 9: ");
    }



switch(option) {

case '-':
board[y][x] = 'O';
copy[y][x] = 'O';
print[y][x] = 'O';

log = fopen("battleship_log.txt", "a");
fprintf(log,"Shot: %d %d - MISS\n",y ,x);
fclose(log);
shot++;

board_file(board);

printf("MISS!\n\n\n");
player_board(print);

break;




case 'A':

board[y][x] = 'X';
copy[y][x] = 'X';
print[y][x] = 'X';

log = fopen("battleship_log.txt", "a");
fprintf(log,"Shot: %d %d - HITT\n",x ,y);
fclose(log);
shot++;
board_file(board);


counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( board[i][k] == 'S') {
     counter++;
    }
   }
}

if( counter == 0 ) {
printf("HIT!\nCongratulations ! You sank a 4-cell ship !\nAll ships are sunk! Total shots: %d\n", shot);
player_board(print);
printf("Press 'N' to play again or 'X' to exit: ");

while (1) {
scanf(" %c", &option);
while( getchar() != '\n');

if ( option == 'N') {
finish = 2 ;
break;
}else{

if( option == 'X') {
finish = 1;
break;
} else {
printf("Press only 'N' to play again or 'X' to exit. Do not press any other keys: ");
}
}
}


} else {

counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( copy[i][k] == 'A') {
     counter++;
    }
   }
}

if ( counter == 0) {
printf("HIT!\nCongratulations ! You sank a 4-cell ship !\n\n");
player_board(print);


} else {

printf("HITT!\n\n\n");
player_board(print);
}

}
break;





case 'B':

board[y][x] = 'X';
copy[y][x] = 'X';
print[y][x] = 'X';

log = fopen("battleship_log.txt", "a");
fprintf(log,"Shot: %d %d - HITT\n",y ,x);
fclose(log);
shot++;
board_file(board);


counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( board[i][k] == 'S') {
     counter++;
    }
   }
}

if( counter == 0 ) {
printf("HIT!\nCongratulations ! You sank a 3-cell ship !\nAll ships are sunk! Total shots: %d\n", shot);
player_board(print);
printf("Press 'N' to play again or 'X' to exit: ");

while (1) {
scanf(" %c", &option);
while( getchar() != '\n');

if ( option == 'N') {
finish = 2;
break;
}else{

if( option == 'X') {
finish = 1;
break;
} else {
printf("Press only 'N' to play again or 'X' to exit. Do not press any other keys: ");
}
}
}


} else {

counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( copy[i][k] == 'B') {
     counter++;
    }
   }
}

if ( counter == 0) {
printf("HIT!\nCongratulations ! You sank a 3-cell ship !\n\n");
player_board(print);


} else {

printf("HITT!\n\n\n");
player_board(print);
}


}
break;



case 'b':

board[y][x] = 'X';
copy[y][x] = 'X';
print[y][x] = 'X';

log = fopen("battleship_log.txt", "a");
fprintf(log,"Shot: %d %d - HITT\n",y ,x);
fclose(log);
shot++;
board_file(board);


counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( board[i][k] == 'S') {
     counter++;
    }
   }
}

if( counter == 0 ) {
printf("HIT!\nCongratulations ! You sank a 3-cell ship !\nAll ships are sunk! Total shots: %d\n", shot);
player_board(print);
printf("Press 'N' to play again or 'X' to exit: ");

while (1) {
scanf(" %c", &option);
while( getchar() != '\n');

if ( option == 'N') {
finish = 2;
break;
}else{

if( option == 'X') {
finish = 1;
break;
} else {
printf("Press only 'N' to play again or 'X' to exit. Do not press any other keys: ");
}
}
}


} else {

counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( copy[i][k] == 'b') {
     counter++;
    }
   }
}

if ( counter == 0) {
printf("HIT!\nCongratulations ! You sank a 3-cell ship !\n\n");
player_board(print);


} else {

printf("HITT!\n\n\n");
player_board(print);
}

}
break;



case 'C':

board[y][x] = 'X';
copy[y][x] = 'X';
print[y][x] = 'X';

log = fopen("battleship_log.txt", "a");
fprintf(log,"Shot: %d %d - HITT\n",y ,x);
fclose(log);
shot++;
board_file(board);


counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( board[i][k] == 'S') {
     counter++;
    }
   }
}

if( counter == 0 ) {
printf("HIT!\nCongratulations ! You sank a 2-cell ship !\nAll ships are sunk! Total shots: %d\n", shot);
player_board(print);
printf("Press 'N' to play again or 'X' to exit: ");

while (1) {
scanf(" %c", &option);
while( getchar() != '\n');
if ( option == 'N') {
finish = 2;
break;
}else{

if( option == 'X') {
finish = 1;
break;
} else {
printf("Press only 'N' to play again or 'X' to exit. Do not press any other keys: ");
}
}
}


} else {

counter = 0;

for (i = 0; i < N; i++) {
    for ( k = 0; k < N; k++) {
    
     if ( copy[i][k] == 'C') {
     counter++;
    }
   }
}

if ( counter == 0) {
printf("HIT!\nCongratulations ! You sank a 2-cell ship !\n\n");
player_board(print);


} else {

printf("HITT!\n\n\n");
player_board(print);
}

}
break;


case 'K':
finish = 1;
break;

default:
printf("You have tried this coordinate before.\n\n");
break;

}

} while(finish != 1);

remove("battleship_log.txt");

return 0;
}


