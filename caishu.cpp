#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void initialize_number_generator(void) {
	srand((unsigned)time(NULL));
}

int new_secret_number(void) {
	return  rand() % MAX_NUMBER + 1;
}

void read_guess(int secret_number) {
	int guess, num_guess = 0;

	for (;;)
	{
		num_guess++;
		printf("Enter guess: ");
		scanf_s("%d", &guess);
		if (guess==secret_number)
		{
			printf("You win in the %d number guesses!!\nThe number is %d.\n\n", num_guess, secret_number);
			return;
		}
		else if (guess < secret_number)
			printf("Tow low! Try again;\n");
		else
		{
			printf("Tow high! Try again;\n");
		}
	}
}

int main(void) {
	char command;
	int secret_number;

	printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
	initialize_number_generator();

	do{
		secret_number = new_secret_number();
		printf("A new number has been chosen.\n");
		read_guess(secret_number);
		printf("Play again?(Y or N) ");
		scanf_s(" %c", &command);
		printf("\n");
	} while (command=='y' || command=='Y');

	system("pause");
	return 0;
}