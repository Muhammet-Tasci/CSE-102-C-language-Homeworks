#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    CSE101 ,
    CSE102 ,
    CSE103 ,
    CSE104 ,
    CSE105 
}lecture;

typedef struct {
    int id;
    char name[20];
    lecture lectures[5];
    int grades[5];
    int lec_size;
    double GPA;
}student;

typedef struct M{
    student* st;
    struct M* next;
}node;



void calculate_gpa(student* st) {

    const int lecture_credits[] = { 2, 3, 3, 4, 5};

    int i,sum = 0;
    int credits = 0;

    for(i=0;i<st->lec_size;i++){
        
        sum += (lecture_credits[st->lectures[i] ] * st->grades[i]);
        credits += lecture_credits[st->lectures[i]];

    }

    st->GPA = sum / credits;
}


void print_student(student* st){
int i;

const char* lecture_names[] = {
    "CSE101",
    "CSE102",
    "CSE103",
    "CSE104",
    "CSE105"
};
    printf("%-22s",st->name);

    for(i=0;i<st->lec_size;i++){
        printf("%s",lecture_names[st->lectures[i]]);
        if(i != st->lec_size - 1)printf(",");
    }

    printf("               ");

    for(i=0;i<st->lec_size;i++){
        printf("%d",st->grades[i]);
        if(i != st->lec_size - 1)printf(",");
    }

    printf("%15.2lf\n",st->GPA);
}


void print_id(node** head) {
node* temp;
int i;

    printf("id: ");

temp = *head;
i=0;
while(temp != NULL){
    if(i==0){
        printf("%d", temp->st->id);
    }else{
        printf(",%d",temp->st->id);
    }
    
    i = 1;

    temp = temp->next;
}
printf("\n\n");
}


void add_student(node** head, int* id_counter){
char temp[50];
char* token;
int i;
node* last = *head;

node* new_node = (node*)malloc(sizeof(node));
new_node->st = (student*)malloc(sizeof(student));
new_node->next = NULL;

while(getchar() != '\n');
printf("Enter student name: ");
fgets(temp,sizeof(temp),stdin);
temp[strlen(temp)-1] = '\0';
strcpy(new_node->st->name,temp);

printf("Enter lectures: ");
fgets(temp,sizeof(temp),stdin);
temp[strlen(temp)-1] = '\0';

token = strtok(temp,",");
i=0;
while(token != NULL){
    if(strcmp(token,"CSE101") == 0){
        new_node->st->lectures[i] = CSE101;
    }else{
        if(strcmp(token,"CSE102") == 0){
            new_node->st->lectures[i] = CSE102;
        }else{
            if(strcmp(token,"CSE103") == 0){
                new_node->st->lectures[i] = CSE103;
            }else{
                if(strcmp(token,"CSE104") == 0){
                    new_node->st->lectures[i] = CSE104;
                }else{
                    if(strcmp(token,"CSE105") == 0){
                        new_node->st->lectures[i] = CSE105;
                    }else{
                        printf("Invalid input.\n");
                        free(new_node->st);
                        free(new_node);
                        return;
                    }
                }
            }
        }
    }

    token = strtok(NULL,",");
    i++;
}
new_node->st->lec_size = i;

printf("Enter grades: ");
fgets(temp,sizeof(temp),stdin);
temp[strlen(temp)-1] = '\0';


token = strtok(temp,",");
i=0;
while(token != NULL){
new_node->st->grades[i] = atoi(token);
if(new_node->st->grades[i] < 0 || new_node->st->grades[i] > 100){
    printf("Invalid input.\n");
    free(new_node->st);
    free(new_node);
    return;
}
token = strtok(NULL,",");
i++;
}

new_node->st->id = (*id_counter)++;

calculate_gpa(new_node->st);

if(*head == NULL){
    *head = new_node;
}else{
    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}


printf("Student added. \n");
print_id(head);

}



void add_lecture(node** head){
    int found = 0;
    int id,counter,i,k;
    char line[50];
    char* token;
    lecture temp_lec[5];
    int temp_grade[5];
    node* temp = *head;

    printf("Enter id: ");
    if(scanf(" %d", &id) != 1){
        while(getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }

    while(temp != NULL){
        if(temp->st->id == id){
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(!found){
        printf("Student not found.\n");
        return;
    }


    printf("Enter lectures: ");
    while(getchar() != '\n');
    fgets(line,sizeof(line),stdin);
    line[strlen(line)-1] = '\0';

    token = strtok(line,",");

    counter = 0;
    while(token != NULL){

    if(strcmp(token,"CSE101") == 0){
        temp_lec[counter] = CSE101;
    }else{
        if(strcmp(token,"CSE102") == 0){
            temp_lec[counter] = CSE102;
        }else{
            if(strcmp(token,"CSE103") == 0){
                temp_lec[counter] = CSE103;
            }else{
                if(strcmp(token,"CSE104") == 0){
                    temp_lec[counter] = CSE104;
                }else{
                    if(strcmp(token,"CSE105") == 0){
                        temp_lec[counter] = CSE105;
                    }else{
                        printf("Invalid input.\n");
                        return;
                    }
                }
            }
        }
    }
    token = strtok(NULL, ",");
    counter++;
    }

    printf("Enter grades: ");
    fgets(line,sizeof(line),stdin);
    line[strlen(line)-1] = '\0';

    token = strtok(line,",");

    i=0;
    while(token != NULL){
        temp_grade[i] = atoi(token);
        if(temp_grade[i] < 0 || temp_grade[i] > 100){
            printf("Invalid input.\n");
            return;
        }
        token = strtok(NULL,",");
        i++;
    }



 for(i=0;i<counter;i++){
    found = 0;
    for(k=0;k < temp->st->lec_size;k++){
        if(temp->st->lectures[k] == temp_lec[i]){
            temp->st->grades[k] = temp_grade[i];
            found++;
            break;
        }
    }

    if(!found){
        temp->st->lectures[temp->st->lec_size] = temp_lec[i];
        temp->st->grades[temp->st->lec_size] = temp_grade[i];
        temp->st->lec_size++;
        calculate_gpa(temp->st);
    }

 }
                                                                                    
printf("----------------------------------------------------------------------------------\n");
printf("Name                   Lecture                      Grades             GPA\n");
printf("----------------------------------------------------------------------------------\n");
 print_student(temp->st);
 
}


void remove_lecture(node** head){
int id,i,k,counter;
int found = 0;
node* temp = *head;

lecture selected_lectures[5];
char* token;
char line[50];

    const char* lecture_names[] = {
    "CSE101",
    "CSE102",
    "CSE103",
    "CSE104",
    "CSE105"
};

    printf("Enter student id: ");
    if(scanf(" %d",&id) != 1){
        while(getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }


    while(temp != NULL){
        if(temp->st->id == id){
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(!found){
        printf("Student not found.\n");
        return;
    }


    printf("Enter lectures: ");
    while(getchar() != '\n');
    fgets(line,sizeof(line),stdin);
    line[strlen(line)-1] = '\0';

    token = strtok(line,",");

    counter = 0;
    while(token != NULL){

    if(strcmp(token,"CSE101") == 0){
        selected_lectures[counter] = CSE101;
    }else{
        if(strcmp(token,"CSE102") == 0){
            selected_lectures[counter] = CSE102;
        }else{
            if(strcmp(token,"CSE103") == 0){
                selected_lectures[counter] = CSE103;
            }else{
                if(strcmp(token,"CSE104") == 0){
                    selected_lectures[counter] = CSE104;
                }else{
                    if(strcmp(token,"CSE105") == 0){
                        selected_lectures[counter] = CSE105;
                    }else{
                        printf("Invalid input.\n");
                        return;
                    }
                }
            }
        }
    }
    token = strtok(NULL,",");
    counter++;
    }      


    for(i=0;i<counter;i++){
        found = 0;
        for(k=0;k < temp->st->lec_size;k++){
            if(temp->st->lectures[k] == selected_lectures[i]){
                
                while(k < temp->st->lec_size - 1 ){
                    temp->st->lectures[k] = temp->st->lectures[k+1];
                    temp->st->grades[k] = temp->st->grades[k+1];
                    k++;
                }
                temp->st->lec_size--;
                found++;
                break;
            }
        }

        if(!found){
            printf("%s lecture not found so did not remove.\n",lecture_names[selected_lectures[i]]);
        }

    }

    calculate_gpa(temp->st);
printf("----------------------------------------------------------------------------------\n");
printf("Name                   Lecture                      Grades             GPA\n");
printf("----------------------------------------------------------------------------------\n");
    print_student(temp->st);

}


student* search_student(node** head){
    int id, found = 0;  
    node* temp = *head;

    printf("Enter student id: ");
    if(scanf(" %d",&id) != 1){
        while(getchar() != '\n');
        printf("Invalid input.\n");
        return NULL;
    }


    while(temp != NULL){
        if(temp->st->id == id){
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(!found){
        printf("Student not found.\n");
        return NULL;
    }
        
    return temp->st;
    

}


void remove_student(node** head) {
    int id,i, found = 0;  
    node* temp = *head;
    node* back = NULL;

    printf("Enter student id: ");
    if(scanf(" %d",&id) != 1){
        while(getchar() != '\n');
        printf("Invalid input.\n");
        return;
    }


    while(temp != NULL){
        if(temp->st->id == id){
            found = 1;
            break;
        }
        back = temp;
        temp = temp->next;
    }

    if(!found){
        printf("Student not found.\n");
        return;
    }


    free(temp->st);
    if(back == NULL){
        *head = temp->next;
        free(temp);
    }else{
        back->next = temp->next;
        free(temp);
    }

    printf("Student was removed.\n");
    print_id(head);
}

void print_list(node** head){
    node* temp = *head;

printf("----------------------------------------------------------------------------------\n");
printf("Name                   Lecture                      Grades             GPA\n");
printf("----------------------------------------------------------------------------------\n");

 while(temp != NULL){
    print_student(temp->st);
    temp = temp->next;
 }

}

void free_all(node** head) {
node* temp;

    while((*head) != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp->st);
        free(temp);
    }

    printf("Freeing memory... Have a nice day!\n");
}




int main() {
    int choice;
    node* head = NULL;
    int ch,id_counter = 1;
    student* st;


    do {
        printf("Menu \n1. Add Student \n2. Remove Student \n3. Search Student \n4. Add Lecture \n5. Remove Lecture \n6. Print ID \n7. Print List \n8. Exit\n\n");
        printf("Choice: ");
            if(scanf(" %d", &choice) != 1){
                printf("Invalid input.\n");
                while(getchar() != '\n');
                continue;
            }

        
        switch(choice){
            case 1:
            add_student(&head,&id_counter);
            break;

            case 2:
            remove_student(&head);
            break;

            case 3:
            st = search_student(&head);
            if(st != NULL){
                 printf("----------------------------------------------------------------------------------\n");
                 printf("Name                   Lecture                      Grades             GPA\n");
                 printf("----------------------------------------------------------------------------------\n");
                print_student(st);
            }
            break;

            case 4:
            add_lecture(&head);
            break;

            case 5:
            remove_lecture(&head);
            break;

            case 6:
            print_id(&head);
            break;

            case 7:
            print_list(&head);
            break;

            case 8:
            free_all(&head);
            break;

            default:
            while(getchar() != '\n');
            printf("Invalid choice.\n");
            break;

        }


    }while(choice != 8);

    return 0;
}
