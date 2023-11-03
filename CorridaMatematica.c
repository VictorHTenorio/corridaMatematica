#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct Node {
    char nome[20];
    int score;
    struct Node *prox;
} Node;

void inserirPlayer(Node **head,Node **tail,char nome[20]);
int numeroAleatorio();
int numeroAleatorio_mult();
int numeroAleatorio_div();
int soma();
int subtracao();
int multiplicacao();
int divisao();
int equacao();
void bubbleSort(Node **head, Node** tail);
void tabelaScore(Node *head, Node* tail);
int tamanho(Node *head, Node *tail);
void liberar(Node **head, Node **tail);
void menu() {
    printf("\033[H\033[J"); // Limpa a tela
    printf("Bem-vindo ao Jogo de Matemática!\n");
    printf("=================================\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Pontuações\n");
    printf("3. Sair\n");
    printf("=================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    srand(time(NULL));
    Node *head = NULL;
    Node *tail = NULL;
    int qtdPlayers;
    char palavra[20];
    int flag = 0; // se a flag for 1, acabou o jogo
    int flagFive = 0; //flag que diz se alguem fez 5 de score (1 - sim / 0 - nao)
    int retorno;
    int escolha=0;
    do{
        //printf("\033[H\033[J"); // Limpa a tela
        printf("         Jogo de Matematica!     \n");
        printf("=================================\n");
        printf("|1. Iniciar Jogo                |\n");
        printf("|2. Regras                      |\n");
        printf("|3. Sair                        |\n");
        printf("=================================\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &escolha);
        if(escolha == 1){
            printf("Quantas pessoas vao jogar?\n");
            scanf("%d",&qtdPlayers);
            getchar();

            for(int i = 0; i<qtdPlayers; i++){
                printf("\033[H\033[J");
                printf("Digite o nome do jogador %d\n",i+1);
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';
                inserirPlayer(&head,&tail,palavra);
            }
            
            Node *aux = head;
            while(flag==0){
                printf("\033[H\033[J");
                if (aux->score == 0){
                    printf("Vez de %s\n",aux->nome);
                    retorno = soma();
                    if (retorno == 1){
                        aux->score ++;
                        retorno = 0;
                    }
                }
                else if (aux->score == 1 ){
                    printf("Vez de %s\n",aux->nome);
                    retorno = subtracao();
                    if (retorno == 1){
                        aux->score ++;
                        retorno = 0;
                    }
                }
                else if (aux->score == 2 ){
                    printf("Vez de %s\n",aux->nome);
                    retorno = multiplicacao();
                    if (retorno == 1){
                        aux->score ++;
                        retorno = 0; 
                    }
                }
                else if (aux->score == 3 ){
                    printf("Vez de %s\n",aux->nome);
                    retorno = divisao();
                    if (retorno == 1){
                        aux->score ++;
                        retorno = 0;
                    }
                }
                else if (aux->score == 4 ){
                    printf("Pergunta final! Vez de %s\n",aux->nome);
                    retorno = equacao();
                    if (retorno == 1){
                        aux->score ++;
                        retorno = 0;
                        flagFive = 1;
                    }
                }
                if((aux==tail)&&(flagFive==1)){
                    flag = 1;
                }
                aux=aux->prox;
                //passar para o prox no
            }
            bubbleSort(&head,&tail);
            
            tabelaScore(head,tail);
            //liberar(&head, &tail);
        }else if(escolha == 2){ 
            printf("\n");
            printf("O jogo consiste em um jogo de perguntas matemáticas com 5 perguntas envolvendo diferentes operações.\n");
            printf("O jogador que conseguir responder primeiro às 5 perguntas ganha. Se vários jogadores responderem a mesma pergunta\n");
            printf("na mesma rodada, pode ocorrer um empate.\n");
            printf("\n");
        }else if(escolha == 3){ 
            printf("Obrigado por acessar o jogo, até a proxima!! ");
            exit(1);
        }else{ 
            printf("Opção invalida.");
        }
    }while(escolha!=3);

    return 0; 
}

void inserirPlayer(Node **head,Node **tail, char nome[20]) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->score = 0;
        if(*head==NULL) {
            *tail = novo;
            *head = novo;
            (*tail)->prox = *head;
        }else{
            (*tail)->prox = novo;
            *tail = novo;
            (*tail)->prox = *head;
        }
    }
}

int numeroAleatorio(){
    int n = (rand() % 100) + 1;
    return n;
}
int numeroAleatorio_mult(){
    int n = (rand() % 20) + 1;
    return n;
}
int numeroAleatorio_div(){
    int n = (rand() % 200) + 1;
    return n;
}


int soma(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = a + b;
    int input;

    printf("%d + %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        sleep(1);
        return 1;
       
    }else{
        printf("Voce errou\n");
        sleep(1);
        return 0;
    }
}

int subtracao(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = a - b;
    int input;

    printf("%d - %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        sleep(1);
        return 1;
       
    }else{
        printf("Voce errou\n");
        sleep(1);
        return 0;
    }
}

int multiplicacao(){
    int a = numeroAleatorio_mult();
    int b = numeroAleatorio_mult();
    int resposta = a * b;
    int input;

    printf("%d x %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        sleep(1);
        return 1;
       
    }else{
        printf("Voce errou\n");
        sleep(1);
        return 0;
    }
}

int divisao(){
    int a = numeroAleatorio_div();
    int b = numeroAleatorio_div();
    while(a%b!=0){
        a = numeroAleatorio_div();
        b = numeroAleatorio_div();   
    }
    int resposta = a / b;
    int input;
    printf("%d / %d = ?\n",a,b); 
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        sleep(1);
        return 1;
       
    }else{
        printf("Voce errou\n");
        sleep(1);
        return 0;
    }
}

int equacao(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = ((a + b)*2)-a;
    int input;

    printf("((%d + %d)x 2)-%d = ?\n",a,b,a);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        sleep(1);
        return 1;
       
    }else{
        printf("Voce errou\n");
        sleep(1);
        return 0;
    }
}

void tabelaScore(Node *head, Node *tail) {
    if (head != NULL) {
        int largura1 = 20;
        int largura2 = 10;

        printf("\033[H\033[J");
        printf("Tabela De Pontos: \n");
        printf("%*s | %*s\n", largura1, "Jogador", largura2, "Pontuacao");
        do {
            printf("%*s | %*d\n", largura1, head->nome, largura2, head->score);
            head = head->prox;
        } while (head != tail->prox);
    }
    int cont; 
    printf("\ndeseja continuar o jogo? (1 = SIM), (2 = NÃO)\n");
    scanf("%d", &cont);
    if(cont == 2 ){
        exit(1);
    }
    printf("\033[H\033[J");
}


void bubbleSort(Node **head, Node** tail){
    Node *aux = *head;
    char tempNome[20];
    int tempScore;
    int len = tamanho(*head,*tail);
    for(int i = 0; i<len; i++){
        aux = *head;
        for(int j = 0; j<len-1;j++){
            if((aux !=NULL) && (aux->score<aux->prox->score)){
                strcpy(tempNome,aux->nome);
                tempScore = aux->score;

                strcpy(aux->nome,aux->prox->nome);
                aux->score = aux->prox->score;

                strcpy(aux->prox->nome,tempNome);
                aux->prox->score = tempScore;
            }
            aux = aux->prox;
        }
    }   
}

int tamanho(Node *head, Node *tail) {
    int contador = 0;
    if(head != NULL){
        do{
        head = head->prox;
        contador ++;
        }while(head != tail->prox);
    }
    return(contador);
}

void liberar(Node **head, Node **tail) {
    if(*head != NULL){
        Node *aux = *head;
        do{
            if(*head == *tail){
                *head = NULL;
                *tail = NULL;
            }else{
                *head = (*head)->prox;
                (*tail)->prox = *head;
            }
            free(aux);
        }while((*head) != (*tail)->prox);
    }
}