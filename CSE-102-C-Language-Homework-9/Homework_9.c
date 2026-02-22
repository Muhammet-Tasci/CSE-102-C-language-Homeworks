#include <stdio.h>
#include <string.h>

#define MAX_PAIRS 150
#define MAX_LINE 150
#define MAX_EMBEDDING_COLS 50000

int embedding[MAX_PAIRS * 2][MAX_EMBEDDING_COLS];

void discard_new_line(char *str) {
    int k;
    for (k = 0; str[k] != '\0' && str[k] != '\n'; k++);
    str[k] = '\0';
}

int parse_file_find_pairs(char questions[][MAX_LINE], char answers[][MAX_LINE]) {
    char line[MAX_LINE];
    int i = 0;
    FILE *file = fopen("database.txt", "r");

    if (file == NULL) {
        printf("ERROR: database.txt was not opened.\n");
        return 0;
    }

    while (fgets(line, MAX_LINE, file) != NULL && i < MAX_PAIRS) {
        strcpy(questions[i], &line[3]);
        discard_new_line(questions[i]);

        fgets(line, MAX_LINE, file);
        strcpy(answers[i], &line[3]);
        discard_new_line(answers[i]);

        fgets(line, MAX_LINE, file); 
        i++;
    }

    fclose(file);
    return i;
}

void tokanize(char *str, char *data_base, int *k, int *max_word_length, int* max_word_num) {
    char copy[MAX_LINE];
    char *token;
    int len, i;
    int word_num = 0;
    strcpy(copy, &str[3]);

    token = strtok(copy, " ");
    while (token != NULL) {
        len = strlen(token);
        if (len > *max_word_length) *max_word_length = len;

        for (i = 0; i < len; i++) {
            if (strchr(data_base, token[i]) == NULL) {
                data_base[*k] = token[i];
                (*k)++;
            }
        }
        token = strtok(NULL, " ");
        word_num++;
    }
    data_base[*k] = '\0';

    if(word_num > *max_word_num) *max_word_num = word_num;
}

void encode(char questions[][MAX_LINE], char answers[][MAX_LINE], int max_word_length, int pairs, int db_len, char *data_base) {
    char temp[MAX_LINE];
    int emb_y = 0;
    int i, qa;

    for (i = 0; i < pairs; i++) {
        for (qa = 0; qa < 2; qa++) {
            char *part;
            int emb_x = 0;
            int len, needed, p, c, d;

            if (qa == 0) {
                strcpy(temp, questions[i]);
            } else {
                strcpy(temp, answers[i]);
            }

            part = strtok(temp, " ");
            while (part != NULL) {
                len = strlen(part);
                needed = (max_word_length * db_len) + db_len;

                for (p = 0; p < (max_word_length - len) * db_len; p++) {
                    embedding[emb_y][emb_x++] = 0;
                }

                for (c = 0; c < len; c++) {
                    for (d = 0; d < db_len; d++) {
                        embedding[emb_y][emb_x++] = (data_base[d] == part[c]);
                    }
                }

                for (d = 0; d < db_len; d++) {
                    embedding[emb_y][emb_x++] = (data_base[d] == ' ');
                }

                part = strtok(NULL, " ");
            }

            emb_x = emb_x - db_len;

            embedding[emb_y][emb_x++] = -1;
            emb_y++;
        }
    }
}

void equal_line(int max_emb_len, int pairs) {
    for (int i = 0; i < pairs * 2; i++) {
        int length = 0;
        while (embedding[i][length] != -1) length++;

        int shift = max_emb_len - length;

        for (int j = length - 1; j >= 0; j--) {
            embedding[i][j + shift] = embedding[i][j];
        }

        for (int j = 0; j < shift; j++) {
            embedding[i][j] = 0;
        }

        embedding[i][max_emb_len] = -1;
    }
}


void writing_the_file(int pairs, int db_len, int max_emb_length) {
    FILE *output = fopen("embedding.txt", "w");
    int i, j, k;

    if (output == NULL) {
        printf("ERROR: embedding.txt file could not open.\n");
        return;
    }

    fprintf(output, "The maximum length of a sentence embedding across all questions and answers = %d\n\n", max_emb_length);
    fprintf(output, "The dimension of the word embeddings = %d\n\n", db_len);
    fprintf(output, "The number of question-answer pairs = %d\n\n", pairs);

    k = 0;
    for (i = 0; i < pairs; i++) {
        fprintf(output, "Question: ");
        for (j = 0; embedding[k][j] != -1; j++) {
            fprintf(output, "%d", embedding[k][j]);
        }
        fprintf(output, "\n");
        k++;

        fprintf(output, "Answer: ");
        for (j = 0; embedding[k][j] != -1; j++) {
            fprintf(output, "%d", embedding[k][j]);
        }
        fprintf(output, "\n---\n");
        k++;
    }

    fclose(output);
}

int main() {
    char questions[MAX_PAIRS][MAX_LINE];
    char answers[MAX_PAIRS][MAX_LINE];
    char data_base[150];
    int data_base_index = 0;
    int max_word_length = 0;
    int max_word_num = 0;
    int max_line_length = 0;
    int pairs, emb_dim, max_emb_len;
    FILE *data;
    char line[MAX_LINE];
    int i;

    pairs = parse_file_find_pairs(questions, answers);
    if (pairs == 0) return 1;

    data = fopen("database.txt", "r");
    if (!data) return 1;

    i = 1;
    while (fgets(line, MAX_LINE, data)) {
        if (i % 3 != 0) {
            discard_new_line(line);
            tokanize(line, data_base, &data_base_index, &max_word_length,&max_word_num);
        }
        i++;
    }
    fclose(data);

    emb_dim = data_base_index;
    max_emb_len = (emb_dim * max_word_length*max_word_num) + (max_word_num-1)*emb_dim;

    encode(questions, answers, max_word_length, pairs, emb_dim, data_base);
    equal_line(max_emb_len,pairs);
    writing_the_file(pairs, emb_dim, max_emb_len);

    return 0;
}
