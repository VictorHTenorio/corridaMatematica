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
int numeroAleatorio();
int soma();
int subtracao();
int multiplicacao();
int divisao();
int equacao();

int main() {
    srand(time(NULL));
    Node *head = NULL;
    Node *tail = NULL;
    int qtdPlayers;
    char palavra[20];
    int flag = 0; // se a flag for 1, acabou o jogo
    int flagResposta = 0; // se ja respondeu = 1, nao respondeu =0
    int retorno;

    printf("Quantas pessoas vao jogar?\n");
    scanf("%d",&qtdPlayers);
    getchar();

    for(int i = 0; i<qtdPlayers; i++){
        printf("Digite o nome do jogador %d\n",i+1);
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';
        inserirPlayer(&head,&tail,palavra);
    }
    
    Node *aux = head;
    while(flag==0){
        
        if ((aux->score == 0) && (flagResposta == 0)){
            printf("Vez de %s\n",aux->nome);
            retorno = soma();
            if (retorno == 1){
                aux->score ++;
                retorno = 0;
                flagResposta = 1; 
            }
        }
        else if ((aux->score == 1 ) && (flagResposta == 0)){
            printf("Vez de %s\n",aux->nome);
            retorno = subtracao();
            if (retorno == 1){
                aux->score ++;
                retorno = 0;
                flagResposta = 1; 
            }
        }
        else if ((aux->score == 2 ) && (flagResposta == 0)){
            printf("Vez de %s\n",aux->nome);
            retorno = multiplicacao();
            if (retorno == 1){
                aux->score ++;
                retorno = 0;
                flagResposta = 1; 
            }
        }
        else if ((aux->score == 3 ) && (flagResposta == 0)){
            printf("Vez de %s\n",aux->nome);
            retorno = divisao();
            if (retorno == 1){
                aux->score ++;
                retorno = 0;
                flagResposta = 1; 
            }
        }
        else if ((aux->score == 4 ) && (flagResposta == 0)){
            printf("Pergunta final! Vez de %s\n",aux->nome);
            retorno = equacao();
            if (retorno == 1){
                aux->score ++;
                retorno = 0;
                flagResposta = 1;
                flag = 1;
            }
        }
        flagResposta = 0;
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

int soma(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = a + b;
    int input;

    printf("%d + %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        return 1;
       
    }else{
        printf("Voce errou\n");
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
        return 1;
       
    }else{
        printf("Voce errou\n");
        return 0;
    }
}

int multiplicacao(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = a * b;
    int input;

    printf("%d x %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        return 1;
       
    }else{
        printf("Voce errou\n");
        return 0;
    }
}

int divisao(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = a / b;
    int input;

    printf("%d / %d = ?\n",a,b);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        return 1;
       
    }else{
        printf("Voce errou\n");
        return 0;
    }
}

int equacao(){
    int a = numeroAleatorio();
    int b = numeroAleatorio();
    int resposta = ((a + b)*b)-a;
    int input;

    printf("((%d + %d)x %d)-%d = ?\n",a,b,b,a);    
    scanf("%d",&input);
    if (input==resposta){
        printf("Voce acertou!\n");
        return 1;
       
    }else{
        printf("Voce errou\n");
        return 0;
    }
}
