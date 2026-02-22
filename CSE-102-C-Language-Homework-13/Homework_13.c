#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Job types in the company */
typedef enum {
    BACKEND_DEVELOPER,
    FRONTEND_DEVELOPER,
    FULLSTACK_DEVELOPER,
    MOBILE_DEVELOPER,
    EMBEDDED_SOFTWARE_ENGINEER,
    GAME_DEVELOPER,
    DEVOPS_ENGINEER,
    TEST_ENGINEER
}JobType;

/* Date structure to hold day, month, and year */
typedef struct {
    int day;
    int month;
    int year;
}Date;

/* Person structure to hold worker info */
typedef struct {
    int id;  /* Unique ID start from 1*/
    char* name;  /* Name as dynamic string */
    char* mail;   /* Email as dynamic string */
    JobType job;  /* Job type enum */
    bool email_verified;  /* Email verification flag */
    Date date;  /* Date structure */
}person;


/* This function prints the data to "output.txt" */
void print_table(person *workers, int size){
    int i;
    FILE* output = fopen("output.txt","a");
    
    /* Loop all workers and print their data */
    for(i=0;i<size;i++){
        fprintf(output,"%s,%s,",workers[i].name, workers[i].mail);

         /* Print job type as string */
        switch(workers[i].job){

            case 0:
            fprintf(output,"BACKEND_DEVELOPER,");
            break;

            case 1:
            fprintf(output,"FRONTEND_DEVELOPER,");
            break;

            case 2:
            fprintf(output,"FULLSTACK_DEVELOPER,");
            break;

            case 3:
            fprintf(output,"MOBILE_DEVELOPER,");
            break;

            case 4:
            fprintf(output,"EMBEDDED_SOFTWARE_ENGINEER,");
            break;

            case 5:
            fprintf(output,"GAME_DEVELOPER,");
            break;

            case 6:
            fprintf(output,"DEVOPS_ENGINEER,");
            break;

            case 7:
            fprintf(output,"TEST_ENGINEER,");
            break;
        }

        /* Print email verification as true/false */
        if(workers[i].email_verified){
            fprintf(output,"true,");
        }else{
            fprintf(output,"false,");
        }

        /* Print date with leading zeros */
        fprintf(output,"%02d.%02d.%04d\n",workers[i].date.day, workers[i].date.month, workers[i].date.year);

    }
    fprintf(output,"----------\n");
    fclose(output);
}


/* Reads input.txt and fills workers array */
void read_input(person** workers, int* size) {
    char line[200];
    char* token;
    int i;
    *size = 0;
    FILE *input = fopen("input.txt", "r");

    *workers = NULL;

 /* Read file line by line */
    while (fgets(line, sizeof(line), input)) {
         /* Increase array size */
        *workers = realloc(*workers, (*size + 1) * sizeof(person));
        person* p = &(*workers)[*size];
        p->id = *size + 1;

         /* Parse CSV tokens */
        token = strtok(line, ",\n");
        p->name = (char*)malloc((strlen(token) + 1 ) * sizeof(char) );
        strcpy(p->name, token); 

        token = strtok(NULL, ",\n");
        p->mail = (char*)malloc((strlen(token) + 1 ) * sizeof(char) );
        strcpy(p->mail, token);

        token = strtok(NULL, ",\n");
        p->job = atoi(token);

        token = strtok(NULL, ",\n");
        p->email_verified = atoi(token);

        /* Parse date string day.month.year */
        token = strtok(NULL, ",\n");
        p->date.day = atoi(strtok(token, "."));
        p->date.month = atoi(strtok(NULL, "."));
        p->date.year = atoi(strtok(NULL, "."));

        (*size)++;
    }

    fclose(input);
}




/* Insert new person from a line command */
void insert(person** workers, int* size, char* line) {
int m,k,i = 0;
int counter = 0;
char temp[15];

/* Increase array size for new person */
(*workers) = (person*)realloc(*workers, (*size + 1) * sizeof(person));

    (*workers)[*size].id = *size + 1;

             /* Find '(' character where data starts */
            while(line[i] != '(')i++;
             /* Count name length between quotes */
            for(k=i+1; line[k] != ',';k++)counter++;

             /* If empty name */
            if(counter == 0){
                (*workers)[*size].name = NULL;
            }else{
                /* Allocate memory for name, exclude quotes */
                (*workers)[*size].name = (char*)malloc((counter - 2 + 1)* sizeof(char)); /* -2 for " " and +1 for \0 */
                i = i + 2; /* for skip first " */
                for(m=0;m<counter-2;m++){
                    (*workers)[*size].name[m] = line[i];
                    i++;
                }
                (*workers)[*size].name[counter-2] = '\0';
            }


            /* Count mail length */
            counter = 0;
            for(i=k+1; line[i] != ',';i++)counter++;
            if(counter == 0){
                (*workers)[*size].mail = NULL;
            }else{
                /* Allocate mail excluding quotes */
                (*workers)[*size].mail = (char*)malloc((counter - 2 + 1)* sizeof(char));/* -2 for " " and +1 for \0 */
                k = k + 2;/* for skip first " */
                for(m=0;m<counter-2;m++){
                    (*workers)[*size].mail[m] = line[k];
                    k++;
                }
                (*workers)[*size].mail[counter-2] = '\0';

            }

            /* Parse job as int */
            for(i=i+1, m=0 ; line[i] != ',';i++,m++)temp[m] = line[i]; 
            temp[m] = '\0';
            (*workers)[*size].job = atoi(temp);

            /* Parse email_verified as int */
            for(i=i+1, m=0 ; line[i] != ',';i++,m++)temp[m] = line[i]; 
            temp[m] = '\0';
            (*workers)[*size].email_verified = atoi(temp);

            /* Parse date if exists */
            if(line[i+1] != ')'){
                /* Copy date string between quotes */
                for(i=i+2, m=0; line[i] != ')'; i++, m++)temp[m] = line[i]; 
                temp[m-1] = '\0'; /* Remove last quote */
                /* Split date string by '.' and convert */
                (*workers)[*size].date.day = atoi(strtok(temp,"."));
                (*workers)[*size].date.month = atoi(strtok(NULL,"."));   
                (*workers)[*size].date.year = atoi(strtok(NULL,"."));


            }else{
                /* No date, set to 0 */
                (*workers)[*size].date.day = 0;
                (*workers)[*size].date.month = 0;
                (*workers)[*size].date.year = 0;
            }

            
            
       (*size)++;     /* Increase size */
}




/* Delete person by id */
void delete_person(person** arr, int* size, int id) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if ((*arr)[i].id == id) {
            found = 1;

            /* Free current person's memory and shift all next persons left */
            for (int j = i; j < *size - 1; j++) {
                free((*arr)[j].name);
                free((*arr)[j].mail);

                /* Allocate and copy next person's name */
                (*arr)[j].name = (char*)malloc((strlen((*arr)[j+1].name) + 1) * sizeof(char));
                strcpy((*arr)[j].name, (*arr)[j+1].name);

                 /* Allocate and copy next person's mail */
                (*arr)[j].mail = (char*)malloc((strlen((*arr)[j+1].mail) + 1) * sizeof(char));
                strcpy((*arr)[j].mail, (*arr)[j+1].mail);

                /* Copy other fields */
                (*arr)[j].date = (*arr)[j+1].date;
                (*arr)[j].email_verified = (*arr)[j+1].email_verified;
                (*arr)[j].job = (*arr)[j+1].job;
                
            }

            /* Free last person's memory */
            free((*arr)[*size - 1].name);
            free((*arr)[*size - 1].mail);

            (*size)--; /* Decrease size */

            /* Resize array */
            *arr = (person*)realloc(*arr, (*size) * sizeof(person));
            break;
        }
    }

    if (!found) {
        printf("Error: No record with id=%d found.\n",id);
    }
}

/* Remove all people and free memory */
void truncate_table(person** workers, int* size){
int i;

if (*size != 0) {
    /* Free all allocated strings */
    for(i=0;i<*size;i++){
        free((*workers)[i].name);
        free((*workers)[i].mail);
    }

    /* Free the whole array */
    free(*workers);
    *workers = NULL;

    *size = 0; /* Reset size */
}else{
    printf("Table is empty.\n");
}

}

/* Update email and job for person by id */
void update_info(person** workers, int size, char* line){
    char temp[100];
    int new_job;
    int id;

 /* Parse UPDATE command with sscanf */
int matched = sscanf(line, "UPDATE CUSTOMER SET email=\"%[^\"]\", job_type=%d WHERE id=%d;", temp, &new_job, &id);
    if (matched != 3) {
        printf("Format error: matched = %d\n", matched);
        return;
    }
  
    /* Check valid id */
    if (id <= 0 || id > size) {
        printf("Wrong Id: %d\n", id);
        return;
    }

    /* Free old mail */
    if ((*workers)[id - 1].mail != NULL) {
        free((*workers)[id - 1].mail);
    }

    /* Allocate and copy new mail */
    (*workers)[id-1].mail = (char*)malloc( (strlen(temp) + 1) * sizeof(char));
    strcpy((*workers)[id-1].mail, temp);

    /* Update job */
    (*workers)[id-1].job = new_job;
    
}


int main() {

    char line[200];
    int size = 0;
    person* workers = NULL;

    /* Read initial data */
    read_input(&workers,&size);

    /* Print initial data */
    print_table(workers,size);

    int i,k,m,counter = 0;
    int sum;

    FILE* command = fopen("commands.txt","r");

    /* Process each command line */
    while(fgets(line,sizeof(line),command) != NULL) {

        switch(line[0]){

            case 'I': /* Insert */
            line[strlen(line) - 1] = '\0'; /* Remove newline */
            insert(&workers,&size,line);

            break;


            case 'D': /* Delete */
            i=0;
            sum = 0;
            while(line[i] != '=')i++;
            for(k=i+1;line[k] != ';'; k++){
                sum *= 10;
                sum += line[k] - '0';
            }
            delete_person(&workers,&size,sum);
            break;


            case 'U': /* Update */
            line[strlen(line) - 1] = '\0'; /* Remove newline */
            
            update_info(&workers,size,line);
            break;


            case 'T': /* Truncate */
            truncate_table(&workers,&size);
            break;

        }

        /* Print table after each command */
        print_table(workers,size);
    }

    /* Free memory if any data remains */
    if(size != 0)truncate_table(&workers,&size);
    fclose(command);

    return 0;

}
