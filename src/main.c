/**
 * 
 * 
 *@file   main.c
 *@author grupo 65 
 *@date   07/01/18
 * 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/*** --------------------------------------------------------------------- ***/

/*** Funções do programa  ***/

void desenha_nome();     /*** Função para o desenho do logo do jogo ***/
void tabela();           /*** Função que mete as peças de jogo nas posições ***/
void le_instrucoes();    /*** Função que lê as instruções de jogo ***/
void movimento_cima();   /*** Função para o começo de jogo 'O' ***/
void movimento_baixo();  /*** Função para o começo de jogo '@' ***/
void coordenadas_1();      /*** Função para fazer as trocas de peças 1 ***/
void coordenadas_2();      /*** Função para fazer as trocas de peças 2 ***/     
void desenho_tabela();       /*** Função para imprimir o tabuleiro de jogo ***/
void troca_diagonais();      /*** Função para fazer as diagonais da rainha ***/  
void rainha_jog_1();         /*** Função para verificar a rainha jog.1 ***/
void rainha_jog_2();         /*** Função para verificar a rainha jog.2 ***/
void clearScreen();          /*** Função para limpar o ecrã ***/
void coordenadas_rainha_1(); /*** Função para trocas da rainha 1 ***/
void coordenadas_rainha_2(); /*** Função para trocas da rainha 2 ***/
void le();                   /*** Função para ler o nome dos jogadores ***/
void mostra();               /*** Função que desenha o placard de jogo ***/
int verifica_peca_jog_1(); /*** Função para verificar a peça do jog. 1 ***/
int verifica_peca_jog_2(); /*** Função para verificar a peça do jog. 2 ***/
int verifica_peca_rainha();  /*** Função para verificar se a linha = 7 ou 0 ***/
int escolha_posicao_linha(); /*** Função para introduzir a linha ***/
int escolha_posicao_coluna();/*** Função para introduzir a coluna ***/

/*** --------------------------------------------------------------------- ***/

/*** Variáveis, matrizes, vetores e estruturas ***/

int contador[2]={12,12};   /*** Contador das peças de cada jogador ***/
const int linha_tab = 8;   /*** linhas da tabela iguais a 8 ***/
const int coluna_tab = 8;  /*** Colunas da tabela igual a 8 ***/
char tab[8][8];            /*** Matriz de jogo 8*8 ***/
char linha[8]={'A','B','C','D','E','F','G','H'};/*** Coordenadas das linhas ***/
char peca[6] = {'O','@','.',' ','R','Q'};/*** Vetor com as peças de jogo
                                                 * e espaços vazios e não 
                                                 * jogáveis ***/

struct jogadores{/*** Estrutura jogador ***/
    
    char nome[100];   
};

/*** -------------------------------------------------------------------- ***/

/*** Função "Main" ***/


int main() {
    
    unsigned short int esc;
    
    desenha_nome();

   do{
        do{/*** Menu de jogo ***/
            printf("\n 1 - JOGAR VERSUS HUMANO");
            printf("\n 2 - INSTRUCOES DO JOGO");
            printf("\n 3 - SAIR");
            printf("\n\nIntroduza a sua escolha: ");
            scanf("%hu",& esc);
        }while(esc <= 1 && esc >= 3);
        switch(esc){
            case 1 :
                clearScreen();
                le();
                mostra();
                tabela();
                break;
            case 2 :
                clearScreen();
                le_instrucoes();
                break;
            case 3 :
                exit(0);
                break;    
        }
    }while(esc != 3);

                    
    return 0;
}

/*** -------------------------------------------------------------------- ***/

/*** Função que imprime o logo do jogo ***/

void desenha_nome(){
    
    printf("\n\t******      ******   ***    ***    ******     ******\n");
    
    printf("\t**    **   **    **  ****  ****   **    **   **\n");
    
    printf("\t**    **   **    **  **  **  **   **    **    ***\n");
    
    printf("\t**    **   ********  **      **   ********       ***\n");
    
    printf("\t**    **   **    **  **      **   **    **         **\n");
    
    printf("\t******     **    **  **      **   **    **    ******\n");
 
    printf("\t-----------------------------------------------------\n");   
    
    

}

/*** -------------------------------------------------------------------- ***/

/*** Função para ler as instruções do jogo ***/

void le_instrucoes()
{
    
    char ch;
    FILE *ptr;
    
    ptr = fopen("regras.txt", "r");
    
    if(ptr == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    else
    {
        while((ch = fgetc(ptr)) != EOF)
            putchar(ch);
    }
    
    fclose(ptr);
}


/*** -------------------------------------------------------------------- ***/

/*** Função para preencher a matriz de jogo com as peças ***/


void tabela() {
    
    /*** Colocação das peças de jogo nas posições ***/
    
    tab[0][0] = peca[0];
    tab[0][1] = peca[2];
    tab[0][2] = peca[0];
    tab[0][3] = peca[2];
    tab[0][4] = peca[0];
    tab[0][5] = peca[2];
    tab[0][6] = peca[0];
    tab[0][7] = peca[2];

    tab[1][0] = peca[2];
    tab[1][1] = peca[0];
    tab[1][2] = peca[2];
    tab[1][3] = peca[0];
    tab[1][4] = peca[2];
    tab[1][5] = peca[0];
    tab[1][6] = peca[2];
    tab[1][7] = peca[0];

    tab[2][0] = peca[0];
    tab[2][1] = peca[2];
    tab[2][2] = peca[0];
    tab[2][3] = peca[2];
    tab[2][4] = peca[0];
    tab[2][5] = peca[2];
    tab[2][6] = peca[0];
    tab[2][7] = peca[2];

    tab[3][0] = peca[2];
    tab[3][1] = peca[3];
    tab[3][2] = peca[2];
    tab[3][3] = peca[3];
    tab[3][4] = peca[2];
    tab[3][5] = peca[3];
    tab[3][6] = peca[2];
    tab[3][7] = peca[3];

    tab[4][0] = peca[3];
    tab[4][1] = peca[2];
    tab[4][2] = peca[3];
    tab[4][3] = peca[2];
    tab[4][4] = peca[3];
    tab[4][5] = peca[2];
    tab[4][6] = peca[3];
    tab[4][7] = peca[2];

    tab[5][0] = peca[2];
    tab[5][1] = peca[1];
    tab[5][2] = peca[2];
    tab[5][3] = peca[1];
    tab[5][4] = peca[2];
    tab[5][5] = peca[1];
    tab[5][6] = peca[2];
    tab[5][7] = peca[1];

    tab[6][0] = peca[1];
    tab[6][1] = peca[2];
    tab[6][2] = peca[1];
    tab[6][3] = peca[2];
    tab[6][4] = peca[1];
    tab[6][5] = peca[2];
    tab[6][6] = peca[1];
    tab[6][7] = peca[2];

    tab[7][0] = peca[2];
    tab[7][1] = peca[1];
    tab[7][2] = peca[2];
    tab[7][3] = peca[1];
    tab[7][4] = peca[2];
    tab[7][5] = peca[1];
    tab[7][6] = peca[2];
    tab[7][7] = peca[1];

     

    /*** Imprime tabuleiro de jogo ***/

    desenho_tabela(tab);
    
    movimento_baixo(tab); /*** chama a função movimento_baixo para a
                                                 * primeira jogada***/
}

/*** -------------------------------------------------------------------- ***/

/*** Função para desenhar a tabela ***/


void desenho_tabela(char tab[][8]){
    
    int i, j;
   
    /*** Imprime tabuleiro de jogo ***/

    printf(" \t  ---------------------------------\n");
    
    for (i = 0; i < 8; i++) {
        
        printf("\t%c ", linha[i]);

        for (j = 0; j < 8; j++) {


            printf("| %c ", tab[i][j]);
        }
        
        printf("|\n");
        
        printf(" \t  ---------------------------------\n");
    }
    
    printf("   \t    1   2   3   4   5   6   7   8");
     
}

/*** -------------------------------------------------------------------- ***/

/***Função para o receber as coordenadas da peça a ser jogada pelo jogador 1***/

void movimento_baixo(char tab[8][8]) {

    int  y, esc_col, i, j, posicao,l, verifica;

    char x;
   
    struct jogadores *leJog1 = malloc(sizeof(struct jogadores));
    
    FILE *fich;
    
    fich = fopen("jogador1.txt", "r");
    
    if(fich == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fread(leJog1, sizeof(struct jogadores), 1, fich);
        fclose(fich);
    }
   
    printf("\n %s ---> @ \n", leJog1->nome);
    
    do{
    
    i = escolha_posicao_linha(i);
    
    esc_col = escolha_posicao_coluna(esc_col);
    
    if(tab[i][esc_col] == '@' &&
            tab[i-1][esc_col+1] == '@' &&
            tab[i-1][esc_col-1] == '@'){
        
        printf("\nEscolha invalida! A peca que escolheu tem mais pecas à"
                " sua frente!\n");
       
        posicao = 2; 
    }
    
    else if((esc_col == 7 && tab[i][esc_col] == '@' &&
            tab[i-i][esc_col-1] == '@') ||
            (esc_col == 0 && tab[i][esc_col] == '@' &&
            tab[i-1][esc_col+1] == '@')){
        
        printf("\nEscolha invalida !\n");
        
        
        posicao = 2;
        
    }
    
    else if(tab[i][esc_col] == '@' && tab[i-1][esc_col-1] == '@' &&
            tab[i-1][esc_col+1] == '@' &&
            tab[i-2][esc_col-2] == 'O' && tab[i-2][esc_col+2] == 'O'){
        
        printf("\nEscolha invalida !\n");
        
        
        posicao = 2;
        
    }
    else if ((tab[i][esc_col] == '.') ||
            (tab[i][esc_col] == ' ') ||
            (tab[i][esc_col] == 'O')){                       
        
        printf("\nEscolha invalida a sua peca e a '@'!\n");
        

        posicao = 2;

    }
    
    else if((tab[i][esc_col] == 'R' && tab[i+1][esc_col+1] == 'O' &&
            tab[i+1][esc_col-1] == 'O')||
            (tab[i][esc_col] == 'R' &&
            tab[i-1][esc_col+1] == 'O' && tab[i-1][esc_col-1] == 'O'))
        
        posicao = 2;
    
    else
       
       posicao = 1;
    
    }while(posicao != 1);
    
    do{
    
        do{
    
        printf("\nIntroduza a linha para onde pretende mover a peca: ");
        
        scanf(" %c", &x);
        
        x = toupper(x);/*** passa minusculas a maiusculas ***/
        
        }while( x != 'A' && x != 'B' && x != 'C' && x != 'D' &&
                x != 'E' && x != 'F' && x != 'G' && x != 'H');
            
        for (j = 0; j <= 7; j++) {/*** contador para percorrer o vetor linha 
                             para encontrar o caracter ***/

            if (x == linha[j]) {/*** se a escolha for igual à posição 
                                       do vetor ***/

                x = j; /*** escolha passa a ser o indice do vetor
                                  encontrado ***/

                break;
            }

        }
        
        printf("\nIntroduza a coluna para onde pretende mover a peca: ");
        
        scanf("%d", &y);
                   
        y--;
 
        if( tab[i][esc_col] == peca[4] )
            
            verifica = verifica_peca_rainha(i,esc_col,y,j);
            
        else
        
            verifica = verifica_peca_jog_1(i, esc_col, y,j); 
        
    }while(verifica != 1);   
    
    clearScreen();
    
    if(tab[i][esc_col] != peca[4]){
        
        rainha_jog_1(tab,j,y);
        
        coordenadas_1(tab,i,j,y,esc_col);
   
    }
    else{
    
        rainha_jog_1(tab,j,y);
        
        coordenadas_rainha_1(tab,i,esc_col,y,j);
    }
    movimento_cima(tab);

    }

/*** -------------------------------------------------------------------- ***/

/***Função para o receber as coordenadas da peça a ser jogada pelo jogador 2***/


void movimento_cima(char tab[8][8]) {

    int  y, esc_col, i, posicao, j, verifica;
   
    char x;
   
    struct jogadores *leJog2 = malloc(sizeof(struct jogadores));
    
    FILE *fich2;
    
    fich2 = fopen("jogador2.txt", "r");
    
    if(fich2 == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fread(leJog2, sizeof(struct jogadores), 1, fich2);
        fclose(fich2);
    }
   
    printf("\n %s---> O \n", leJog2->nome);
    
    do{
    
        i = escolha_posicao_linha(i);
    
        esc_col = escolha_posicao_coluna(esc_col);
        
        if((tab[i][esc_col] == 'O' &&
                tab[i+1][esc_col+1] == 'O' &&
                tab[i+1][esc_col-1] == 'O')){
   
            printf("\nEscolha invalida! A peca que escolheu tem mais pecas suaÂ frente!");
                  
            posicao = 2; 
    
        }
    
        else if((esc_col == 7 && tab[i][esc_col] == 'O' &&
                tab[1+i][1+esc_col] == 'O') ||
                (esc_col == 0 && tab[i][esc_col] == 'O' &&
                tab[1+i][1-esc_col] == 'O')){
        
            printf("\nEscolha invalida !\n");
        
            posicao = 2;
        
        }
         
        else if(tab[i][esc_col] == '@' && tab[i+1][esc_col-1] == '@' &&
                tab[i+1][esc_col+1] == '@' &&
                tab[i+2][esc_col-2] == 'O' && tab[i+2][esc_col+2] == 'O'){
        
        printf("\nEscolha invalida !\n");
        
        
        posicao = 2;
        
        }
        else if (tab[i][esc_col] == '.' ||
                tab[i][esc_col] == ' ' ||
                tab[i][esc_col] == '@'){                       
        
            printf("Escolha invalida a sua peca e a 'O'!\n");
        
            posicao = 2;

        }
    
         else if((tab[i][esc_col] == 'Q' && tab[i+1][esc_col+1] == 'O' &&
                 tab[i+1][esc_col-1] == 'O')||
                (tab[i][esc_col] == 'Q' &&
                 tab[i-1][esc_col+1] == 'O' && tab[i-1][esc_col-1] == 'O'))
        
            posicao = 2;
    
        
        else
       
            posicao = 1;
    
    }while(posicao != 1);
                         
    do{
        
        do{
    
            printf("\nIntroduza a linha para onde pretende mover a peca: ");
        
            scanf(" %c", &x);
        
            x = toupper(x);/*** passa minusculas a maiusculas ***/
        
        }while( x != 'A' && x != 'B' && x != 'C' && x != 'D' &&
                x != 'E' && x != 'F' && x != 'G' && x != 'H' );
        
        for (j = 0; j <= 7; j++) {/*** contador para percorrer o vetor linha 
                             para encontrar o caracter ***/

            if (x == linha[j]) {/*** se a escolha for igual à posição 
                                       do vetor ***/

                x = j; /*** escolha passa a ser o indice do vetor
                                  encontrado ***/

                break;
            }

        }
        
        do{
        
            printf("\nIntroduza a coluna para onde pretende mover a peca: ");
        
            scanf("%d", &y);
        
        }while(y != 1 && y != 2 && y != 3 && y != 4 && y != 5 && y != 6 &&
               y != 7 && y != 8);
        
        y--;
        
        if(tab[i][esc_col] == peca[5])
            
            verifica = verifica_peca_rainha(i,esc_col,y,j);
            
        else
            
            verifica = verifica_peca_jog_2(i,esc_col, y, j);
        
    }while(verifica != 1);
     
    clearScreen();

    if(tab[i][esc_col] != peca[5]){
    
        rainha_jog_2(tab,j,y);

        coordenadas_2(tab,i,j,y,esc_col);
       
    }
    else{
        
        rainha_jog_2(tab,j,y); 
        
        coordenadas_rainha_2(tab,i,esc_col,y,j);
    }
    
    movimento_baixo(tab);
    }

/*** -------------------------------------------------------------------- ***/

/*** Função que pede a linha para se jogar ***/

int escolha_posicao_linha(int i){

   
    char esc_linha;
    
        do{
    
            printf("\nSe pretende sair coloque a letra S.");
            
            printf("\nIntroduza a linha da peca que pretende mover:");
            
            scanf(" %c", &esc_linha);
    
            esc_linha = toupper(esc_linha); /*** passa minusculas a
                                             *  maiusculas ***/
    
        }while( esc_linha != 'A' && esc_linha != 'B' && esc_linha != 'C' &&
                esc_linha != 'D' && esc_linha != 'E' && esc_linha != 'F' &&
                esc_linha != 'G' && esc_linha != 'H' && esc_linha != 'S');
        
        if(esc_linha == 'S')
            
            main();
            
    for (i = 0; i <= 7; i++) {/*** contador para percorrer o vetor linha 
                             para encontrar o caracter ***/

        if (esc_linha == linha[i]) {/*** se a escolha for igual à posição 
                                       do vetor ***/

            break;
        }

    }
   
   return i; 
}

/*** -------------------------------------------------------------------- ***/

/*** Função para a escolha da coluna ***/
 
int escolha_posicao_coluna (int esc_col){   

    do{
   
        printf("\nIntroduza a coluna da peca que pretende mover:");
    
        scanf("%d", &esc_col);
    
    }while(esc_col != 1 && esc_col != 2 && esc_col != 3 &&
           esc_col != 4 && esc_col != 5 && esc_col != 6 &&
           esc_col != 7 && esc_col != 8);
    
    esc_col--; /*** subtrai 1 à escolha para ficar igual ao indice do vetor ***/

    return esc_col;
    
}

/*** -------------------------------------------------------------------- ***/

/*** Função para verificar a peça do jogador 1 ***/

int verifica_peca_jog_1(int i, int esc_col, int y, int j) {              
   
    if((tab[i][esc_col] == '@' && j == i-1 && y == esc_col-1 &&
            tab[j][y] == ' ') || (tab[i][esc_col] == '@' &&
            j == i-1 && y == esc_col+1 && tab[j][y] == ' '))
        
        return 1;
    
    else if((tab[i][esc_col] == '@' && j == i-2 && y == esc_col-2 &&
            tab[j][y] == ' ' && tab[i-1][esc_col-1] == 'O')||
            (tab[i][esc_col] == '@' && j == i-2 && y == esc_col+2 &&
            tab[j][y] == ' ' && tab[i-1][esc_col+1] == 'O')||
            (tab[i][esc_col] == '@' && j == i-2 && y == esc_col-2 &&
            tab[j][y] == ' ' && tab[i-1][esc_col-1] == 'Q')||
            (tab[i][esc_col] == '@' && j == i-2 && y == esc_col+2 &&
            tab[j][y] == ' ' && tab[i-1][esc_col+1] == 'Q'))
        
        return 1;
   
    else{
    
        printf(" Escolha invalida !!");
        
        return 2;
    }
        
}

/*** -------------------------------------------------------------------- ***/

/*** Função para verificar a peça do jogador 2 ***/

int verifica_peca_jog_2(int i, int esc_col, int y, int j) {              
 
    if((tab[i][esc_col] == 'O' && j == i+1 && y == esc_col-1 &&
            tab[j][y] == ' ' )||
       (tab[i][esc_col] == 'O' && j == i+1 && y == esc_col+1 &&
            tab[j][y] == ' '))
        
        return 1;
    
    else if((tab[i][esc_col] == 'O' && j == i+2 && y == esc_col-2 &&
            tab[j][y] == ' ' && tab[i+1][esc_col-1] == '@')||        
            (tab[i][esc_col] == 'O' && j == i+2 && y == esc_col+2 &&
            tab[j][y] == ' ' && tab[i+1][esc_col+1] == '@')||
            (tab[i][esc_col] == 'O' && j == i+2 && y == esc_col-2 &&
            tab[j][y] == ' ' && tab[i+1][esc_col-1] == 'R')||       
            (tab[i][esc_col] == 'O' && j == i+2 && y == esc_col+2 &&
            tab[j][y] == ' ' && tab[i+1][esc_col+1] == 'R'))
        
        return 1;
    
    else{
    
        printf(" Escolha invalida !!");
        
        return 2;
    }
    
}

/*** -------------------------------------------------------------------- ***/

/*** Função para verificar a peça rainha ***/

int verifica_peca_rainha( int i, int esc_col, int y, int j){

    if(i > j && esc_col > y){
    
        do{
        
            i--;
        
            esc_col--;
            
        }while(i != j && esc_col != y && (i >= 0 || esc_col >= 0));
        
        if(i = j)
            
            return 1;
            
    }
    
    else if(i < j && esc_col > y){
    
        do{
        
            i++;
        
            esc_col--;
         
        }while(i != j && esc_col != y && (i <= 7  || esc_col >= 0));
        
        if(i = j)
            
            return 1;
        
    }
    
    else if(i < j && esc_col < y){
    
        do{
        
            i++;
        
            esc_col++;

        }while(i != j && esc_col != y && (i <= 7 || esc_col <= 7));
        
        if(i = j)
            
            return 1;
        
    }

    else if(i > j && esc_col < y){
    
        do{
        
            i--;
        
            esc_col++;
        
        }while(i != j && esc_col != y && (i >= 0 || esc_col <= 7));
        
        if(i = j)
            
            return 1;
        
    }
    
    else 
        
        printf("\nNao pode escolher essa posicao! So pode andar na diagonal.\n");
        
        return 2;
    
}

/*** -------------------------------------------------------------------- ***/

/*** Função para fazer as trocas de posições e comer peças jogador 1 ***/

void coordenadas_1(char tab[][8], int i, int j, int y, int esc_col){
    
    char ch;
    
    if( i-1 == j ){                  /* Move a peca uma casa para a frente */
        
        tab[j][y] = tab[i][esc_col]; 
    
        tab[i][esc_col] = peca[3];

        mostra();

        desenho_tabela(tab);
    }
    
    else if(y > esc_col){/* Come uma peca do adversario e move a
                          *  peca para a direita*/
    
        tab[j][y] = tab[i][esc_col]; 
    
        tab[i][esc_col] = peca[3];
   
        tab[--i][++esc_col] = peca[3];
        
        contador[1]--;
        
        i = j;
        
        esc_col = y;
        
        mostra();
        
        desenho_tabela(tab);
        
        while(tab[j-1][y-1] == peca[0] && tab[j-2][y-2] == peca[3]){
        
        troca_diagonais(j,y,i);
        
        coordenadas_1(tab,i,j,y,esc_col);
        
        } 
         
    }
    
    
    else {   /* Come uma peca do adversario e move a peca para a esquerda*/
       
        
    
        tab[j][y] = tab[i][esc_col]; 
     
        tab[i][esc_col] = peca[3];
       
        tab[--i][--esc_col] = peca[3];
       
        contador[1]--;
       
        i = j;
        
        esc_col = y;
        
        mostra();
        
        desenho_tabela(tab);
        
        while(tab[j-1][y+1] == peca[0] && tab[j-2][y+2] == peca[3]){
        
        troca_diagonais(j,y,i);
        
        coordenadas_1(tab,i,j,y,esc_col);
        
        }
        
    
        }  
   
         if(contador[1] == 0){
                
        printf("\n\nJogo terminado. Jogador 1 foi o vencedor\n\n");
        
        printf("Introduza 'S' para voltar ao menu inicial: ");
        scanf(" %c", &ch);
        
        clearScreen();
         
        main(); 
         
    } 
       
    }
           
/*** -------------------------------------------------------------------- ***/

/*** Função para fazer as trocas de posições e comer peças jogador 2 ***/

void coordenadas_2(char tab[8][8], int i, int j, int y, int esc_col){
    
    char ch;

    if( i+1 == j ){            /* Move a peca uma casa para a frente */
        
        tab[j][y] = tab[i][esc_col]; 
    
        tab[i][esc_col] = peca[3];

        mostra();

        desenho_tabela(tab);
    }
    
    else if(y > esc_col){/* Come uma peca do adversario e move a
                          *  peca para a direita*/
            
        tab[j][y] = tab[i][esc_col]; 
    
        tab[i][esc_col] = peca[3];
   
        tab[++i][++esc_col] = peca[3];
        
        contador[0]--;
        
        i = j;
        
        esc_col = y;
        
        mostra();
        
        desenho_tabela(tab);
        
        while(tab[j+1][y-1] == peca[1] && tab[j+2][y-2] == peca[3]){
        
        troca_diagonais(j,y,i);
        
        coordenadas_2(tab,i,j,y,esc_col);
   
        }
    }
    
    else
    {    /* Come uma peca do adversario e move a peca para a esquerda*/
    
        tab[j][y] = tab[i][esc_col]; 
     
        tab[i][esc_col] = peca[3];
       
        tab[++i][--esc_col] = peca[3];
       
        contador[0]--;
       
        i = j;
        
        esc_col = y;
        
        mostra();
        
        desenho_tabela(tab);
        
        while(tab[j+1][y+1] == peca[1] && tab[j+2][y+2] == peca[3]){
        
        troca_diagonais(j,y,i);
        
        coordenadas_2(tab,i,j,y,esc_col);
        
        }
        
     }
    
    if(contador[0] == 0){
                   
            printf("\n\nJogo terminado. Jogador 2 foi o vencedor\n\n");
            
            printf("Introduza 'S' para voltar ao menu inicial: ");
            scanf(" %c", &ch);

            clearScreen();
   
            main();
        } 
        
}

/*** -------------------------------------------------------------------- ***/

/*** Função para a troca das peças da rainha do jogador 1 ***/

void coordenadas_rainha_1(char tab[][8], int i, int esc_col, int y, int j){
    
    char ch;
 
     if(i > j && esc_col > y){
        
        tab[i][esc_col] = peca[3];
        
        do{
        
            i--;
        
            esc_col--;
            
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[1]--;
            }
            
        }while(i != j && esc_col != y && (i >= 0 || esc_col >= 0));
        
        tab[j][y] = peca[4];
        
        mostra();
        
        desenho_tabela(tab);
    }
    
    else if(i < j && esc_col > y){
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i++;
        
            esc_col--;
         
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[1]--;
            }
            
        }while(i != j && esc_col != y && (i <= 7  || esc_col >= 0));
       
        tab[j][y] = peca[4];
        
        mostra();
        
        desenho_tabela(tab);
    }
    
    else if(i < j && esc_col < y){
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i++;
        
            esc_col++;

            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[1]--;
            }
            
        }while(i != j && esc_col != y && (i <= 7 || esc_col <= 7));
  
        tab[j][y] = peca[4];
        
        mostra();
        
        desenho_tabela(tab);
    }

    else{
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i--;
        
            esc_col++;
        
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[1]--;
            }
            
        }while(i != j && esc_col != y && (i >= 0 || esc_col <= 7));
    
        tab[j][y] = peca[4];
        
        mostra();
        
        desenho_tabela(tab);
    }
    
     if(contador[1] == 0){
                
        printf("\n\nJogo terminado. Jogador 1 foi o vencedor\n\n");
        
        printf("Introduza 'S' para voltar ao menu inicial: ");
        scanf(" %c", &ch);
        
        clearScreen();

        main(); 
         
    } 
}

/*** -------------------------------------------------------------------- ***/

/*** Função para a troca das peças da rainha do jogador 1 ***/

void coordenadas_rainha_2(char tab[][8], int i, int esc_col, int y, int j){
    
    char ch;
    
     if(i > j && esc_col > y){
        
        tab[i][esc_col] = peca[3];
        
        do{
        
            i--;
        
            esc_col--;
            
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[0]--;
            }
            
        }while(i != j && esc_col != y && (i >= 0 || esc_col >= 0));
        
        tab[j][y] = peca[5];
        
        mostra();
        
        desenho_tabela(tab);
    }
    
    else if(i < j && esc_col > y){
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i++;
        
            esc_col--;
         
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[0]--;
            }
            
        }while(i != j && esc_col != y && (i <= 7  || esc_col >= 0));
        
        tab[j][y] = peca[5];
        
        mostra();
        
        desenho_tabela(tab);
    }
    
    else if(i < j && esc_col < y){
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i++;
        
            esc_col++;

            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[0]--;
            }
            
        }while(i != j && esc_col != y && (i <= 7 || esc_col <= 7));
  
        tab[j][y] = peca[5];
        
        mostra();
        
        desenho_tabela(tab);
    }

    else{
    
        tab[i][esc_col] = peca[3];
        
        do{
        
            i--;
        
            esc_col++;
        
            if(tab[i][esc_col] == peca[0] || tab[i][esc_col] == peca[5]){

                tab[i][esc_col] = peca[3];

                contador[0]--;
            }
            
        }while(i != j && esc_col != y && (i >= 0 || esc_col <= 7));
    
        tab[j][y] = peca[5];
        
        mostra();
        
        desenho_tabela(tab);
    }
     
     if(contador[0] == 0){
                   
            printf("\n\nJogo terminado. Jogador 2 foi o vencedor\n\n");
            
            printf("Introduza 'S' para voltar ao menu inicial: ");
            scanf(" %c", &ch);
        
            clearScreen();
            
            main();
        } 
}

/*** -------------------------------------------------------------------- ***/

/*** Função para as diagonais da peça rainha ***/

void troca_diagonais(int j, int y, int i){

 char x;   
    
 do{    
            
        do{
    
            printf("Tem que comer a peca \n");
            
            printf("\nIntroduza a linha para onde pretende mover a peca: ");
        
            scanf(" %c", &x);
        
            x = toupper(x);/*** passa minusculas a maiusculas ***/
        
        }while( x != 'A' && x != 'B' && x != 'C' && x != 'D' &&
                x != 'E' && x != 'F' && x != 'G' && x != 'H' );
        
        for (j = 0; j <= 7; j++) {

            if (x == linha[j]) {

                x = j;
                
                break;
            }

        }
        
        }while(j == i);
        
        do{
        
            printf("\nIntroduza a coluna para onde pretende mover a peca: ");
        
            scanf("%d", &y);
        
        }while(y != 1 && y != 2 && y != 3 && y != 4 && y != 5 && y != 6 &&
               y != 7 && y != 8);
        
        y--;

}

/*** -------------------------------------------------------------------- ***/

/*** Função para verificar se a peça escolhida é a rainha no jogador 1 ***/

void rainha_jog_1(char tab[8][8],int j,int y){

    if(j == 0 && tab[j][y] == peca[1])
    
        tab[j][y] = peca[4];  
    
}

/*** -------------------------------------------------------------------- ***/

/*** Função para verificar se a peça escolhida é a rainha no jogador 2 ***/

void rainha_jog_2(char tab[8][8],int j,int y){

    if(j == 0 && tab[j][y] == peca[0])
    
        tab[j][y] = peca[5]; 
    
}

/*** -------------------------------------------------------------------- ***/

/*** Função para limpar o ecrã ***/

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);

}

/*** -------------------------------------------------------------------- ***/

/*** Função que lê o nome dos jogadores ***/

void le()
{
    struct jogadores *jog1 = malloc(sizeof(struct jogadores));
    struct jogadores *jog2 = malloc(sizeof(struct jogadores));
    
    printf("Jogador1: Introduza o seu nome: ");
    scanf("%s", jog1->nome);
    
    printf("Jogador2: Introduza o seu nome: ");
    scanf("%s", jog2->nome);
     
    FILE *fich;
    FILE *fich2;
    
    fich = fopen("jogador1.txt", "w");
    fich2 = fopen("jogador2.txt", "w");
  
    if(fich == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fwrite(jog1, sizeof(struct jogadores), 1, fich);
        fclose(fich);
    }
    
    if(fich2 == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fwrite(jog2, sizeof(struct jogadores), 1, fich2);
        fclose(fich2);
    }  
}

/*** -------------------------------------------------------------------- ***/

/*** Função para mostrar o placard e informações de jogo ***/

void mostra()
{
    struct jogadores *leJog1 = malloc(sizeof(struct jogadores));
    struct jogadores *leJog2 = malloc(sizeof(struct jogadores));
    
    FILE *fich;
    FILE *fich2;
    
    fich = fopen("jogador1.txt", "r");
    fich2 = fopen("jogador2.txt", "r");
    
    if(fich == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fread(leJog1, sizeof(struct jogadores), 1, fich);
        fclose(fich);
    }
    
    if(fich2 == NULL)
    {
        printf("Erro ao abrir o ficheiro.");
        exit(1);
    }
    
    else
    {
        fread(leJog2, sizeof(struct jogadores), 1, fich2);
        fclose(fich2);
    }
    
    
    printf("\n\t\t       DAMAS \n");

    printf("%s: '@''R'(%d/12)\t Vs \t %s: 'O''Q'(%d/12)  \n\n", 
    leJog1->nome, contador[0], leJog2->nome, contador[1]);
     
}