// including the libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // printing a nice game header
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Welcome to the   \n");
    printf("     |_|_|nnnn nnnn|_|_|         Guessing Game!   \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    // declaring variables that will be used later
    int guess;
    int correct;
    int level;
    int total_attempts;

    // defining the initial score
    double score = 1000;

    // generating a random secret number
    srand(time(0));
    int secret_number = rand() % 100;

    printf("%d", secret_number);

    // choosing the difficulty level
    printf("What is the difficulty level?\n");
    printf("(1) Easy (2) Medium (3) Hard\n\n");
    printf("Choose: ");

    scanf("%d", &level);

    switch(level) {
        case 1: 
            total_attempts = 20;
            break;
        case 2:
            total_attempts = 15;
            break;
        default:
            total_attempts = 6;
            break;
    }

    // main game loop
    for(int i = 1; i <= total_attempts; i++) {

        printf("-> Attempt %d of %d\n", i, total_attempts);

        printf("Guess a number: ");
        scanf("%d", &guess);

        // handling negative number guesses
        if(guess < 0) {
            printf("You can't guess negative numbers\n");
            i--;
            continue;
        }

        // checks if the guess is correct, higher, or lower
        correct = guess == secret_number;

        if(correct) {
            break;
        } else if(guess > secret_number) {
            printf("\nLower than that!\n\n");
        } else {
            printf("\nhigher than that!\n\n");
        }

        // calculates the score loss
        double points_lost = abs(guess - secret_number) / 2.0;
        score = score - points_lost;
    }

    // printing victory or defeat message
    printf("\n");
    if(correct) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nCongratulations! You got it right!\n");
        printf("You scored %.2f points. See you next time!\n\n", score);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nYou lost! Try again!\n\n");
    }
}
