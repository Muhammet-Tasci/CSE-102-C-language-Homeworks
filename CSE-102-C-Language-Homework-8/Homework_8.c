#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


 char op [3];
 int top = -1;

void push(char ch) {
    if( top < 2 ) {
    top++;
    op[top] = ch;
    }
    else { 
        return;
    }
}

void pop() {
    if(top >= 0) {
        top--;
    }else{
        return;
    }
}

typedef enum {
     rgb, bgr, gray} Color;




     void make_file() {
        int i;
        int k;

        int chunk_numbers[] = {3,6,9};
        int line_numbers[] = {20,50,80};

        int chunk = rand() % 3;
        int line = rand() % 3;

        FILE* file = fopen("input.txt","w");

        for(i=0;i<chunk_numbers[chunk];i++) {
            fprintf(file,"%d",1 + rand() % 250);
            if(i != chunk_numbers[chunk]-1) {
                fprintf(file,",");

            }
        }
        fprintf(file,"\n");

    for(k=0;k<3;k++) {

        for(i=0;i<line_numbers[line];i++) {
            fprintf(file,"%d",1 + rand() % 250);
            if(i != line_numbers[line]-1) {
                fprintf(file,",");
            }
        }
        fprintf(file,"\n");

    }

    fclose(file);

     }

int max_operation(int* chunk, int* corresponding_chunk_part, int chunk_size) {
    int max = 0;
    int i;

    for(i=0;i<chunk_size;i++){
        if(chunk[i] * corresponding_chunk_part[i] > max) {
            max = chunk[i] * corresponding_chunk_part[i];
        }
    }

    return max;

}


int avg_operation(int* chunk, int* corresponding_chunk_part, int chunk_size) {
    int i;
    int avg = 0;

    for(i=0;i<chunk_size;i++) {
        avg += chunk[i] * corresponding_chunk_part[i];
    }

    return avg / chunk_size;
}


void print_output_file(int* chunk, int* line2, int* line3,int* line4 ,int chunk_size, int line_size, Color color) {
int i;
int k;
int temp_head,head = 0;
int (*operation)(int*, int*, int);
int result_num = line_size - chunk_size + 1;

int* part_line2 = (int*)malloc(chunk_size * sizeof(int));
int* part_line3 = (int*)malloc(chunk_size * sizeof(int));
int* part_line4 = (int*)malloc(chunk_size * sizeof(int));

int* result2 = (int*)malloc((result_num) * sizeof(int));
int* result3 = (int*)malloc((result_num) * sizeof(int));
int* result4 = (int*)malloc((result_num) * sizeof(int));

if (op[top] == 'a') {
    operation =  avg_operation;
}else{
    operation = max_operation;
}
pop();

for(i=0;i<result_num;i++) {

    temp_head = head;
    for(k=0;k<chunk_size;k++){
       part_line2[k] = line2[temp_head];
       temp_head++;
    }

    result2[i] = operation(chunk,part_line2,chunk_size);
    
    head++;
}
head = 0;


if (op[top] == 'a') {
    operation =  avg_operation;
}else{
    operation = max_operation;
}
pop();

for(i=0;i<result_num;i++) {

    temp_head = head;
    for(k=0;k<chunk_size;k++){
       part_line3[k] = line3[temp_head];
       temp_head++;
    }

    result3[i] = operation(chunk,part_line3,chunk_size);
    
    head++;
}
head = 0;


if (op[top] == 'a') {
    operation =  avg_operation;
}else{
    operation = max_operation;
}
pop();

for(i=0;i<result_num;i++) {

    temp_head = head;
    for(k=0;k<chunk_size;k++){
       part_line4[k] = line4[temp_head];
       temp_head++;
    }

    result4[i] = operation(chunk,part_line4,chunk_size);
    
    head++;
}


FILE* file = fopen("output.txt","w");

switch(color) {

    case rgb:
    for(i=0;i<result_num;i++) {
        fprintf(file,"[%d, %d, %d]", result2[i], result3[i], result4[i]);

        if(i != result_num - 1 ) fprintf(file,", ");

    }
    break;

    case bgr:
    for(i=0;i<result_num;i++) {
        fprintf(file,"[%d, %d, %d]", result4[i], result3[i], result2[i]);

        if(i != result_num - 1) fprintf(file,", ");
    }
    break;



    case gray:

    fprintf(file,"[");
    for(i=0;i<result_num;i++) {
        fprintf(file,"%d", result2[i]);

        if(i != result_num - 1 ) fprintf(file,", ");
    }
    fprintf(file,"]\n");

    fprintf(file,"[");
    for(i=0;i<result_num;i++) {
        fprintf(file,"%d", result3[i]);

        if(i != result_num - 1 ) fprintf(file,", ");
    }
    fprintf(file,"]\n");

    fprintf(file,"[");
    for(i=0;i<result_num;i++) {
        fprintf(file,"%d", result4[i]);

        if(i != result_num - 1 ) fprintf(file,", ");
    }
    fprintf(file,"]\n");

    break;

}


fclose(file);

free(part_line2);
free(part_line3);
free(part_line4);

free(result2);
free(result3);
free(result4);

}



int string_to_int(char* str) {
    int result = 0;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}




int main() {

    srand(time(NULL));

    char operation[10];
    char output[10];
    int flag = 1;
    Color color;
    int i = 0;
    int k = 0;
    int chunk_size;
    int line_size;

    char line[80];
    int chunk[9];
    int line2[80];
    int line3[80];
    int line4[80];

    FILE* source = fopen("input.txt","r");

if(source == NULL) {
    make_file();
    source = fopen("input.txt","r");
}

   
fgets(line,80,source);

char *part = strtok(line,",\n");
i= 0;
while (part != NULL) {
    chunk[i] = string_to_int(part);
   part = strtok(NULL, ",\n");
   i++;
}
chunk_size = i;


fgets(line,80,source);

part = strtok(line,",\n");
i= 0;
while (part != NULL) {
    line2[i] = string_to_int(part);
   part = strtok(NULL, ",\n");
   i++;
}
line_size = i;

fgets(line,80,source);

part = strtok(line,",\n");
i= 0;
while (part != NULL) {
    line3[i] = string_to_int(part);
   part = strtok(NULL, ",\n");
   i++;
}

fgets(line,80,source);

part = strtok(line,",\n");
i= 0;
while (part != NULL) {
    line4[i] = string_to_int(part);
   part = strtok(NULL, ",\n");
   i++;
}

fclose(source);

    printf("Please enter first operation(avg or max): ");

    do{
    flag = 1;
    fgets(operation,10,stdin);

    if(strcmp(operation,"max\n") == 0 ) {
        push('m');
    }else {
        if(strcmp(operation,"avg\n") == 0) {
            push('a');
        }else{
            while(getchar() != '\n');
            printf("Please enter only avg or max: ");
            flag = 0;
        }
        


    }
    }while(!flag);


    printf("Please enter second operation (avg or max): ");

    do{
    flag = 1;
    fgets(operation,10,stdin);

    if(strcmp(operation,"max\n") == 0 ) {
        push('m');
    }else {
        if(strcmp(operation,"avg\n") == 0) {
            push('a');
        }else{
            while(getchar() != '\n');
            printf("Please enter only avg or max: ");
            flag = 0;
        }
        


    }
    }while(!flag);


    printf("Please enter third operation (avg or max): ");

    do{
    flag = 1;
    fgets(operation,10,stdin);

    if(strcmp(operation,"max\n") == 0 ) {
        push('m');
    }else {
        if(strcmp(operation,"avg\n") == 0) {
            push('a');
        }else{
            while(getchar() != '\n');
            printf("Please enter only avg or max: ");
            flag = 0;
        }
        


    }
    }while(!flag);

    printf("Please enter one of output types(rgb /bgr /gray): ");


    do{
    flag = 1;
    fgets(output,10,stdin);

    if(strcmp(output,"rgb\n") == 0) {
    color = rgb;
    }else{
        if(strcmp(output,"bgr\n") == 0) {
            color = bgr;
        }else{
            if(strcmp(output,"gray\n") == 0) {
                color = gray;
            }else{
                while(getchar() != '\n');
                printf("Please enter only rgb or bgr or gray: ");
                flag = 0;
            }
        }
    }

}while(!flag);


print_output_file(chunk,line2,line3,line4,chunk_size,line_size,color);


return 0;


}


