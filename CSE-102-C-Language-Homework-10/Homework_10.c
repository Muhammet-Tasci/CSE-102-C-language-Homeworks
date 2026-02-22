#include <stdio.h>
#include <string.h>

int possible_answers[150][30000];
int encoded_question[30000];

typedef struct {
    int question[30000];
    int answer[30000];
    int kn_base[30000];
}hm;

hm qa[150];



void extract_char_set_and_max_word(char *char_set, int *char_set_size, int *max_word_len) {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        printf("ERROR: Could not open database.txt\n");
        return;
    }

    char line[200];
    *char_set_size = 0;
    *max_word_len = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] != 'Q' && line[0] != 'A') continue;

        char *text = &line[3]; 
        char *token = strtok(text, " \n");

        while (token != NULL) {
            int len = strlen(token);
            if (len > *max_word_len)
                *max_word_len = len;

            for (int i = 0; i < len; i++) {
                int exists = 0;
                for (int j = 0; j < *char_set_size; j++) {
                    if (char_set[j] == token[i]) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    char_set[*char_set_size] = token[i];
                    (*char_set_size)++;
                }
            }

            token = strtok(NULL, " \n");
        }
    }

    char_set[*char_set_size] = '\0'; 

    fclose(file);
}


void read_embedding(int *pairs,int *max_emb_length){
int i,j;
int emb;

    FILE *file = fopen("embedding.txt","r");

    fscanf(file,"The maximum length of a sentence embedding across all questions and answers = %d\n\n",max_emb_length);
    fscanf(file,"The dimension of the word embeddings = %*d\n\n");
    fscanf(file,"The number of question-answer pairs = %d\n\n",pairs);


    for (i = 0; i < *pairs; i++) {
        while(fgetc(file) != ' '); 
        for (j = 0; j<*max_emb_length; j++) {
            emb = fgetc(file) - '0';
            qa[i].question[j] = emb; 
        }
        fgetc(file); 


        while(fgetc(file) != ' '); 
        for (j = 0; j<*max_emb_length; j++) {
            emb = fgetc(file) - '0';
            qa[i].answer[j] = emb; 
        }
        fgetc(file); 

        while(fgetc(file) != '\n'); 

    }


}


void make_knowledge_base(int pairs, int line_emb_len) {
int i,j;
    for(i=0;i<pairs;i++) {
        for(j=0;j<line_emb_len;j++){
            qa[i].kn_base[j] = qa[i].question[j] ^ qa[i].answer[j];
        }
    }
}



void encode_user_question(char *new_question, int *encoded_ques, int max_word_length, int char_set_len, char *char_set, int max_emb_len) {
    char temp[100];
    strcpy(temp, new_question);

    char *part = strtok(temp, " ");
    int emb_x = 0;
    int len, p, c, d;

    while (part != NULL) {
        len = strlen(part);
   
        for (p = 0; p < (max_word_length - len) * char_set_len; p++) {
            encoded_ques[emb_x++] = 0;
        }
    
        for (c = 0; c < len; c++) {
            for (d = 0; d < char_set_len; d++) {
                encoded_ques[emb_x++] = (char_set[d] == part[c]);
            }
        }

        
        for (d = 0; d < char_set_len; d++) {
            encoded_ques[emb_x++] = (char_set[d] == ' ');
        }

        part = strtok(NULL, " ");
    }

    emb_x = emb_x - char_set_len;
   
    int shift = max_emb_len - emb_x;
    for (int i = emb_x - 1; i >= 0; i--) {
        encoded_ques[i + shift] = encoded_ques[i];
    }

    
    for (int i = 0; i < shift; i++) {
        encoded_ques[i] = 0;
    }

    
    encoded_ques[max_emb_len] = -1;
}

void decode_print(int* selected,char *char_set,int char_set_size, int max_emb_len){
int i,m,allZero;
char decoded[150];
int temp = 0;

for(i=0; i < max_emb_len; i+= char_set_size){

    allZero = 1;
    for(m=0;m<char_set_size;m++){
        if(selected[i + m] == 1){
            allZero = 0;
            decoded[temp++] = char_set[m];
            break;
        }
    }

    if(allZero && temp != 0 && decoded[temp-1] != ' '){
        decoded[temp++] = ' ';
    }
}

if (temp > 0 && decoded[temp - 1] == ' ') {
        temp--;
    }
decoded[temp] = '\0';

printf("%s\n",decoded);

}


void query(int *encoded_ques,int pairs, int max_emb_len, char *char_set, int char_set_size) {
int i,c,diff;
double match_score;

for(i=0;i<pairs;i++) {

        for(c=0;c<max_emb_len;c++) {
            possible_answers[i][c] = qa[i].kn_base[c] ^ encoded_ques[c];

        }

        diff = 0;
        for (int c = 0; c < max_emb_len; c++) {
        if (possible_answers[i][c] != qa[i].answer[c]) {
            diff++;
        }
    }

    match_score = 1 - ((double)diff / max_emb_len);

    if(match_score > 0.8) decode_print(qa[i].answer,char_set,char_set_size,max_emb_len);
        
}

}


int main() {

char char_set[150];
int char_set_size = 0;
int max_world_len = 0;
int pairs;
int max_emb_len;
char new_question[150];
int k = 0;
int i;

extract_char_set_and_max_word(char_set,&char_set_size,&max_world_len);
read_embedding(&pairs,&max_emb_len);

printf("Please enter the question: ");
fgets(new_question,sizeof(new_question),stdin);

while(new_question[k] != '\n') k++;
new_question[k] = '\0';

encode_user_question(new_question,encoded_question,max_world_len,char_set_size,char_set,max_emb_len);
query(encoded_question,pairs,max_emb_len,char_set,char_set_size);

return 0;

}