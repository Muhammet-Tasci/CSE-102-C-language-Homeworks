#include <stdio.h>

int main () {

int counter = 4;

float Error;
float ExpectedResult;
float ExperimentalResult;
float ErrorPercentage;
float num1;
float num2;
float averageerror;
float totalerror = 0;

char operation;


printf (" Enter an operation (Example: 3+2):");
if ( scanf("%f %c %f", &num1, &operation, &num2) != 3 ) {
while (getchar() != '\n');
printf("Invalid input.\n");
counter = counter - 1;
} else {

if ( operation == '+') {
ExpectedResult = num1 + num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}


} else {


if ( operation == '-') {
ExpectedResult = num1 - num2;
ExperimentalResult = num1 * num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {


if ( operation == '*') {
ExpectedResult = num1 * num2;
ExperimentalResult = num1 + num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {

if ( operation == '/' && num2 != 0) { 
ExpectedResult = num1 / num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

}else {
printf("Invalid operation.\n");
counter = counter - 1;
}


}
}
}

}






printf (" Enter an operation (Example: 3+2):");
if ( scanf("%f %c %f", &num1, &operation, &num2) != 3 ) {
while (getchar() != '\n');
printf("Invalid input.\n");
counter = counter - 1;
} else {

if ( operation == '+') {
ExpectedResult = num1 + num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}


} else {


if ( operation == '-') {
ExpectedResult = num1 - num2;
ExperimentalResult = num1 * num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {


if ( operation == '*') {
ExpectedResult = num1 * num2;
ExperimentalResult = num1 + num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {

if ( operation == '/' && num2 != 0) { 
ExpectedResult = num1 / num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

}else {
printf("Invalid operation.\n");
counter = counter - 1;
}


}
}
}

}







printf (" Enter an operation (Example: 3+2):");
if ( scanf("%f %c %f", &num1, &operation, &num2) != 3 ) {
while (getchar() != '\n');
printf("Invalid input.\n");
counter = counter - 1;
} else {

if ( operation == '+') {
ExpectedResult = num1 + num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}


} else {


if ( operation == '-') {
ExpectedResult = num1 - num2;
ExperimentalResult = num1 * num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {


if ( operation == '*') {
ExpectedResult = num1 * num2;
ExperimentalResult = num1 + num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {

if ( operation == '/' && num2 != 0) { 
ExpectedResult = num1 / num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

}else {
printf("Invalid operation.\n");
counter = counter - 1;
}


}
}
}

}







printf (" Enter an operation (Example: 3+2):");
if ( scanf("%f %c %f", &num1, &operation, &num2) != 3 ) {
while (getchar() != '\n');
printf("Invalid input.\n");
counter = counter - 1;
} else {

if ( operation == '+') {
ExpectedResult = num1 + num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}


} else {


if ( operation == '-') {
ExpectedResult = num1 - num2;
ExperimentalResult = num1 * num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {


if ( operation == '*') {
ExpectedResult = num1 * num2;
ExperimentalResult = num1 + num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

} else {

if ( operation == '/' && num2 != 0) { 
ExpectedResult = num1 / num2;
ExperimentalResult = num1 - num2;

Error = ExpectedResult - ExperimentalResult;
if( Error < 0 ) {
Error = -1 * Error;
}

if(ExpectedResult != 0) { 
ErrorPercentage = (Error / ExpectedResult) * 100;
totalerror = totalerror + ErrorPercentage;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: %.2f%% \n", ExpectedResult, ExperimentalResult, Error, ErrorPercentage);


} else {
counter = counter - 1;

printf("Expected Result: %.2f \n\nExperimental Result: %.2f \n\nError: %.2f \n\nError Percentage: Can not be calculated. \n", ExpectedResult, ExperimentalResult, Error);


}

}else {
printf("Invalid operation.\n");
counter = counter - 1;
}


}
}
}

}


if(counter == 0) {
printf("Average Error Value can not be calculated.\n");

} else {

averageerror = totalerror / counter;
printf("Average Error Value : %.2f%% \n", averageerror);

}






return 0;

}













