#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[10];
    char class[10];
    int min_damage;
    int max_damage;
    int min_mana;
    int max_mana;
} spell;


typedef struct {
    char name[30];
    char magic_class[10];
    spell spells[3];
    int HP;
    int mana;
    int alive;
    int stats[3];

} wizard;



void duel(wizard* attacker, wizard* defender) {
    int attack_spell = rand() % 3;
    int mana = attacker->spells[attack_spell].min_mana + ( rand() % ( attacker->spells[attack_spell].max_mana - attacker->spells[attack_spell].min_mana + 1) );
    
    if(attacker->mana < mana){

        printf("%s is low on mana and meditates...\n",attacker->name);
        int rec_mana = 10 + (rand() % 11);
        attacker->mana += rec_mana;
        attacker->stats[2]++;
        printf("%s recovers %d mana. Current mana: %d\n",attacker->name, rec_mana, attacker->mana);
        printf("-------------------------------------------\n");

        duel(defender,attacker);

    }else{

        int damage = attacker->spells[attack_spell].min_damage + ( rand() % ( attacker->spells[attack_spell].max_damage - attacker->spells[attack_spell].min_damage + 1) );
        if(strcmp(attacker->spells[attack_spell].class, attacker->magic_class) == 0 ) damage += 5;

        attacker->mana -= mana;
        attacker->stats[1] += mana;
        attacker->stats[0] += damage;

        defender->HP -= damage;

        printf("%s casts %s on %s\n",attacker->name, attacker->spells[attack_spell].name, defender->name);

        if(defender->HP <= 0){
            defender->alive = 0;
            printf("Damage: %d | %s's HP: 0 | %s's Mana: %d \n",damage, defender->name, attacker->name, attacker->mana);
            printf("-------------------------------------------\n");
            printf("Winner: %s the %s Wizard !\n",attacker->name, attacker->magic_class);
            return;

        }else{
            printf("Damage: %d | %s's HP: %d | %s's Mana: %d \n",damage, defender->name, defender->HP ,attacker->name, attacker->mana);
            printf("-------------------------------------------\n");

            duel(defender,attacker);

        }
    }

}


int calculate_score(int stats[], int n) {
    int weights[] = {2, 1, -3};
    if (n == 1) {
        return stats[0] * weights[0];
    }
    return stats[n - 1] * weights[n - 1] + calculate_score(stats, n - 1);
}



int main() {

    char line[40];
    spell all_spell[15];
    int spell_count,i;
    wizard wizard1;
    wizard wizard2;
    int score1;
    int score2;

    srand(time(NULL));


    FILE*file = fopen("spellbook.txt","r");

    spell_count = 0;
    while(fgets(line, 100, file) != NULL) {
    
    int len = strlen(line);
    if(len > 0 && line[len-1] == '\n') line[len-1] = '\0';

    char *token = strtok(line, ",");
    strcpy(all_spell[spell_count].name, token);

    token = strtok(NULL, ",");
    strcpy(all_spell[spell_count].class, token);

    token = strtok(NULL, ",");
    all_spell[spell_count].min_damage = atoi(token);

    token = strtok(NULL, ",");
    all_spell[spell_count].max_damage = atoi(token);

    token = strtok(NULL, ",");
    all_spell[spell_count].min_mana = atoi(token);

    token = strtok(NULL, ",");
    all_spell[spell_count].max_mana = atoi(token);

    spell_count++;
}

    fclose(file);


    strcpy(wizard1.name,"Sir Yakup");
    strcpy(wizard2.name,"Honored One Mehmet");

    wizard1.alive = 1;
    wizard2.alive = 1;
    wizard1.HP = 100;
    wizard2.HP = 100;
    wizard1.mana = 100;
    wizard2.mana = 100;
    wizard1.stats[0] = 0;
    wizard2.stats[0] = 0;
    wizard1.stats[1] = 0;
    wizard2.stats[1] = 0;
    wizard1.stats[2] = 0;
    wizard2.stats[2] = 0;

    strcpy(wizard1.magic_class,all_spell[rand() % spell_count].class);
    strcpy(wizard2.magic_class,all_spell[rand() % spell_count].class);

    for(i=0; i<3; i++){
        wizard1.spells[i] = all_spell[rand() % spell_count];
        wizard2.spells[i] = all_spell[rand() % spell_count];
    }

    printf("Wizard Duel Begins: %s vs %s!\n\n",wizard1.name, wizard2.name);

    duel(&wizard1, &wizard2);

    score1 = calculate_score(wizard1.stats,3);
    score2 = calculate_score(wizard2.stats,3);

    printf("\nBattle Summary:\n");
    printf("%s - Damage: %d | Mana Spent: %d | Recoveries: %d | Score: %d\n",wizard1.name, wizard1.stats[0], wizard1.stats[1], wizard1.stats[2], score1);
    printf("%s - Damage: %d | Mana Spent: %d | Recoveries: %d | Score: %d\n",wizard2.name, wizard2.stats[0], wizard2.stats[1], wizard2.stats[2], score2);
    
    return 0;

}