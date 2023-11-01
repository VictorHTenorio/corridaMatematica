#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char nome[20];
    int score;
    struct Node *prox;
} Node;

void inserirPlayer(Node **head,Node **tail,char nome[20]);
void somaScore(Node **head);
int numeroAleatorio();
void soma();

int main() {
    srand(time(NULL));
    Node *head = NULL;
    Node *tail = NULL;
    int qtdPlayers;
    char palavra[20];
    int flag = 0; // se a flag for 1, acabou o jogo
    int flagResposta = 0; // se ja respondeu = 1, nao respondeu =0

    printf("Quantas pessoas vao jogar?\n");
    scanf("%d",&qtdPlayers);

    for(int i = 0; i<qtdPlayers; i++){
        printf("Digite o nome do jogador %d\n",i+1);
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';
        inserirPlayer(&head,&tail,palavra);
    }
    printf("%d",head->score);

    Node *aux = head;
    while(flag=0){
        
        if ((aux->score == 0) && (flagResposta = 0)){
            //soma();
        }
        else if ((aux->score == 1 ) && (flagResposta = 0)){
            // subtracao(&head);
        }
        else if ((aux->score == 2 ) && (flagResposta = 0)){
            // multiplicacao(&head);
        }
        else if ((aux->score == 3 ) && (flagResposta = 0)){
        // divisao(&head);
        }
        else if ((aux->score == 4 ) && (flagResposta = 0)){
        // equacao(&head);
        }
        aux=aux->prox;
        //passar para o prox no
    }

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

void somaScore(Node **head){
    (*head)->score = (*head)->score +1;
}

void soma(){
    int a = numeroAleatorio;
    int b = numeroAleatorio;
    int resposta = a + b;
    int input;

    printf("%d + %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
       
    }

}
