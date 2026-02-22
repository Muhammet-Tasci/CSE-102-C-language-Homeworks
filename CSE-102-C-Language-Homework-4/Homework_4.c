#include <stdio.h>
#include <math.h>

void enter_parameters() {

double initial_v;
double gravity;
double initial_h;

printf("Enter initial velocity (m/s): ");

while(1) {

if ( scanf("%lf", &initial_v) == 1  && initial_v > 0 ) {
break;
}

while( getchar() != '\n');
printf("Invalid input. Please enter positive velocity: ");

}



printf("Enter gravity (m/s², default 9.8): ");

while(1) {

if ( scanf("%lf", &gravity) == 1  && gravity > 0 ) {
break;
}

while( getchar() != '\n');
printf("Invalid input. Please enter positive gravity: ");

}


printf("Enter launch height (m): ");

while(1) {

if ( scanf("%lf", &initial_h) == 1  && initial_h >= 0 ) {
break;
}

while( getchar() != '\n');
printf("Invalid input. Please enter positive or zero height: ");

}


FILE *data = fopen("rocket_data.txt", "w");

fprintf(data,"v0 = %lf, g = %lf, h0 = %lf", initial_v, gravity, initial_h);

fclose(data);

printf("Rocket parameters saved to rocket_data.txt!\n");


}




double max_h(double h0, double V0, double g ) {

return ( (V0*V0) / (2*g) ) + h0;

}

double flight(double h0, double V0, double g ) {

return (V0 + sqrt( (V0*V0) + 2*g*h0 ) ) / g;

}


void simulate() {

double v0;
double h0;
double g;
double hmax;
double totalflight;
double y_increase;
double x_increase;
double x_miniincrease;
double x1;
double x2;
double temp;
double space1;
double space2;
double x0;
double space0;


FILE *data = fopen("rocket_data.txt", "r");

if ( data == NULL ) {

printf("Rocket information have not been received yet. Please enter the information first.\n");

} else {

fscanf(data,"v0 = %lf, g = %lf, h0 = %lf", &v0, &g, &h0);
fclose(data);

printf("Reading rocket parameters from file...\nEquation: h(t) = %.1lf * t^2 + %.1lf * t + %.1lf\nSimulating trajectory...\n\n",(g/-2), v0, h0 );

hmax = max_h(h0,v0,g);

totalflight = flight(h0,v0,g);

y_increase = hmax / 10;
x_increase = totalflight / 10;
x_miniincrease = totalflight / 80;


temp = hmax;
FILE *graph = fopen("trajectory.txt","w");

for( int i = 0; i < 10; i++) {
 


fprintf(graph,"%6.1lf |",temp);
printf("%6.1lf |",temp);

      
      
      
         
x1 = ( -v0 - sqrt( (v0*v0) - 4*(-(g/2) )*(h0-temp) ) ) / (2*-(g/2) );
x2 = ( -v0 + sqrt( (v0*v0) - 4*(-(g/2) )*(h0-temp) ) ) / (2*-(g/2) );


space1 = x1 / x_miniincrease;
space2 = x2 / x_miniincrease;


if(  ((int)space1 + 1 ) - space1 > space1 - (int)space1 ) {

space1 = (int)space1;
}else {
space1 = (int)space1 + 1;
}


if(  ((int)space2 + 1 ) - space2 > space2 - (int)space2 ) {

space2 = (int)space2;
}else {
space2 = (int)space2 +1;
}



if (h0 > temp ) {

if( space1 > space2) {

for(int i = 1; i < space1; i++) {
fprintf(graph," ");
printf(" ");

}
fprintf(graph,"#");
printf("#");



}else {


for(int i = 1; i < space2; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#");
printf("#");

}

} else {

if( space1 > space2) {

for(int i = 1; i < space2; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#");
printf("#");

for(int i = 1; i < space1 - space2; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#");
printf("#");


}else {


for(int i = 1; i < space1; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#");
printf("#");

for(int i = 1; i < space2 - space1; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#");
printf("#");

}

}





 
 if( h0 < temp && (temp - y_increase) < h0) {
 
 x0 = ( -v0 - v0  ) / (2*-(g/2) );
space0 = x0 / x_miniincrease;

if(  ((int)space0 + 1 ) - space0 > space0 - (int)space0 ) {

space0 = (int)space0;
} else {
space0 = (int)space0 + 1;
}

fprintf(graph,"\n       #");
printf("\n       #");

for(int i = 1; i < space0; i++) {
fprintf(graph," ");
printf(" ");
}
fprintf(graph,"#\n");
printf("#\n");

temp = temp - y_increase;

} else {


fprintf(graph,"\n\n");
printf("\n\n");


temp = temp - y_increase;

}



}

if( h0 == 0) {

fprintf(graph,"     0 #");
printf("     0 #");

} else {
fprintf(graph,"     0 |");
printf("     0 |");

}


for(int i = 0; i < 9; i++) {
fprintf(graph," - - - |");
printf(" - - - |");
}
fprintf(graph," - - - #\n");
printf(" - - - #\n");



fprintf(graph,"         ");
printf("         ");

double k = 0;
for(int i = 0; i < 11; i++ ) {
fprintf(graph,"%.1lf     ", k);
printf("%.1lf     ", k);


k = k + x_increase;

}

fclose(graph);

}

}


int main () {

int choice;
double h_max;
double total_flight;
double h0;
double v0;
double g;
int flag = 0;


while(1) {

printf("----------------------------------------\n1. Enter launch parameters\n2. Simulate rocket trajectory\n3. Save trajectory data\n4. Exit\nChoice: ");
while( scanf("%d", &choice) != 1 ) {

while( getchar() != '\n');
printf("Invalid input. Please select only from the menu options.\n");

}

switch(choice) {

case 1:
enter_parameters();
break;

case 2:
simulate();
printf("\n");
break;

case 3:

FILE *rocket = fopen("rocket_data.txt","r");

if ( rocket == NULL ) {

printf("Rocket information have not been received yet. Please enter the information first.\n");
break;

} else {
printf("Saving trajectory data...\n");

fscanf(rocket,"v0 = %lf, g = %lf, h0 = %lf", &v0, &g, &h0);

h_max = max_h(h0, v0, g );
total_flight = flight(h0, v0, g );

printf("Maximum altitude: %.2lf meters\n", h_max);
printf("Total flight duration: %.2lf seconds\n", total_flight);
printf("Graph saved to trajectory.txt !\n");

fclose(rocket);
break;
}


case 4:
printf("Exiting the program. Byee !!\n");
flag = 1;
break;


default :
printf("Invalid input. Please select only from the menu options.\n");
break;

}

if(flag) {
break;
} 

}


return 0;

}







