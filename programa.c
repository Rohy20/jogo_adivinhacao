#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo numero de tentativas
#define Try 5 //constante

int main(){
    //cabecalho do jogo
    printf("*****************************\n");
    printf("*Welcome to my Guessing Game*\n");
    printf("*****************************\n");

    //numero secreto randomico
    int seconds = time(0); //Mudando a semente da f rand() para garantir que rand() gere um numero realmente aleatorio.
    srand(seconds);
    int bignum = rand(); //funcao que trara numeros randomicos, porem muito grandes
    int secretnumber = bignum % 100; //aqui pegamos o resto da divisao por 100, para garantir que o numero sera sempre entre 0 e 99.


    //chute do jogador
    int guess;
    //int win = 0;
    //int try = 1;

    int points = 1000;

    //perguntando ao jogador qual o chute, e imprimindo na tela
    for(int i = 1; i <= Try; i++){ //loop de de acordo com as tentativas
    //while(win == 0){ //loop indeterminado, ate o jogador acertar
    //printf("Try %i\n", try + 1);
    printf("Try %i of %i\n", i, Try);
    printf("What's your guess?? ");
    scanf("%i", &guess);
    printf("Your guess is %i \n", guess);

    //Numero ou caracter invalido
    if(guess < 0){
        printf("Invalid Guess \n");
        //i--;

        continue;
    }
    

    //condicionais para caso o jogador acerte ou erre.
    int correct = guess == secretnumber;
    int Higher = guess < secretnumber;
    int Lower = guess > secretnumber;

    if(correct){
        printf("Nice! You did'it\n");
        printf("You did %d\n", points);
        //para de executar
        break;
    }
    else{
       if(Lower){
        points -= guess;
        printf("Lower than that\n");
        
       }
       if(Higher){
        points -= guess;
            printf("Higher than that\n");
        }
    }
    //try++; //toda vez que o codigo for executado, ele contara mais uma tentativa do jogador, ate que ele acerte
    }
    
return 0;
};