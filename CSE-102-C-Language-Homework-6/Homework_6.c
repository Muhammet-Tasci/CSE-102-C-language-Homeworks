#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_code() {
int* code;

int control;
int flag = 0;
int i;
int k;
int code_l;
int d_min;
int d_max;
int duplicate;


FILE *rules = fopen("vault_config.txt","r");

fscanf(rules,"CODE_LENGTH=%d\nDIGIT_MIN=%d\nDIGIT_MAX=%d\nMAX_ATTEMPTS=%*d\nALLOW_DUPLICATES=%d\nPOINTS_CORRECT=%*d\nPOINTS_MISPLACED=%*d\nPENALTY_WRONG=%*d",&code_l, &d_min, &d_max, &duplicate);

fclose(rules);

srand(time(NULL));
code = (int*)malloc(code_l * sizeof(int));

if( duplicate == 1) {

for(i = 0; i<code_l;i++) {

code[i] = d_min + rand() % (d_max - d_min + 1);

}

}else{

for(i = 0; i<code_l;i++) {

do {
control = d_min + rand() % (d_max - d_min + 1);

flag = 0;
for(k = 0; k < i;k++) {
if(code[k] == control) {
flag = 1;
break;
}

}

}while(flag == 1);
flag = 0;

code[i] = control;

}

}

return code;

}

int* get_guess() {

int* guess;
int i;
int code_l;
int valid = 0;

FILE *rules = fopen("vault_config.txt","r");

fscanf(rules,"CODE_LENGTH=%d\nDIGIT_MIN=%*d\nDIGIT_MAX=%*d\nMAX_ATTEMPTS=%*d\nALLOW_DUPLICATES=%*d\nPOINTS_CORRECT=%*d\nPOINTS_MISPLACED=%*d\nPENALTY_WRONG=%*d",&code_l);

fclose(rules);

guess = (int*)malloc(code_l * sizeof(int));


do {    
printf("Enter your guess: ");
valid = 0;

for (i = 0; i < code_l; i++) {
if( scanf("%1d", &guess[i]) != 1) {
valid = 1;
while( getchar() != '\n');
printf("Invalid ınput.\n");
break;
}

}


}while(valid == 1);
valid = 0;



return guess;

}


int main() {

setenv("TZ", "Europe/Istanbul", 1);
tzset();
    
int *guess;
int *code;

int i;
int k;
int t;
int counter;
int score = 0;
int place;
char user;
int code_l;
int d_min;
int d_max;
int duplicate;
int max_att;
int correct;
int misplaced;
int wrong;
int flag;

FILE *rules;

printf("Press A Administrator mode or P for Player mode: ");
scanf("%c",&user);

switch(user) {

case 'A':

 printf("Do you allow duplicates( 0 = No, 1 = Yes): ");
while(!flag){

if( scanf("%d", &duplicate) != 1 ) {
while( getchar() != '\n');
printf("Invalid input. Please enter only 0 or 1: ");

} else{
if(duplicate != 1 && duplicate != 0) {
printf("Invalid input. Please enter only 0 or 1: ");
}else{
flag = 1;
}
}
}flag = 0;

while (1) {

printf("Please enter the code length(e.g., 4): ");
  while( scanf("%d", &code_l) != 1 || code_l <= 0) {
while( getchar() != '\n');
printf("Invalid input. Please enter only positive digit: ");

}


 printf("Please enter the minimum digit(e.g., min:0): ");
 while(!flag) {
 if( scanf("%d", &d_min) != 1 || d_min < 0 || d_min > 9) {
 while( getchar() != '\n');
 printf("Invalid input. Please enter only positive digit or zero: ");
 } else {
 if( d_min == 9) {
 printf("Minimum digit can not be 9. Please enter another digit: ");
 } else {
 flag = 1;
 }
 }
 } flag = 0;
 

 printf("Please enter the maximum digit(e.g., max:9): ");
 while(!flag) {
 if( scanf("%d", &d_max) != 1 || d_max <= 0 || d_max > 9) {
 while( getchar() != '\n');
 printf("Invalid input. Please enter only positive digit: ");
 } else {
 if( d_max <= d_min) {
 printf("Minimum digit and maximum digit can not be the same or maximum digit can not be smaller. Please enter another digit: ");
 } else {
 flag = 1;
 }
 }
 } flag = 0;

if( d_max - d_min + 1 < code_l && duplicate == 0) {
printf("It is impossible to generate an %d-digit code without duplicates when the minimum digit is %d and the maximum digit is %d. Please re-enter the limits and the desired length.\n", code_l ,d_min,d_max );
}else{
break;
}
}flag = 0;

printf("Please enter the maximum number of attempts: ");
  while( scanf("%d", &max_att) != 1 || max_att <= 0) {
while( getchar() != '\n');
printf("Invalid input. Please enter only positive integer: ");

}

printf("Please enter the point for correct digit in correct place: ");
  while( scanf("%d", &correct) != 1 || correct <= 0) {
while( getchar() != '\n');
printf("Invalid input. Please enter only positive integer: ");

}

printf("Please enter the point for correct digit in wrong place: ");
  while( scanf("%d", &misplaced) != 1 || misplaced <= 0) {
while( getchar() != '\n');
printf("Invalid input. Please enter only positive integer: ");

}

printf("Please enter the point for penalty for wrong digit: ");
  while( scanf("%d", &wrong) != 1 || wrong <= 0) {
while( getchar() != '\n');
printf("Invalid input. Please enter only positive integer: ");

}




rules = fopen("vault_config.txt","w");

fprintf(rules,"CODE_LENGTH=%d\nDIGIT_MIN=%d\nDIGIT_MAX=%d\nMAX_ATTEMPTS=%d\nALLOW_DUPLICATES=%d\nPOINTS_CORRECT=%d\nPOINTS_MISPLACED=%d\nPENALTY_WRONG=%d",code_l, d_min, d_max, max_att, duplicate, correct, misplaced, wrong);

fclose(rules);

break;



case 'P':

rules = fopen("vault_config.txt","r");

fscanf(rules,"CODE_LENGTH=%d\nDIGIT_MIN=%d\nDIGIT_MAX=%d\nMAX_ATTEMPTS=%d\nALLOW_DUPLICATES=%d\nPOINTS_CORRECT=%d\nPOINTS_MISPLACED=%d\nPENALTY_WRONG=%d",&code_l,&d_min,&d_max,&max_att,&duplicate,&correct, &misplaced, &wrong);

fclose(rules);


code = generate_code();

FILE* secret = fopen("vault_code.txt","w");

for(i=0; i<code_l;i++) {
fprintf(secret,"%d",code[i]);
}
fclose(secret);



FILE *log = fopen("game_log.txt","w");
time_t now = time(NULL);
struct tm *tm_info = localtime(&now);
fprintf(log, "--- Vault Codebreaker Game Log ---\n Game Date: [%04d-%02d-%02d %02d:%02d:%02d] \nSecret Code: ",
tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);


for(i=0; i<code_l;i++) {
fprintf(log,"%d",code[i]);
}

fprintf(log,"\nCode Length: %d\nDigit Range: %d-%d \nDuplicates Allowed: %d \nMax Attempts: %d\n\n",code_l, d_min, d_max, duplicate, max_att);

for(i=0; i<max_att;i++) {
counter = 0;
guess = get_guess();

fprintf(log,"Attempt %d: ",i+1);
for(k=0; k<code_l;k++) {
fprintf(log,"%d",guess[k]);
}
fprintf(log," => Feedback: ");


for(k=0; k<code_l;k++) {

if ( guess[k] == code[k] ) {
printf("C");
score = score + correct;
} else {

place = 0;
for(t=0; t<code_l;t++) {
if( guess[k] == code[t] ) {
place = 1;
break;
}

}

if(place) {
printf("M");
score = score + misplaced;
} else {
printf("W");
score = score - wrong;
}
}

}
printf("\n");

fprintf(log," Score: %d\n", score);


for(k=0;k<code_l;k++) {
if(code[k] == guess[k]) {
counter++;
}
}

if(counter == code_l) {
break;
}


}

fprintf(log,"\nFinal Score: %d\n", score);
printf("Final Score: %d\n", score);

if(score >= 90) {
fprintf(log,"Rank: Code Master\n");
printf("Rank: Code Master\n");
}

if(score >= 70 && score <= 89) {
fprintf(log,"Rank: Cipher Hunter\n");
printf("Rank: Cipher Hunter\n");
}

if(score >= 50 && score <= 69) {
fprintf(log,"Rank: Number Sleuth\n");
printf("Rank: Number Sleuth\n");
}

if(score >= 30 && score <= 49) {
fprintf(log,"Rank: Code Master\n");
printf("Rank: Code Master\n");
}

if(score >= 10 && score <= 29) {
fprintf(log,"Rank: Code Master\n");
printf("Rank: Code Master\n");
}

if(score < 10) {
fprintf(log,"Rank: Code Potato\n");
printf("Rank: Code Potato\n");
}

fprintf(log,"-----------------------------------");

fclose(log);

free(guess);
free(code);

break;

default:
printf("Invalid input.\n");

}


return 0;

}

