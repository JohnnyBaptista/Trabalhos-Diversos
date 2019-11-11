//
// Created by ratob on 23/05/2019.
//

//Includes da biblioteca C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <dirent.h>
#include <locale.h>

//Macros
#define ERROR printf("\n  *>!ERROR!<*\n");

//Includes de outros codigos
#include "headers/player.h"             // Include do header do player
#include "headers/skill.h"              // Include do header das skills do player
#include "headers/inventory.h"          // Include do header do inventario do player
#include "headers/lore.h"               // Include do header da lore do jogo e da info dele
#include "headers/mobs.h"               // Include do header dos monstros (aka mobs)
#include "headers/mobs_name.h"          // Include do header dos nomes dos mobs
#include "headers/fightSystem.h"        // Include do header do sistema de luta
#include "headers/dungeon_tutorial.h"   // Include do header da dungeon do tutorial( esta usa uma pilha para funcionar)
#include "headers/puzzle_stack.h"       // Include do header do desafio que o jogador vai enfrentar, nele utilizamos uma pilha
#include "delay.h"                      // Include do header para delays, pausas, rngs e coisas relacionados ao <time.h>

// Variaveis globais
char name[50];      // Variavel para o nome do personagem.
int quit = 0;       // Variavel para sair do jogo.
int new_game = 0;   // Variavel para entrar no loop do jogo.
int tutorial = 0;   // Variavel para entrar no loop to tutorial.
int victory = 0;    // Variavel usada para determinar se o jogador venceu o jogo.
int quantidade[9];  // Vetor pra armazenar a quantidade de cada item em cada posicao do vetor.
int load_item_id[9];// Vetor pra armazena os IDs dos items.
int load = 0;       // Variavel para saber se o jogo foi carregado ou nao.
int count_item = 0; // Variavel pra controlar quantos nodes de item o jogador tem.

// Declaracoes de funcoes
int start();    //inicia o jogo.
int saveGame(); // Funcao para salvar o jogo
void loadGame(); // Funcao para carregar o jogo

void Intro(){
    setlocale(LC_ALL, "Portuguese");
    char line1[1000],line2[1000],line3[1000],line4[1000], line5[1000], line6[1000], line7[1000];
    strcpy(line1,"Existe uma lenda, a historia de uma criatura ja esquecida pela historia do mundo capaz de construir\n");
    strcpy(line2,"exercitos com defuntos de pessoas e coisas que ja pisaram uma vez neste mundo.\n");
    strcpy(line3,"Pouco se sabe a respeito da criatura ou de seus truques demoniacos, mas estes ainda estao a ser descobertos...\n");
    strcpy(line4,"Uma expedicao por exploradores do reino de Stormheld descobriu uma masmorra estranha e ");
    strcpy(line5,"uma equipe de elite foi enviada parar investigar, ordenada pelo proprio rei Arithus.");
    strcpy(line6,"Entretanto faz tempo que nao se ouve sinal deles...\n");
    strcpy(line7,"\n  Estranhamente, a escavacao da masmorra se da no mesmo local da vila onde voce aventureiro nasceu...\n");

    int i;
    for(i = 0; line1[i] != '\0'; i++){
        delay(1);
        printf("%c",line1[i]);
    }
    for(i = 0; line2[i] != '\0'; i++){
        delay(1);
        printf("%c",line2[i]);
    }
    for(i = 0; line3[i] != '\0'; i++){
        delay(1);
        printf("%c",line3[i]);
    }
    for(i = 0; line4[i] != '\0'; i++){
        delay(1);
        printf("%c",line4[i]);
    }
    for(i = 0; line5[i] != '\0'; i++){
        delay(1);
        printf("%c",line5[i]);
    }
    for(i = 0; line6[i] != '\0'; i++){
        delay(1);
        printf("%c",line6[i]);
    }
    for(i = 0; line7[i] != '\0'; i++){
        delay(1);
        printf("%c",line7[i]);
    }
    printf("\n");

}

void Start(){
    delay_start(1);
    printf("*");
    delay_start(1);
    printf("*");
    delay_start(1);
    printf("*");
    printf(" Iniciando");
    delay_start(1);
    printf(".");
    delay_start(1);
    printf(".");
    delay_start(1);
    printf(".");
    printf("\n");
}

void gameCredits(){
    printf("	Feito por: \n	>>Juan Cardoso da Silva\n	>>Felipe Canuto\n	>> Estrutura de Dados I\n\n");
}

void Name(char nome[15]){ // Funcao que seta o nome do jogador

    printf("Qual o seu nome aventureiro... ?\n");
    printf(">>: ");
    fflush(stdin);
    gets(nome);
}

player* getClass(char nome[15],player *Hero, int id_class){ // funcao para adicionar a classe ao jogador, depois de ler um arquivo

    if (id_class == 1){
        Hero = NewPlayer(WARRIOR, nome);
    }

    else if (id_class == 3){
        Hero = NewPlayer(MAGE, nome);
    }

    else if (id_class == 2){
        Hero = NewPlayer(RANGER, nome);
    }

    else if (id_class == 4) {
        Hero = NewPlayer(WARLOCK, nome);
    }

    else if (id_class == 5) {
        Hero = NewPlayer(PALADIN, nome);
    }

    return Hero;
}

player* chooseClass(player *Hero){ // Escolha de classe do jogador por um menu


    char c[50];
    int escolhido = 0;

    printf("\n");
    delay_start(1);
    printf("\n*************************************************\n");
    delay_start(1);
    printf("*     &         &      &       &           &    *\n");
    delay_start(1);
    printf("*        &                          &           *\n");
    delay_start(1);
    printf("*            Sussuro de Ny'hilant          &    *\n");
    delay_start(1);
    printf("*  &              &            &        &       *\n");
    delay_start(1);
    printf("*          &         &      &                &  *\n");
    delay_start(1);
    printf("*************************************************\n");
    printf("**************Escolha sua classe!****************\n");
    delay_start(1);
    printf("* |-> WARRIOR                                   *\n");
    delay_start(1);
    printf("* |-> MAGE                                      *\n");
    delay_start(1);
    printf("* |-> RANGER                                    *\n");
    delay_start(1);
    printf("* |-> WARLOCK                                   *\n");
    delay_start(1);
    printf("* |-> PALADIN                                   *\n");
    printf("*************************************************\n");
    delay_start(1);

    while(escolhido == 0){ // enquanto o jogador nao escolher, repete o loop
        printf("%s, qual classe voce pertence ?\n", name);
        printf(">>: ");
        gets(c);
        fflush(stdin);

        if (strcasecmp("WARRIOR",c) == 0){
            Hero = NewPlayer(WARRIOR, name);
            escolhido = 1;
        }

        else if (strcasecmp("MAGE",c) == 0){
            Hero = NewPlayer(MAGE, name);
            escolhido = 1;
        }

        else if (strcasecmp("RANGER",c) == 0){
            Hero = NewPlayer(RANGER, name);
            escolhido = 1;
        }

        else if (strcasecmp("WARLOCK",c) == 0) {
            Hero = NewPlayer(WARLOCK, name);
            escolhido = 1;
        }

        else if (strcasecmp("PALADIN",c) == 0) {
            Hero = NewPlayer(PALADIN, name);
            escolhido = 1;
        }

        else{
            printf("\nClasse invalida!\n");
            memset(c,0,strlen(c));
            fflush(stdin);
        }
    }

    return Hero;
}

player* Menu_No_Delay(player *Hero) { // Menu sem a intro do jogo, sem o delay da intro
    int escolhido = 0;

    char choice[50];


    while (escolhido != 1) {
        system("cls");
        gameCredits();

        printf("		[=====================================================================================]\n");
        printf("		 #################### __________________###############################################\n");
        printf("		 ###################//                |\\#############################################\n");
        printf("		 ##################||                  |\\############################################\n");
        printf("		 #################//                    |\\###########################################\n");
        printf("		 ################||                      ||##########################################\n");
        printf("		 ################||                      |\\##########################################\n");
        printf("		 ###############//                        ||#########################################\n");
        printf("		 ##############||                          ||#####################Sussurro###########\n");
        printf("		 ##############||                          |\\#######################de###############\n");
        printf("		 ##############||                           ||###################Ny'hilant###########\n");
        printf("		 ##############//                           |\\#######################################\n");
        printf("		 ##############||                            ||######################################\n");
        printf("		 ##############||                            |\\######################################\n");
        printf("		 ##############||                             ||#####################################\n");
        printf("		 ##############//                             ||#####################################\n");
        printf("		 #############||                             //######################################\n");
        printf("		 #############||                             ||######################################\n");
        printf("		[=====================================================================================]\n");
        printf("\n");
        printf("                         		[================================]\n");
        printf("                         		|         Novo jogo              |\n");
        printf("                         		|         Tutorial               |\n");
        printf("                         		|         Carregar jogo          |\n");
        printf("                         		|         Sair                   |\n");
        printf("                         		[================================]\n");

        printf("\n                         		*Digite uma das opcoes validas*\n");
        printf("                         		  >: ");
        gets(choice);
        fflush(stdin);


        if (strcasecmp("Novo jogo",choice) == 0){

            Name(name);
            new_game = 1;
            Hero = chooseClass(Hero);
            escolhido = 1;
        }

        else if (strcasecmp("Tutorial",choice) == 0){
            tutorial = 1;
            escolhido = 1;
        }

        else if (strcasecmp("Carregar jogo",choice) == 0){
            loadGame();
            escolhido = 1;
        }

        else if (strcasecmp("Sair", choice) == 0){
            escolhido = 1;
            quit = 1;
        }

        else{
            Hero = Menu_No_Delay(Hero);
            escolhido = 1;
        }

    }

    return Hero;
}

player* Menu(player *Hero){ // Menu do jogo com intro
    //Start();

    int escolhido = 0;

    char choice[50];

    system("cls");
    gameCredits();


    delay_start(1); printf("		[=====================================================================================]\n");
    delay_start(1); printf("		 #################### __________________#############################################\n");
    delay_start(1); printf("		 ###################//                  |\\###########################################\n");
    delay_start(1); printf("		 ##################||                    |\\##########################################\n");
    delay_start(1); printf("		 #################//                      |\\#########################################\n");
    delay_start(1); printf("		 ################||                        ||########################################\n");
    delay_start(1); printf("		 ################||                        |\\########################################\n");
    delay_start(1); printf("		 ###############//                          ||#######################################\n");
    delay_start(1); printf("		 ##############||                            ||###################Sussurro###########\n");
    delay_start(1); printf("		 ##############||                            |\\#####################de###############\n");
    delay_start(1); printf("		 ##############||                             ||#################Ny'hilant###########\n");
    delay_start(1); printf("		 ##############//                             |\\#####################################\n");
    delay_start(1); printf("		 ##############||                              ||####################################\n");
    delay_start(1); printf("		 ##############||                              |\\####################################\n");
    delay_start(1); printf("		 ##############||                               ||###################################\n");
    delay_start(1); printf("		 ##############//                               ||###################################\n");
    delay_start(1); printf("		 #############||                               //####################################\n");
    delay_start(1); printf("		 #############||                               ||####################################\n");
    delay_start(1); printf("		[=====================================================================================]\n");
    delay_start(1); printf("\n");
    delay_start(1); printf("                         		[================================]\n");
    delay_start(1); printf("                         		|         Novo jogo              |\n");
    delay_start(1); printf("                         		|         Tutorial               |\n");
    delay_start(1); printf("                         		|         Carregar jogo          |\n");
    delay_start(1); printf("                         		|         Sair                   |\n");
    delay_start(1); printf("                         		[================================]\n");

    delay_start(1); printf("\n                         		*Digite uma das opcoes validas*\n");
    delay_start(1); printf("                         		  >: ");
    gets(choice);
    fflush(stdin);

    while(escolhido != 1){
        if (strcasecmp("Novo jogo",choice) == 0){

            Name(name);
            new_game = 1;
            Hero = chooseClass(Hero);
            escolhido = 1;
        }

        else if (strcasecmp("Tutorial",choice) == 0){
            tutorial = 1;
            escolhido = 1;
        }

        else if (strcasecmp("Carregar jogo",choice) == 0){
            loadGame();
            escolhido = 1;
        }

        else if (strcasecmp("Sair", choice) == 0){
            quit = 1;
            escolhido = 1;
        }

        else{
            Hero = Menu_No_Delay(Hero);
            escolhido = 1;
        }

    }

    return Hero;
}

mobs* createMob(mobs *Monster , int monster_id){ // funcao para criar um monstro
    //Monster = malloc(sizeof(mobs));
    int op;
    int i;

    switch (monster_id){ // pelo id nos criamos os monstros
        case 1:
            i = RNG(11); // Essa eh uma funcao de aleatoriedade.
            Monster = NewMob(MINION, mobs_names[i]);
            break;
        case 2:
            i = RNG(11);
            Monster = NewMob(SCOURGE, mobs_names[i]);
            break;
        case 3:
            i = RNG(11);
            Monster = NewMob(PLAGUE, mobs_pagues[i]);
            break;
        case 4:
            i = RNG(11);
            Monster = NewMob(DARK, mobs_dark[i]);
            break;
        case 5:
            i = RNG(10);
            Monster = NewMob(LORD, mobs_lords[i]);
            break;
        case 6:
            i = RNG(7);
            Monster = NewMob(BOSS, mobs_bosses[i]);
            break;
        case 7:
            i = 0;
            Monster = NewMob(LASTBOSS, mobs_lastboss[i]);
            break;
        default:
            break;
    }

    return Monster;

}

int HeroStatus(player *Hero, mobs *Monster){ // Funcao pra verificar o status do jogador
    if(Hero->alive == 0) { // se o heroi tiver alive = 0 , ele perdeu o jogo
        system("cls");
        fflush(stdin);
        printf("%s matou %s...", Monster->name, Hero->name);
        printf("\nA jornada de %s chegou ao fim", Hero->name); delay(1); printf(". . .\n");
        free(Monster);
        free(Hero);
        start();
    }
}

int execute_tutorial(player *Hero, mobs *Monster,skill *pointer_skill, skill_prop *prop_skill_pointer){ // Funcao para o tutorial do jogo
    setlocale(LC_ALL, "Portuguese");

    int escolhido = 0;
    char c[50];
    inventory *inv_pointer = CreateInventory(); // Alocando memoria para inicializar o ponteiro
    // Assim, podemos passar o enderesso do ponteiro inves de ponteiro de enderesso.
    // Entao a nossa funcao vai aceitar o pointeiro para ponteiro para o itemNode.

    system("cls");
    fflush(stdin);
    delay_start(1); printf("%s", tutorial_intro);
    delay_start(1); printf("%s", tutorial_warrior);
    delay_start(1); printf("%s", tutorial_ranger);
    delay_start(1); printf("%s", tutorial_mage);
    delay_start(1); printf("%s", tutorial_warlock);
    delay_start(1); printf("%s", tutorial_paladin);

    while(escolhido == 0){
        printf(">>: ");
        gets(c);
        fflush(stdin);

        if (strcasecmp("WARRIOR",c) == 0){
            Hero = NewPlayer(WARRIOR, "Sir.Leeroy");
            escolhido = 1;
        }

        else if (strcasecmp("MAGE",c) == 0){
            Hero = NewPlayer(MAGE, "Sir.Leeroy");
            escolhido = 1;
        }

        else if (strcasecmp("RANGER",c) == 0){
            Hero = NewPlayer(RANGER, "Sir.Leeroy");
            escolhido = 1;
        }

        else if (strcasecmp("WARLOCK",c) == 0) {
            Hero = NewPlayer(WARLOCK, "Sir.Leeroy");
            escolhido = 1;
        }

        else if (strcasecmp("PALADIN",c) == 0) {
            Hero = NewPlayer(PALADIN, "Sir.Leeroy");
            escolhido = 1;
        }

        else{
            printf("\nClasse invalida!\n");
            memset(c,0,strlen(c));
            fflush(stdin);
        }
    }
    switch (Hero->classe){ // monstrando a info da classe que o jogador escolher
        case WARRIOR:
            delay_start(1); printf("%s", tutorial_warrior_1);
            delay_start(1); printf("%s", tutorial_warrior_2);
            break;
        case RANGER:
            delay_start(1); printf("%s", tutorial_ranger_1);
            delay_start(1); printf("%s", tutorial_ranger_2);
            break;
        case MAGE:
            delay_start(1); printf("%s", tutorial_mage_1);
            delay_start(1); printf("%s", tutorial_mage_2);
            break;
        case WARLOCK:
            delay_start(1); printf("%s", tutorial_warlock_1);
            delay_start(1); printf("%s", tutorial_warlock_2);
            break;
        case PALADIN:
            delay_start(1); printf("%s", tutorial_paladin_1);
            delay_start(1); printf("%s", tutorial_paladin_2);
            break;
    }

    int id_class = Hero->id_classe;
    CreateHeroSkill(id_class,pointer_skill); // criando o ponteiro das habilidades

    switch(Hero->id_classe){ // vend o id da classe para adicionar os items conforme ela
        case 1:
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            break;
        case 2:
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            break;
        case 3:
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            AddItem(1, inv_pointer);
            AddItem(1, inv_pointer);
            break;
        case 4:
            AddItem(0, inv_pointer);
            AddItem(0, inv_pointer);
            AddItem(1, inv_pointer);
            AddItem(2, inv_pointer);
            break;
        case 5:
            AddItem(1, inv_pointer);
            AddItem(2, inv_pointer);
            AddItem(2, inv_pointer);
            AddItem(2, inv_pointer);
            break;
    }
	// Info do tutorial abaixo
    printf("\n Neste tutorial, usaremos Sir.Leeroy e a classe escolhida pelo jogador para guia-lo"); delay(10); printf(".  "); delay(10); printf(".  "); delay(10); printf(".\n\n");
    pause();
    system("cls");
    
    free(Monster);
    Monster = createMob(Monster, 1);

    printf("\nPrimeiro vamos entender as opcoes do sistema de combate, o combate funciona por turnos e o %s tera que enfrentar monstros como '%s' durante a aventura\n",Hero->name,Monster->name);
    printf(" cada monstro tem seu tipo e diferentes status segundo sua hierarquia(mais fracos - mais fortes). No combate, voce tem 4 opcoes para escolher: \n\n");

    printf("1) Atacar\n");
    printf("2) Habilidades\n");
    printf("3) Inventario\n");
    printf("4) Fugir do combate\n");

    printf("\n1) Atacar\n");
    printf("Consiste em usar poder de ataque do seu personagem contra o seu oponente, e a eficacia do poder de ataque eh calculada  por:\n (ataque do heroi) - (defesa do monstro), veja o exemplo: ");
    printf("\nPoder de ataque do Sir.Leeroy: %d, defesa so monstro: %d , ataque efetivo do Sir.Leeroy : %d\n", Hero->attack, Monster->defense, (Hero->attack-Monster->defense));
    printf("Depois de realizar um ataque, o seu turno termina, dando vez ao oponente.\n");
    printf("Lembre-se que quem possuir a maior agilidade( comparando sempre de monstro pra jogador), comeca atacando.\n");
    pause();

    printf("\n2) Habilidades\n");
    printf("Uso de habilidades sao poderosas e contem dano direto ao oponente ignorando sua defesa, cada habilidade de cada classe tem seu custo e dano.\n");
    printf("Ao ganhar bastante xp para upar de nivel, seu personagem ganhara mais uma habilidade automaticamente");
    printf("Depois de escolher uma habilidade e o dano ser realizado, o seu turno termina, dando vez ao opoenente.\n");
    pause();

    printf("\n3) Inventario\n");
    printf("O inventario eh aonde a maioria das pocoes vao estar, voce pode acessa-lo para usar elas e recuperar mana, vida e dentre outros!\n");
    printf("Toda vez que voce for usar um item, a quantidade do item atual eh removida, porem ele so eh retirado do inventario\n quando as quantidades chegam a 0\n");
    printf("\n>>Atencao, somenete Magos e Warlocks podem usar pocoes de que recuperam mana!!\n");
    DisplayItems(inv_pointer);
    pause();

    printf("\n4) Fugir do combate\n");
    printf("Caso voce se sinta fraco perante um oponente ou acredita que nao consegue derrota-lo, voce pode usar essa opcao para correr do combate\n");
    printf("Atencao, fugir do combate nao eh algo direto, existe uma chance de fugir, e exite uma chance de nao fugir e se falhar sera a vez do oponente...\n");
    pause();

    printf("Agora vamos testar um combate do Sir.Leeroy contra um monstro!\n");
    pause();

    system("cls");

    free(Monster);
    Monster = createMob(Monster, 1);
    Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
    HeroStatus(Hero, Monster);

    if(Hero->alive == 0) {
        system("cls");
        printf("%s matou %s...", Monster->name, Hero->name);
        printf("\nA jornada de %s chegou ao fim", Hero->name); delay(1); printf(". . .\n");
    }


    if(Hero->alive == 1) {
        printf("\nParabens pela vitoria!, agora vamos ver como o Sir.Leeroy ficou apos o combate:\n");
        DisplayStats(Hero);
        pause();
    }


    printf("\nQuando o personagem conseguir uma determinada quantidade de xp, seu nivel vai aumentar\naumentando seus status ganhando novas habilidades");
    printf("\nO xp do %s eh [%d/%d], vamos aumenta-lo para deM ostrar como subir de nivel funciona!\n", Hero->name, Hero->xp_now, Hero->xp_total);
    pause();
    Hero->xp_now = Hero->xp_now + 25;
    if(Hero->xp_total <= Hero->xp_now){
        Hero = level_up(Hero);
        skills_add(Hero, pointer_skill);
    }

    printf("\nAo longo de sua aventura, um estranho mercador o acompanha, seus motivos sao um misterio,\nele oferece suprimentos e compra suprimentos do ");
    printf("jogador.\n Fique atento para suas aparicoes!\n");
    pause();

    system("cls");
    fflush(stdin);
    int option = 1;
    int count = 0;
    int i = 0;

    while( count < 2){ // loop while pra continuar no tamanho do *tutorial_dungeon[], a dungeon do tutorial
        system("cls");

        if(count < 0)
            count = 0;

        printf("%s", tutorial_dungeon[ stacks( option, i)]); //o stacks(option, i) retorna uma posicao das strings no lore.h tutorial_dungeon[(posicao da string)]
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *2 - Voltar na dungeon          *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                i++;
                count++;
                break;
            case 2:
                i--;
                count--;
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                break;
            case 5:
                printf("\n\nNao se pode salvar o jogo no tutorial\n\n");
                pause();
                break;
            default:
                break;
        }

    }

    system("cls");

    printf("Algo se aproxima do Leeroy...\n");
    printf("%s aparece para combate!\n", Monster->name);
    pause();
    fflush(stdin);

    free(Monster);
    Monster = createMob(Monster, 5);
    Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
    HeroStatus(Hero, Monster);

    system("cls");
    printf("Assim se conclui a historia de Sir.Leeroy, um trÃ¡gico fim nas maos de um monstro horrendo.\n");
    printf("E voce ? tera o mesmo fim de Leeroy ? ou desfrutara das vitorias em combate ? inicie o jogo para descobrir");delay(1); printf(". . .\n");
    pause();
    fflush(stdin);

    free(Monster);

    pop_stack(1);
    pop_stack(0);
    system("cls");
}

int MerchantShop(inventory *merchant_inventory, player *Hero, inventory *inv_pointer){ // Funcao para o mercardor
	// O mercador n é um "tipo" jogador nesse caso, ele apenas é uma "entidade" do qual o jogador interage para adquirir items e vender items que ele poss achar
	// inuteis.
    int opcao = 0; // opcao do tipo do item que esta vendendo
    int opcao1; // decidir se vai entrar no loop para ficar vendendo ou comprando
    int exit = 0; // para sair do loop

    while(exit != 1){
        system("cls");
        opcao = 0;
        printf("A caravana da figura misteriosa eh toda baguncada\ne cheio de items todos fora de lugar, com poeira por toda parte...\n");
        printf("\"Ola aventureiro, nao se incomode com a bangunca de minha caravana...\"");
        printf("\"Deseja comprar ou vender ?\"\n");
        printf("  1 - comprar\n");
        printf("  2 - vender\n");
        printf("  3 - sair da loja\n");
        scanf("%d", &opcao1);

        switch(opcao1){
            case 1:
                while(opcao != -1){
                    system("cls");
                    DisplayItems(merchant_inventory);
                    printf("\n\nOuro do Jogador: %dgp\n",Hero->gold);
                    printf("O que voce quer comprar ? (digite o ID do item a ser comprado ou -1 para para de comprar)\n");
                    scanf("%d", &opcao);

                    if(opcao == 0){
                        if(Hero->gold >= 10){
                            printf("\nPocao de Vida adicionado, %dgp removido.\n\n",(10));
                            Hero->gold = Hero->gold - 10;
                            AddItem(0, inv_pointer);
                            RemoveItem(merchant_inventory,0);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:10gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 1){
                        if(Hero->gold >= 10){
                            printf("\nPocao de Mana adicionado, %dgp removido.\n\n",(10));
                            Hero->gold = Hero->gold - 10;
                            AddItem(1, inv_pointer);
                            RemoveItem(merchant_inventory,1);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:10gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 2){
                        if(Hero->gold >= 20){
                            printf("\nPocao do rejuvenescimento, %dgp removido.\n\n",(20));
                            Hero->gold = Hero->gold - 20;
                            AddItem(2, inv_pointer);
                            RemoveItem(merchant_inventory,2);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:20gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 3){
                        if(Hero->gold >= 15){
                            printf("\nPocao do Berserk adicionado, %dgp removido.\n\n",(15));
                            Hero->gold = Hero->gold - 15;
                            AddItem(3, inv_pointer);
                            RemoveItem(merchant_inventory,3);
                            pause();
                        }

                        else{
                            printf("%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:15gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 4){
                        if(Hero->gold >= 15){
                            printf("\nPocao de Capacidade adicionado, %dgp removido.\n\n",(15));
                            Hero->gold = Hero->gold - 15;
                            AddItem(4, inv_pointer);
                            RemoveItem(merchant_inventory,4);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:15gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 5){
                        if(Hero->gold >= 120){
                            printf("\nPocao Grande de Vida adicionado, %dgp removido.\n\n",(120));
                            Hero->gold = Hero->gold - 120;
                            AddItem(5, inv_pointer);
                            RemoveItem(merchant_inventory,5);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:120gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 6){
                        if(Hero->gold >= 160){
                            printf("\nPocao Grande de Mana adicionado, %dgp removido.\n\n",(160));
                            Hero->gold = Hero->gold - 160;
                            AddItem(6, inv_pointer);
                            RemoveItem(merchant_inventory,6);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:160g \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 7){
                        if(Hero->gold >= 300){
                            printf("\nPocao de forca adicionado, %dgp removido.\n\n",(300));
                            Hero->gold = Hero->gold - 300;
                            AddItem(7, inv_pointer);
                            RemoveItem(merchant_inventory,7);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:300gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 8){
                        if(Hero->gold >= 200){
                            printf("\nPocao Grande do rejuvenescimento adicionado, %dgp removido.\n\n",(200));
                            Hero->gold = Hero->gold - 200;
                            AddItem(8, inv_pointer);
                            RemoveItem(merchant_inventory,8);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item:200gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else if(opcao == 9){
                        if(Hero->gold >= 500){
                            printf("\nPapiro da defesa adicionado, %dgp removido.\n\n",(500));
                            Hero->gold = Hero->gold - 500;
                            AddItem(9, inv_pointer);
                            RemoveItem(merchant_inventory,9);
                            pause();
                        }

                        else{
                            printf("\n%s nao tem ouro suficiente, ouro atual:%dgp, preco do item: 500gp \n",Hero->name,Hero->gold);
                            pause();
                        }
                    }

                    else{
                        printf("\"Gah, escolha um item que eu possua aventureiro...\"\n\n");
                        pause();
                    }
                }
                break;
            case 2:
                while(opcao != -1){
                    system("cls");
                    DisplayItems(inv_pointer);
                    printf("\n\nOuro do Jogador: %dgp\n",Hero->gold);
                    printf("O que voce quer vender ? (digite o ID do item a ser comprado ou -1 para para de vender)\n");
                    scanf("%d", &opcao);

                    if(opcao == 0){
                        printf("\n%dgp adicionado, Pocao de Vida removido.",(10 - 2));
                        Hero->gold = Hero->gold + 10 - 2;
                        RemoveItem(inv_pointer,0);
                        pause();
                    }

                    else if(opcao == 1){
                        printf("\n%dgp adicionado, Pocao de Mana removido.",(10 - 2));
                        Hero->gold = Hero->gold + 10 - 2;
                        RemoveItem(inv_pointer,1);
                        pause();
                    }

                    else if(opcao == 2){
                        printf("\n%dgp adicionado, Pocao do rejuvenescimento removido.",(20 - 7));
                        Hero->gold = Hero->gold + 20 - 7;
                        RemoveItem(inv_pointer,2);
                        pause();
                    }

                    else if(opcao == 3){
                        printf("\n%dgp adicionado, Pocao do Berserk removido do mercante.",(15 - 5));
                        Hero->gold = Hero->gold + 15 - 5;
                        RemoveItem(inv_pointer,3);
                        pause();
                    }

                    else if(opcao == 4){
                        printf("\n%dgp adicionado, Pocao de Capacidade removido do mercante.",(15 - 5));
                        Hero->gold = Hero->gold + 15 - 5;
                        RemoveItem(inv_pointer,4);
                        pause();
                    }

                    else if(opcao == 5){
                        printf("\n%dgp adicionado, Pocao Grande de Vida removido do mercante.",(120 - 50));
                        Hero->gold = Hero->gold + 120 - 50;
                        RemoveItem(inv_pointer,5);
                        pause();
                    }

                    else if(opcao == 6){
                        printf("\n%dgp adicionado, Pocao Grande de Mana removido do mercante.",(160 - 70));
                        Hero->gold = Hero->gold + 160 - 70;
                        RemoveItem(inv_pointer,6);
                        pause();
                    }

                    else if(opcao == 7){
                        printf("\n%dgp adicionado, Pocao de forca removido do mercante.",(300 - 160));
                        Hero->gold = Hero->gold + 300 - 160;
                        RemoveItem(inv_pointer,7);
                        pause();
                    }

                    else if(opcao == 8){
                        printf("\n%dgp adicionado, Pocao Grande do rejuvenescimento removido do mercante.",(200 - 100));
                        Hero->gold = Hero->gold + 200 - 100;
                        RemoveItem(inv_pointer,8);
                        pause();
                    }

                    else if(opcao == 9){
                        printf("\n%dgp adicionado, Papiro da defesa removido do mercante.",(500 - 280));
                        Hero->gold = Hero->gold + 500 - 280;
                        RemoveItem(inv_pointer,9);
                        pause();
                    }

                    else{
                        printf("\"Gah, escolha um item que eu possa comprar aventureiro...\"\n\n");
                        pause();
                    }
                }
                break;
            case 3:
                exit = 1;
                break;
            default:
                printf("\n>*Opcao invalida*<\n\n");
                pause();
                break;
        }
    }
}


int execute_dungeon(player *Hero, mobs *Monster,skill *pointer_skill, skill_prop *prop_skill_pointer) { // loop principal do jogo
    setlocale(LC_ALL, "Portuguese");
    int i; // Usado para iteracao que adiciona items ao mercador.
    int option = 0;
    int count = 0; // Contador, ele vai ser usado para iteracoes das dungeons.
    int result = 0;
    int puzzle_stacks_done = 0; // variavel para o puzzle, se ele estiver pronto n precisa fazer mais o mesmo.
    int item_rng; // Random number generator para o item;
    int hero_id_class = Hero->id_classe; // Variavel para salvar a opcao de classe;
    int sneak = 0; // Variavel para caso do stealth.
    int item_box_1 = 0;

    char choice[5];
	inventory *inv_pointer = CreateInventory(); // Alocando memoria para inicializar o ponteiro
    inventory *merchant_inventory = CreateInventory(); // Criando o ponteiro para o mercardor
    // Adicionando todos os items do jogo para o mercardor vender depois
    for(i = 0; i < 99; i++){
        AddItem(0,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(1,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(2,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(3,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(4,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(5,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(6,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(7,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(8,merchant_inventory);
    }

    for(i = 0; i < 99; i++){
        AddItem(9,merchant_inventory);
    }

    if(load == 1){ // se o load for 1 , os items sao carregados para o inventario
        int i;
        int j;
        int item;
        for(i = 0; i < count_item; i++){
            item = load_item_id[i]; // adiciona o id do item a variavel item.
            for (j = 0; j < quantidade[i]; j++) { // loop para adicionar a quantidade dos items
                AddItem(item, inv_pointer); // adicionanto os items
            }
        }
    }

    else{
        switch(hero_id_class){ // Adicionando os items conforme a classe
            case 1:// Guerreiro
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                break;
            case 2:// Vigilante
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                break;
            case 3:// Mago
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                AddItem(1, inv_pointer);
                AddItem(1, inv_pointer);
                break;
            case 4:// Bruxo
                AddItem(0, inv_pointer);
                AddItem(0, inv_pointer);
                AddItem(1, inv_pointer);
                AddItem(2, inv_pointer);
                break;
            case 5:// Paladino
                AddItem(1, inv_pointer);
                AddItem(2, inv_pointer);
                AddItem(2, inv_pointer);
                AddItem(2, inv_pointer);
                break;
            default:
                ERROR
                break;
        }
    }

    system("cls");
    delay_start(1);printf("%s", arrival); // Printando a intro da dungeon
    pause();

    system("cls");
    printf("%s\n\n",mercardor_1[0]); // Printando o encontro com o mercador
    pause();
    MerchantShop(merchant_inventory,Hero,inv_pointer); // Funcao onde vc entra na "loja" do mercardor

    while( count < 7){ // loop while pra continuar no tamanho do *dungeon[], a dungeon do jogo
        if(Hero->xp_total <= Hero->xp_now){ // verifica se o personagem vai upar de level
            Hero = level_up(Hero); // adiciona o novo ponteiro ja no proximo nivel
            skills_add(Hero, pointer_skill); // adiciona as skill conforme o level
            if(Hero->xp_now >= Hero->xp_total){ // caso ainda tenha mais xp sobrando entra no loop abaixo
                while(Hero->xp_now >= Hero->xp_total){ // enquanto xp_now >= xp_total, ganha level e adiciona habilidade
                    Hero = level_up(Hero);
                    skills_add(Hero, pointer_skill);
                }
            }
        }

        if(count < 0)
            count = 0;

        if(count == 1 && item_box_1 != 1){ // Evento 1
            system("cls");
            int op;
            printf("%s", dungeon_1_1[0]);
            printf("Deseja examinar as caixas ?\n 1 - Sim\n 2 - Nao\n\n");
            scanf("%d", &op);
            if(op == 1){
                AddItem(2, inv_pointer);
                AddItem(2, inv_pointer);
                printf("\n=> Voce encontrou: 2 de Pocao do rejuvenescimento\n\n");
                pause();
                item_box_1 = 1;
            }

            else if (op == 2){
                item_box_1 = 0;
            }

            else{
                system("cls");
            }
        }

        system("cls");
        printf("%s", dungeon_1[count]); // printando o conteudo da string dungeon_x , onde o count eh a posicao do conteudo
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *2 - Voltar na dungeon          *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                count++;
                break;
            case 2:
                count--;
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                printf("\n");
                pause();
                break;
            case 5:
                saveGame(Hero,inv_pointer);
                break;
            default:
                break;
        }

        if(count == 3){ // Evento 2
            free(Monster);
            Monster = createMob(Monster, 1);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);
        }

        if(count == 4){ // Evento 3
            system("cls");
            printf("\n ** Voce pode tentar se esconder a seguir...\n\nAgilidade necessaria: [ 5 ]\n");
            printf("Deseja passar despercebido ? Sim ou Nao\n");
            scanf("%s", choice);

            if(strcasecmp(choice, "sim") == 0){
                if(Hero->agility >= 5){
                    sneak = 1;
                    printf("\n %s conseguiu se esconder\n", Hero->name);
                    Hero->xp_now = Hero->xp_now + 10;
                    pause();
                }

                else{
                    printf("\n %s falhou na tentativa de se esconder...\n", Hero->name);
                    sneak = 0;
                    pause();
                }
            }

            else if(strcasecmp(choice, "nao") == 0){
                sneak = 0;
            }

            else{
                printf("\n >> Escreva uma opcao valida.\n");
                pause();
            }

            if(sneak != 1){ // Consequencia do Evento 3
                item_rng = RNG_GAME(2); // 0 para um tipo de drop o item e 1 para outro tipo de drop
                free(Monster); // Libera o ponteiro do monstro
                Monster = createMob(Monster, 1); // Criando o monstro
                // Entrando na luta
                Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
                HeroStatus(Hero, Monster);
                if(item_rng == 1){
                    int type_item_rng = RNG(2);
                    if(type_item_rng == 0){
                        AddItem(0, inv_pointer);
                        AddItem(0, inv_pointer);
                    }

                    else{
                        AddItem(0, inv_pointer);
                        AddItem(1, inv_pointer);
                    }
                }

                free(Monster);
                Monster = createMob(Monster, 1);

                item_rng = RNG(2);
                if(item_rng == 1){
                    int type_item_rng = RNG_GAME(2);
                    if(type_item_rng == 0){
                        AddItem(0, inv_pointer);
                        AddItem(0, inv_pointer);
                    }

                    else{
                        AddItem(0, inv_pointer);
                        AddItem(1, inv_pointer);
                    }
                }

                Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
                HeroStatus(Hero, Monster);

                free(Monster);
                Monster = createMob(Monster, 1);
                Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
                HeroStatus(Hero, Monster);
            }
        }

        if(count == 5){ // Evento 4
            free(Monster);
            Monster = createMob(Monster, 1);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 1);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 1);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 1);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);
        }

        if(count == 6 && puzzle_stacks_done == 0){ // Evento 5
            result = puzzle_stacks();
            if(result == 1){
                puzzle_stacks_done = 1;
                Hero->xp_now = Hero->xp_now + 400;
            }

            else{
                printf("%s Desiste de tentar entender o puzzle e volta a andar na masmorra", Hero->name);
                delay(1); printf(". "); delay(1); printf(". "); delay(1); printf(".\n");
                count--;
            }
        }

        if(count == 7){ // Evento 6
            item_rng = RNG_GAME(2); // 0 para um tipo de drop o item e 1 para outro tipo de drop
            free(Monster); // Libera o ponteiro do monstro
            Monster = createMob(Monster, 2); // Criando o monstro
            // Entrando na luta
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);

            if(item_rng == 1){
                int type_item_rng = RNG_GAME(2);
                if(type_item_rng == 0){
                    AddItem(0, inv_pointer);
                    AddItem(0, inv_pointer);
                }

                else{
                    AddItem(0, inv_pointer);
                    AddItem(1, inv_pointer);
                }
            }

            free(Monster);
            Monster = createMob(Monster, 3);

            item_rng = RNG_GAME(2);
            if(item_rng == 1){ // definindo o tipo de drop
                int type_item_rng = RNG_GAME(2);

                if(type_item_rng == 0){
                    AddItem(0, inv_pointer);
                    AddItem(0, inv_pointer);
                }

                else{
                    AddItem(0, inv_pointer);
                    AddItem(0, inv_pointer);
                    AddItem(1, inv_pointer);
                }
            }

            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);

            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 2);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            system("cls");
            printf("\n%dxp por ter sobrevivido a horda.\n",200);
            pause();
        }

    }

    system("cls");
    printf("%s\n\n",mercardor_1[0]);
    pause();
    MerchantShop(merchant_inventory,Hero,inv_pointer);

    count = 0;

    while( count < 3){ // loop while pra continuar no tamanho do *dungeon[], a dungeon do jogo
        system("cls");
        if(Hero->xp_total <= Hero->xp_now){
            Hero = level_up(Hero);
            skills_add(Hero, pointer_skill);
            if(Hero->xp_now >= Hero->xp_total){
                while(Hero->xp_now >= Hero->xp_total){
                    Hero = level_up(Hero);
                    skills_add(Hero, pointer_skill);
                }
            }
        }


        if(count < 0)
            count = 0;

        printf("%s", dungeon_2[count]); // printando o conteudo da string dungeon_x , onde o count eh a posicao do conteudo
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *2 - Voltar na dungeon          *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                count++;
                break;
            case 2:
                count--;
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                break;
            case 5:
                saveGame(Hero,inv_pointer);
                break;
            default:
                break;
        }

        if(count == 3){ // Evento 7
            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 2);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 2);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 3);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            system("cls");
            printf("\n%dxp por ter sobrevivido a horda.\n",600);
            printf("\n%dgp por ter sobrevivido a horda.\n",200);
            Hero->xp_now = Hero->xp_now + 900;
            Hero->gold = Hero->gold + 200;
            pause();

        }

    }

    system("cls");
    printf("%s\n\n",mercardor_1[0]);
    pause();
    MerchantShop(merchant_inventory,Hero,inv_pointer);

    count = 0;

    while( count <= 1){ // loop while pra continuar no tamanho do *dungeon[], a dungeon do jogo
        system("cls");
        if(Hero->xp_total <= Hero->xp_now){
            Hero = level_up(Hero);
            skills_add(Hero, pointer_skill);
            if(Hero->xp_now >= Hero->xp_total){
                while(Hero->xp_now >= Hero->xp_total){
                    Hero = level_up(Hero);
                    skills_add(Hero, pointer_skill);
                }
            }
        }


        if(count < 0)
            count = 0;

        printf("%s", dungeon_3[count]); // printando o conteudo da string dungeon_x , onde o count eh a posicao do conteudo
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *2 - Voltar na dungeon          *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                count++;
                break;
            case 2:
                count--;
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                break;
            case 5:
                saveGame(Hero,inv_pointer);
                break;
            default:
                break;
        }

        if(count == 1){ // Evento 8
            free(Monster);
            Monster = createMob(Monster, 4);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 4);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 5);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 5);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            Monster = createMob(Monster, 4);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);

            free(Monster);
            HeroStatus(Hero, Monster);
            free(Monster);
            Monster = createMob(Monster, 6);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);

            system("cls");
            printf("\n%dxp por ter sobrevivido a horda.",2500);
            printf("\n%dgp por ter sobrevivido a horda.",250);
            Hero->xp_now = Hero->xp_now + 900;
            Hero->gold = Hero->gold + 200;
            pause();
        }

    }

    system("cls");
    printf("%s\n\n",mercardor_1[0]);
    pause();
    MerchantShop(merchant_inventory,Hero,inv_pointer);

    count = 0;

    while( count < 1){ // loop while pra continuar no tamanho do *dungeon[], a dungeon do jogo
        system("cls");
        if(Hero->xp_total <= Hero->xp_now){
            Hero = level_up(Hero);
            skills_add(Hero, pointer_skill);
            if(Hero->xp_now >= Hero->xp_total){
                while(Hero->xp_now >= Hero->xp_total){
                    Hero = level_up(Hero);
                    skills_add(Hero, pointer_skill);
                }
            }
        }


        if(count < 0)
            count = 0;

        printf("%s", dungeon_4[count]); // printando o conteudo da string dungeon_x , onde o count eh a posicao do conteudo
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *2 - Voltar na dungeon          *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                count++;
                break;
            case 2:
                count--;
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                break;
            case 5:
                saveGame(Hero,inv_pointer);
                break;
            default:
                break;
        }

        if(count == 1){ // Evento 9
            printf("\nO colar lhe abencoa... [ 1000xp foi ganho ]\n\n");
            Hero->xp_now = Hero->xp_now + 1000;
            pause();
        }

    }

    count = 0;

    while( count <= 1){ // loop while pra continuar no tamanho do *dungeon[], a dungeon do jogo
        system("cls");
        if(Hero->xp_total <= Hero->xp_now){
            Hero = level_up(Hero);
            skills_add(Hero, pointer_skill);
            if(Hero->xp_now >= Hero->xp_total){
                while(Hero->xp_now >= Hero->xp_total){
                    Hero = level_up(Hero);
                    skills_add(Hero, pointer_skill);
                }
            }
        }


        if(count < 0)
            count = 0;

        printf("%s", dungeon_5[count]); // printando o conteudo da string dungeon_x , onde o count eh a posicao do conteudo
        printf(" *1 - Avancar na dungeon         *\n");
        printf(" *3 - Mostrar status do jogador  *\n");
        printf(" *4 - Mostrar o inventario       *\n");
        printf(" *5 - Salvar Jogo                *\n");
        printf(">>: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                count++;
                break;
            case 2:
                system("cls");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n");
                printf("\n    **NAO HA ESCAPATORIA, $#!@#$$@#@ O CHAMA**\n\n");
                pause();
                break;
            case 3:
                system("cls");
                DisplayStats(Hero);
                pause();
                break;
            case 4:
                DisplayItems(inv_pointer);
                break;
            case 5:
                saveGame(Hero,inv_pointer);
                break;
            default:
                break;
        }

        if(count == 2){ // Evento 10 e final.
            free(Monster);
            Monster = createMob(Monster, 7);
            Hero = Fight(Hero, Monster , pointer_skill, prop_skill_pointer, inv_pointer);
            HeroStatus(Hero, Monster);
        }

    }

    if(Hero->xp_total <= Hero->xp_now){
        Hero = level_up(Hero);
        skills_add(Hero, pointer_skill);
        if(Hero->xp_now >= Hero->xp_total){
            while(Hero->xp_now >= Hero->xp_total){
                Hero = level_up(Hero);
                skills_add(Hero, pointer_skill);
            }
        }
    }

    pause();

    if(victory == 1){ // Final do jogo
        printf("%s\n", prologo);
        pause();
        system("ls");
        printf("%s\n", vitoria);
        printf("\nAperte qualquer tecla pra sair... ");
        getch();
    }

    free(Monster);
    pause();
}

int endsWithSuffix (const char *s, const char *suffix) { // Compra os sufixo do nome do arquivo com a o sufixo dado
    int sLength = strlen(s);
    int suffixLength = strlen(suffix);

    return (sLength >= suffixLength) &&
           (strcmp(s + (sLength-suffixLength), suffix) == 0);
}

int saveGame(player *hero, inventory *inv_pointer){
    system("cls");

    char file_name[15]; // String para o nome do arquivo
    int flag = 0; // Um variavel flag
    FILE *arquivo; // Varivavel para abrir o arquivo que esta salvo o personagem.
    inventory *aux_pointer = inv_pointer;
    
    printf("\n >>> *ATENCAO, SOMENTE ARQUIVOS TERMINADOS EM .trpg SERAO LIDOS!*");
    printf("\n\n >Digite o nome do arquivo a ser salvo:\n ");
    scanf("%s", file_name);

    arquivo = fopen(file_name,"w");

    if(arquivo == NULL){
        printf("\n>>ERRO AO SALVAR ARQUIVO\n\n");
        fclose(arquivo);
        return 0;
    }
    // Salvando os dados do jogador conforme a classe
    switch(hero->id_classe){
        case 1:
            fprintf(arquivo, "%d\n",hero->id_classe);
            fprintf(arquivo, "%s\n",hero->name);
            fprintf(arquivo, "%d\n",hero->health);
            fprintf(arquivo, "%d\n",hero->rage);
            fprintf(arquivo, "%d\n",hero->level);
            fprintf(arquivo, "%d\n",hero->gold);
            fprintf(arquivo, "%d\n",hero->xp_now);
            fprintf(arquivo, "%d\n",hero->xp_total);
            break;
        case 2:
            fprintf(arquivo, "%d\n",hero->id_classe);
            fprintf(arquivo, "%s\n",hero->name);
            fprintf(arquivo, "%d\n",hero->health);
            fprintf(arquivo, "%d\n",hero->combo);
            fprintf(arquivo, "%d\n",hero->level);
            fprintf(arquivo, "%d\n",hero->gold);
            fprintf(arquivo, "%d\n",hero->xp_now);
            fprintf(arquivo, "%d\n",hero->xp_total);
            break;
        case 3:
            fprintf(arquivo, "%d\n",hero->id_classe);
            fprintf(arquivo, "%s\n",hero->name);
            fprintf(arquivo, "%d\n",hero->health);
            fprintf(arquivo, "%d\n",hero->mana);
            fprintf(arquivo, "%d\n",hero->level);
            fprintf(arquivo, "%d\n",hero->gold);
            fprintf(arquivo, "%d\n",hero->xp_now);
            fprintf(arquivo, "%d\n",hero->xp_total);
            break;
        case 4:
            fprintf(arquivo, "%d\n",hero->id_classe);
            fprintf(arquivo, "%s\n",hero->name);
            fprintf(arquivo, "%d\n",hero->health);
            fprintf(arquivo, "%d\n",hero->mana);
            fprintf(arquivo, "%d\n",hero->level);
            fprintf(arquivo, "%d\n",hero->gold);
            fprintf(arquivo, "%d\n",hero->xp_now);
            fprintf(arquivo, "%d\n",hero->xp_total);
            break;
        case 5:
            fprintf(arquivo, "%d\n",hero->id_classe);
            fprintf(arquivo, "%s\n",hero->name);
            fprintf(arquivo, "%d\n",hero->health);
            fprintf(arquivo, "%d\n",hero->mana);
            fprintf(arquivo, "%d\n",hero->level);
            fprintf(arquivo, "%d\n",hero->gold);
            fprintf(arquivo, "%d\n",hero->xp_now);
            fprintf(arquivo, "%d\n",hero->xp_total);
            break;
        default:
            ERROR;
            break;
    }

    // Os dois loops abaixo sao para salvar os items do jogador.
    while(aux_pointer->next != NULL){
        aux_pointer = aux_pointer->next;
    }

    while(aux_pointer != NULL){
    	if(aux_pointer->current->item_id >= 0 && aux_pointer->current->item_id <= 9){
    		fprintf(arquivo, "%d %d\n", aux_pointer->current->item_id, aux_pointer->current->quantity);
		}
        aux_pointer = aux_pointer->previous;
    }

    fclose(arquivo); //fecha o arquivo
    pause();
    return 1;
}

void loadGame(){
    system("cls");

    char file_name[15];
    FILE *arquivo; // Varivavel para abrir o arquivo que esta salvo o personagem.
    DIR *dir;
    struct dirent *lsdir;
    int flag = 0;
    dir = opendir(".");

    char nome[50];      // Variavel local para o nome
    int i = 0;          // Variavel para iteracoes
    int health = 0;     // Variavel local para armazena a vida do jogador do arquivo do jogo
    int mana = 0;       // Variavel local para armazena a man do jogador do arquivo do jogo
    int rage = 0;       // Variavel local para armazena a rage do jogador do arquivo do jogo
    int combo = 0;      // Variavel local para armazena o combo do jogador do arquivo do jogo
    int id_classe;      // Variavel local para armazena a classe do jogador do arquivo do jogo
    int level = 0;      // Variavel local para armazena o level do jogador do arquivo do jogo
    int gold = 0;       // Variavel local para armazena o ouro do jogador do arquivo do jogo
    int xp_now = 0;     // Variavel local para armazena o xp atual do jogador do arquivo do jogo
    int xp_total = 0;   // Variavel local para armazena o xp local jogador do arquivo do jogo

    player *Hero = NULL;  //ponteiro para o jogador
    mobs *Monster = NULL; //ponteiro para os monstros
    skill *pointer_skill = CreatePointer();// ponteiro para habilidade do jogador
    skill_prop *prop_skill_pointer = malloc(sizeof(skill_prop)); // pointeiro para propriedades das habilidades do jogador

    // Printf de todos os arquivos nos diretorio dito.
    printf("======================ARQUIVOS======================\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {
        if(endsWithSuffix (lsdir->d_name,".trpg")){
            printf (" %s\n", lsdir->d_name);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("           SEM DADOS SALVOS\n");
    }
    printf("====================================================\n");
    closedir(dir);
    printf("\n >>> *ATENCAO, SOMENTE ARQUIVOS TERMINADOS EM .trpg SERAO LIDOS!*");
    printf("\n\n >Digite o nome do arquivo a ser carregado: ");
    scanf("%s", file_name);

    arquivo = fopen(file_name,"r");

    if(arquivo == NULL){
        printf(">*Erro ao abrir o arquivo %s*<\n", file_name);
        fclose(arquivo);
        pause();
    }

    else{
        if (!endsWithSuffix (file_name,".trpg")) {
            printf("Error - \"%s\" parece nao ser um arquivo de TRPG valido...\n", file_name);
        }

        else {
            load = 1; // quando entrar no loop principal o programa sabe que foi carregador um arquivo
            fscanf(arquivo, "%d",&id_classe); // pega a classe primeiro
            switch(id_classe){ // leitura do arquivo conforme o id da classe.
                case 1:// Guerreiro
                    fscanf(arquivo, "%s",name);
                    fscanf(arquivo, "%d",&health);
                    fscanf(arquivo, "%d",&rage);
                    fscanf(arquivo, "%d",&level);
                    fscanf(arquivo, "%d",&gold);
                    fscanf(arquivo, "%d",&xp_now);
                    fscanf(arquivo, "%d",&xp_total);
                    break;
                case 2:// Vigilante
                    fscanf(arquivo, "%s",name);
                    fscanf(arquivo, "%d",&health);
                    fscanf(arquivo, "%d",&combo);
                    fscanf(arquivo, "%d",&level);
                    fscanf(arquivo, "%d",&gold);
                    fscanf(arquivo, "%d",&xp_now);
                    fscanf(arquivo, "%d",&xp_total);
                    break;
                case 3:// Mago
                    fscanf(arquivo, "%s",name);
                    fscanf(arquivo, "%d",&health);
                    fscanf(arquivo, "%d",&mana);
                    fscanf(arquivo, "%d",&level);
                    fscanf(arquivo, "%d",&gold);
                    fscanf(arquivo, "%d",&xp_now);
                    fscanf(arquivo, "%d",&xp_total);
                    break;
                case 4:// Bruxo
                    fscanf(arquivo, "%s",name);
                    fscanf(arquivo, "%d",&health);
                    fscanf(arquivo, "%d",&mana);
                    fscanf(arquivo, "%d",&level);
                    fscanf(arquivo, "%d",&gold);
                    fscanf(arquivo, "%d",&xp_now);
                    fscanf(arquivo, "%d",&xp_total);
                    break;
                case 5:// Paladino
                    fscanf(arquivo, "%s",name);
                    fscanf(arquivo, "%d",&health);
                    fscanf(arquivo, "%d",&mana);
                    fscanf(arquivo, "%d",&level);
                    fscanf(arquivo, "%d",&gold);
                    fscanf(arquivo, "%d",&xp_now);
                    fscanf(arquivo, "%d",&xp_total);
                    break;
                default:
                    ERROR
                    break;
            }

            Hero = getClass(name, Hero, id_classe); // criando o jogador
            int id_class = Hero->id_classe; // armazenando sua classe
            CreateHeroSkill(id_class,pointer_skill); // criando a skill de lv 0.

            // Colocando o XP correto no jogador.
            Hero->xp_now = xp_now;
            Hero->xp_total = xp_total;

            // um Case pra cada tipo de classe de jogador.
            switch(id_classe){
                case 1:
                    if(Hero->xp_total <= Hero->xp_now){
                        Hero = level_up_save(Hero);
                        skills_add(Hero, pointer_skill);
                        if(Hero->xp_now >= Hero->xp_total){
                            while(Hero->xp_now >= Hero->xp_total){
                                Hero = level_up_save(Hero);
                                skills_add(Hero, pointer_skill);
                            }
                        }
                    }
                    Hero->health = health;
                    Hero->rage = rage;
                    break;
                case 2:
                    if(Hero->xp_total <= Hero->xp_now){
                        Hero = level_up_save(Hero);
                        skills_add(Hero, pointer_skill);
                        if(Hero->xp_now >= Hero->xp_total){
                            while(Hero->xp_now >= Hero->xp_total){
                                Hero = level_up_save(Hero);
                                skills_add(Hero, pointer_skill);
                            }
                        }
                    }
                    Hero->health = health;
                    Hero->combo = combo;
                    break;
                case 3:
                    if(Hero->xp_total <= Hero->xp_now){
                        Hero = level_up_save(Hero);
                        skills_add(Hero, pointer_skill);
                        if(Hero->xp_now >= Hero->xp_total){
                            while(Hero->xp_now >= Hero->xp_total){
                                Hero = level_up_save(Hero);
                                skills_add(Hero, pointer_skill);
                            }
                        }
                    }
                    Hero->health = health;
                    Hero->mana = mana;
                    break;
                case 4:
                    if(Hero->xp_total <= Hero->xp_now){
                        Hero = level_up_save(Hero);
                        skills_add(Hero, pointer_skill);
                        if(Hero->xp_now >= Hero->xp_total){
                            while(Hero->xp_now >= Hero->xp_total){
                                Hero = level_up_save(Hero);
                                skills_add(Hero, pointer_skill);
                            }
                        }
                    }
                    Hero->health = health;
                    Hero->mana = mana;
                    break;
                case 5:
                    if(Hero->xp_total <= Hero->xp_now){
                        Hero = level_up_save(Hero);
                        skills_add(Hero, pointer_skill);
                        if(Hero->xp_now >= Hero->xp_total){
                            while(Hero->xp_now >= Hero->xp_total){
                                Hero = level_up_save(Hero);
                                skills_add(Hero, pointer_skill);
                            }
                        }
                    }
                    Hero->health = health;
                    Hero->mana = mana;
                    break;
                default:
                    ERROR
                    break;
            }

            while(!feof(arquivo)){ // varredura no resto do arquivo, one contem os items do jogador.
                fscanf(arquivo, "%d %d", &load_item_id[i], &quantidade[i]);
                count_item++; // contando a quantidade de nodes de items
                i++; // iteracao do vetor, cada [i] onde i sendo posicao, armazena um id_item e quantidade dele.
            }

            system("cls");
            printf(" >>>Jogo carregado com sucesso!\n\n");
            pause();
            fclose(arquivo);
            //Abaixo entra no Loop principal do jogo.
            execute_dungeon(Hero, Monster, pointer_skill, prop_skill_pointer);
        }
    }
}

int start(){
    setlocale(LC_ALL, "Portuguese");
    //Start(); // Inicia o jogo
    //Intro(); // Intro do jogo com historia
    while( quit == 0){
        player *Hero = NULL;  //ponteiro para o jogador
        mobs *Monster = NULL; //ponteiro para os monstros
        skill *pointer_skill = CreatePointer();// ponteiro para habilidade do jogador
        skill_prop *prop_skill_pointer = malloc(sizeof(skill_prop)); // pointeiro para propriedades das habilidades do jogador

        Hero = Menu(Hero); // Recebe o jogador ja criado do Menu.

        if (new_game == 1) { // entra no novo jogo
            int id_class = Hero->id_classe;
            CreateHeroSkill(id_class,pointer_skill); // criando a skill de lv 0.
            execute_dungeon(Hero, Monster, pointer_skill, prop_skill_pointer); // loop principal do jogo
        }

        if (tutorial == 1) { // executa o tutorial
            execute_tutorial(Hero, Monster, pointer_skill, prop_skill_pointer);
            tutorial = 0;
        }

    }
    return 1;
}
