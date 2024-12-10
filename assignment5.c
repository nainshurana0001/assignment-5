#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "hangman", guessedWord[] = "_______", guess;
    int chances = 3, correctGuess, i, won = 0;

    while (chances > 0 && !won) {
        printf("Word: %s\n", guessedWord);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        correctGuess = 0;

        for (i = 0; i < strlen(word); i++) {
            if (word[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) chances--;
        won = strcmp(word, guessedWord) == 0;
    }

    if (won)
        printf("Congratulations! You saved the man.\n");
    else
        printf("Game over! The man is hanged. Word was: %s\n", word);

    return 0;
}
