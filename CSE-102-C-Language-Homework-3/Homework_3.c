#include <stdio.h>
#include <stdlib.h>

void update_balance(double new_balance) {

FILE *account = fopen("account.txt","w");
if (account == NULL) {
        printf("Error: Cannot open account file for writing!\n");
        exit(1);
    }
fprintf(account,"%.2lf TRY", new_balance);

fclose(account);

}


double get_balance() {

double b;
FILE *account = fopen("account.txt","r");

fscanf(account,"%lf TRY",&b);
fclose(account);
return b;
}




void check_balance() {

double balance;

balance = get_balance();
printf("Current balance: %.2f TRY\n", balance);

}




void deposit_money() {

double balance;
double deposit;

balance = get_balance();
printf("Enter amount to deposit: ");
scanf("%lf",&deposit);

if(deposit <= 0) {
printf("Negative or zero amount cannot be deposited.\n");
} else {
balance = balance + deposit;

update_balance(balance);

printf("Deposit successful! New balance: %.2lf TRY\n", balance);

}
}


void withdraw_money() {

double balance;
double withdraw;

balance = get_balance();
printf("Enter amount to withdraw: ");
scanf("%lf",&withdraw);

if(withdraw <= 0) {
printf("Negative or zero amount cannot be withdraw.\n");
} else {
if( withdraw > balance) {
printf("Insufficient funds! Your balance is only %.2lf TRY\n", balance);
} else {

balance = balance - withdraw;

update_balance(balance);

printf("Withdraw successful! New balance: %.2lf TRY\n", balance);

}
}

}








void menu() {

printf("----- Virtual ATM -----\n1. Check Balance \n2. Deposit Money\n3. Withdraw Money\n4. Exit\n");
}


int main() {

int option;


FILE *account = fopen("account.txt","r");

if( account == NULL) {

update_balance(100);

} else {
fclose(account);
}

menu();

printf("Choose an option: ");
scanf("%d", &option);


switch(option) {

case 1: 
check_balance();
break;


case 2:
deposit_money();
break;


case 3:
withdraw_money();
break;

case 4:
printf("You are exiting. Byee !!!\n");
break;

default:
printf("You enter the invalid option.\n");
break;

}

return 0;

}

